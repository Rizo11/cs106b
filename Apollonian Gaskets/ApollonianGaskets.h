#pragma once

#include "gtypes.h"
#include <ostream>

/* Type representing a circle. */
struct Circle {
    GPoint center;  // Location of the circle center.
    double radius;  // Radius; negative if this circle encloses the three others
};

/* Check if two circles are equal or unequal. */
bool operator== (const Circle& lhs, const Circle& rhs);
bool operator!= (const Circle& lhs, const Circle& rhs);

/* Allows you to print a Circle to cout for debugging purposes. */
std::ostream& operator<< (std::ostream& out, const Circle& c);

/* Draws a circle on the screen. (We provide this to you; you don't need to write it. */
void drawCircle(const Circle& circle);

/* Draws an Apollonian gasket given a collection of four mutually tangent circles. */
void drawApollonianGasket(const Circle& c1,
                          const Circle& c2,
                          const Circle& c3,
                          const Circle& c4);

/* * * * * Everything below this point is purely for testing purposes. * * * * */

#include <functional>

namespace GasketInternal {
    void setDrawFunction(std::function<void(const Circle&)>);
}
