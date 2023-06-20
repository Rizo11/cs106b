#include "ApollonianGaskets.h"
#include "GUI/MiniGUI.h"
#include "GVector.h"
#include "gslider.h"
#include "glabel.h"
#include <sstream>
#include <iomanip>
using namespace std;
using namespace MiniGUI;

namespace {
    bool approximatelyEqual(double one, double two) {
        return fabs(one - two) <= 1e-6;
    }
}

bool operator== (const Circle& lhs, const Circle& rhs) {
    return approximatelyEqual(lhs.center.x, rhs.center.x) &&
           approximatelyEqual(lhs.center.y, rhs.center.y) &&
           approximatelyEqual(lhs.radius,   rhs.radius);
}

bool operator!= (const Circle& lhs, const Circle& rhs) {
    return !(lhs == rhs);
}

ostream& operator<< (ostream& out, const Circle& c) {
    ostringstream builder;
    builder << "{ " << c.center << ", " << c.radius << " }";
    return out << builder.str();
}

namespace {
    /* Intersection point of two circles. It's assumed the circles are sufficiently separated
     * that there are two intersection points.
     */
    pair<GPoint, GPoint> intersectionOf(const Circle& c1, const Circle& c2) {
        /* Math is derived by drawing a line between the circle centers, dropping a perpendicular
         * from the intersection points to that line, and working out the relevant distances.
         */

        /* Distance between circle centers. */
        auto distance = magnitudeOf(c2.center - c1.center);

        /* Distance along the line from c1's center to c2's center where the perpendicular
         * line hits.
         */
        auto radialLength = (distance * distance + c1.radius * c1.radius - c2.radius * c2.radius) / (2 * distance);

        /* Distance along the perpendicular to the intersection points. */
        auto tangentLength = sqrt(c1.radius * c1.radius - radialLength * radialLength);
        if (isnan(tangentLength)) {
            error("NaN detected.");
        }

        /* Point where the perpendicular line hits. */
        auto branchPoint = c1.center + (c2.center - c1.center) * (radialLength / distance);

        /* Unit vector perpendicular to the line from c1 to c2. */
        auto tangent = GVector{
            c1.center.y - c2.center.y,
            c2.center.x - c1.center.x
        } / distance;

        /* Move from the branch point to the two intersection points. */
        return make_pair(branchPoint + tangent * tangentLength,
                         branchPoint - tangent * tangentLength);
    }

    /* Given a circle, returns the circle formed by adding the given amount to its radius. */
    Circle expand(Circle c, double dRadius) {
        return { c.center, c.radius + dRadius };
    }

    /* Given two circles, returns a circle tangent to both of them that has the given
     * radius. (There can be many different ways to do this; we pick one arbitrarily.
     */
    Circle tangentOf(const Circle& c1, const Circle& c2, double radius) {
        /* The center of the new circle can be found by inflating each circle's radius
         * by the new radius amount and finding their intersection point.
         */

        return { intersectionOf(expand(c1, radius), expand(c2, radius)).first, radius };
    }

    /* Given three circles, returns the point where those three circles intersect. */
    GPoint intersectionOf(const Circle& c1, const Circle& c2, const Circle& c3) {
        /* We could solve this analytically, but where's the fun in that? Instead, let's
         * just find the two intersection points of c1 and c2, then pick whichever one
         * is closer to having the right distance to c3.
         */
        auto points = intersectionOf(c1, c2);

        /* Compute the error between the actual distance and expected distance. */
        double error1 = fabs(magnitudeOf(c3.center - points.first)  - fabs(c3.radius));
        double error2 = fabs(magnitudeOf(c3.center - points.second) - fabs(c3.radius));

        return error1 < error2? points.first : points.second;
    }

    /* Given three circles and the bend of one of their Soddy circles, returns that
     * Soddy circle.
     */
    Circle soddyCircleOfBend(const Circle& c1, const Circle& c2, const Circle& c3, double bend) {
        /* Find the intersection point of the three circles formed by expanding the radius out by
         * the appropriate amount.
         */
        return { intersectionOf(expand(c1, 1/bend), expand(c2, 1/bend), expand(c3, 1/bend)), 1 / bend };
    }

    /* Given three mutually tangent circles, returns the two circles that are mututally
     * tangent to all three.
     */
    pair<Circle, Circle> soddyCirclesFor(const Circle& c1, const Circle& c2, const Circle& c3) {
        /* First, compute the bends of the new circles. The new bends are solutions to
         *
         * 2(b1^2 + b2^2 + b3^3 + b^2) = (b1 + b2 + b3 + b)^2.
         *
         * To solve this, let's have X = b1^2 + b2^2 + b3^2 and Y = b1 + b2 + b3. Then we want
         * to solve
         *
         * 2(b^2 + X) = (b + Y)^2
         *
         * or, equivalently:
         *
         * 2b^2 + 2X = b^2 + 2bY + Y^2
         *  b^2 - 2bY + 2X - Y^2 = 0
         *
         * That's a quadratic, so we can work out the roots as
         *
         *       2Y (+-) sqrt(4Y^2 - 8X + 4Y^2)
         *   b = ------------------------------
         *                     2
         *
         * So
         *
         *       2Y (+-) sqrt(8Y^2 - 8X)
         *   b = -----------------------
         *                   2
         *
         * So
         *
         * b = Y (+-) sqrt(2Y^2 - 2X)
         */
        double X = 1 / (c1.radius * c1.radius) + 1 / (c2.radius * c2.radius) + 1 / (c3.radius * c3.radius);
        double Y = 1 / c1.radius + 1 / c2.radius + 1 / c3.radius;

        /* The two bends. */
        double b1 = Y - sqrt(2 * Y * Y - 2 * X);
        double b2 = Y + sqrt(2 * Y * Y - 2 * X);

        /* For each bend, find the center point associated with it. */
        return make_pair(soddyCircleOfBend(c1, c2, c3, b1),
                         soddyCircleOfBend(c1, c2, c3, b2));
    }

    void drawCircle(GWindow& window, const Circle& c, const char* color = "black") {
        window.setColor(color);
        window.drawOval({
                            c.center.x - fabs(c.radius), c.center.y - fabs(c.radius),
                            2 * fabs(c.radius), 2 * fabs(c.radius)
                        });
    }

    void fillCircle(GWindow& window, const Circle& c, const char* color) {
        window.setColor(color);
        window.fillOval({
                            c.center.x - fabs(c.radius), c.center.y - fabs(c.radius),
                            2 * fabs(c.radius), 2 * fabs(c.radius)
                        });
    }
}

/* Implementation of drawing function logic. */
namespace {
    function<void (const Circle&)> theDrawFn;
}

void GasketInternal::setDrawFunction(function<void (const Circle&)> drawFn) {
    theDrawFn = drawFn;
}

void drawCircle(const Circle& circle) {
    if (!theDrawFn) {
        error("No draw function specified. This can happen if you try calling drawApollonianGasket from a test case.");
    }
    theDrawFn(circle);
}

namespace {
    const int kMinRadius = 1;
    const int kMaxRadius = 300;
    const int kDefaultRadius = 150;
    const double kMinEnclosingRadius = -1000;

    const MiniGUI::Font kErrorFont(FontFamily::SANS_SERIF, FontStyle::ITALIC, 24, "#800000");

    class GasketGUI: public ProblemHandler {
    public:
        GasketGUI(GWindow& window);
        ~GasketGUI();

        void changeOccurredIn(GObservable*) override;

     protected:
        void repaint() override;

    private:
        Temporary<GLabel>  r1Label, r2Label, r3Label;
        Temporary<GSlider> r1Slider, r2Slider, r3Slider;

        void displayParameterError();
    };

    GasketGUI::GasketGUI(GWindow& window) : ProblemHandler(window) {
        /* Set up interactors. */
        r1Label  = make_temporary<GLabel> (window, "SOUTH", "Blue Circle Radius: ");
        r1Slider = make_temporary<GSlider>(window, "SOUTH", kMinRadius, kMaxRadius, kDefaultRadius);
        r2Label  = make_temporary<GLabel> (window, "SOUTH", "Green Circle Radius: ");
        r2Slider = make_temporary<GSlider>(window, "SOUTH", kMinRadius, kMaxRadius, kDefaultRadius);
        r3Label  = make_temporary<GLabel> (window, "SOUTH", "Red Circle Radius: ");
        r3Slider = make_temporary<GSlider>(window, "SOUTH", kMinRadius, kMaxRadius, kDefaultRadius);

        /* Ensure circles get drawn onto the canvas. */
        GasketInternal::setDrawFunction([&] (const Circle& circle) {
            drawCircle(window, circle);
        });
    }

    /* On shutdown, disable the draw function. */
    GasketGUI::~GasketGUI() {
        GasketInternal::setDrawFunction(nullptr);
    }

    void GasketGUI::changeOccurredIn(GObservable*) {
        requestRepaint();
    }

    void GasketGUI::repaint() {
        clearDisplay(window(), "white");

        double r1 = r1Slider->getValue();
        double r2 = r2Slider->getValue();
        double r3 = r3Slider->getValue();

        Circle c1 { { 0, 0 }, r1 };
        Circle c2 { { 0, r1 + r2 }, r2 };
        Circle c3 = tangentOf(c2, c1, r3);

        /* Find the tangents and take the negative-bend one. */
        auto tangents = soddyCirclesFor(c1, c2, c3);
        if ((tangents.first.radius <= kMinEnclosingRadius || tangents.second.radius <= kMinEnclosingRadius) ||
            (tangents.first.radius >= 0    && tangents.second.radius >= 0)) {
            displayParameterError();
            return;
        }

        /* Pick the one with the smaller radius - that's the negative one. */
        auto c4 = tangents.first.radius < tangents.second.radius? tangents.first : tangents.second;

        /* Center everything. */
        GPoint center = { window().getCanvasWidth() / 2, window().getCanvasHeight() / 2 };
        auto delta = center - c4.center;
        c1.center += delta;
        c2.center += delta;
        c3.center += delta;
        c4.center += delta;

        fillCircle(window(), c1, "#ccccff");
        fillCircle(window(), c2, "#ccffcc");
        fillCircle(window(), c3, "#ffcccc");
        drawApollonianGasket(c1, c2, c3, c4);
    }

    void GasketGUI::displayParameterError() {
        auto render = TextRender::construct("(Parameters out of range)", {
                                                0, 0, window().getCanvasWidth(), window().getCanvasHeight()
                                            }, kErrorFont);
        render->alignCenterHorizontally();
        render->alignCenterVertically();
        render->draw(window());
    }
}


GRAPHICS_HANDLER("Apollonian Gaskets", GWindow& window) {
    return make_shared<GasketGUI>(window);
}
