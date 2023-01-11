/* All Examples from Introduction to C++ Lecture
 * Note: this project will compile with warnings about
 * unused variables.
 */

// slide 5: #include statements
#include <iostream>
#include <cmath>
// #include "console.h"
#include "all-examples.h"

using namespace std;

int main() {
    // slide 4: comments
    // Two forward slashes comment out the rest of the line
    int myVar = 5; // everything past the double-slash is a comment

    /* This is a multiline
    comment, and I end it with an asterisk-slash
    */

    // slide 6: typed variables
    int a = 5; // a is an integer
    char b = 'x'; // b is a char ("character")
    float c = 1.42; // c is a floating point number
    double d = 1.4245593330222211176; // d is a double, a more accurate floating point number
    string s = "this is a C++ string";
    // float a = 4.2; // ERROR! You cannot redefine a variable to be another type
    // int a = 12; // ERROR! You do not need the type when re-assigning a variable
    a = 12; // this is okay

    // slide 7: standard output
    int num = 42;
    string theAnswer = "The answer to life, the universe, and everything";
    cout << theAnswer << " is " << num << "." << endl;

    cout << "This is some text followed by endl." << endl;
    cout << "This is more text.";
    cout << "We want to go to the next line here, too" << endl;
    cout << "We made it to the next line." << endl;

    // slide 8: while loops
    int i = 0;
    while (i < 5) {
      cout << i << endl;
      i++;
    }

    // slide 9: for loops
    for (int i = 0; i < 3; i++) {
      cout << i << endl;
    }

    // same as above, with a while loop:
    int j = 0;
    while (j < 3) {
      cout << j << endl;
      j++;
    }

    // slide 10: scoping
    int outsideVar = 5;
    for (int loopVar = 0; loopVar < 3; loopVar++) {
      int insideVar = 10 * outsideVar;
      cout << outsideVar << ", " << insideVar << endl;
      outsideVar += 2;
    }

    cout << outsideVar << endl; // okay
    // cout << insideVar << endl; // error! insideVar not in scope
    // cout << loopVar << endl; // error! loopVar not in scope

    // slide 11: boolean expressions
    int firstNum = 1;
    string compareText;

    for (int secondNum = 0; secondNum < 3; secondNum++) {
        if (firstNum < secondNum) {
            compareText = "less than";
        } else if (firstNum > secondNum) {
            compareText = "greater than";
        } else {
            compareText = "equal to";
        }
        cout << "firstNum is " << firstNum << ", secondNum is " << secondNum << endl;
        cout << "firstNum is " << compareText << " secondNum" << endl << endl;
    }

    int x = 5;
    int y = 7;

    if (x == 5 && y == 7) {
        cout << "x equals 5 and y equals 7" << endl;
    }

    if (x == 5 || y == 5) { // note: cannot combine as if (x || y == 5)
        cout << "x equals 5 or y equals 5" << endl;
    }

    if (x != 5 && y != 5) {
        cout << "x is not equal to 5 and y is not equal to 5" << endl;
    } else if (x != 5 || y != 5) {
        cout << "x is not equal to 5 or y is not equal to 5" << endl;
    }

    if (!(x == 5 && y == 5)) {
        cout << "not (x is equal to 5 and y is equal to 5) (DeMorgan's Law)" << endl;
    }

    // slide 12: functions
    double fpNum = 1234; // a floating point number
    double result = sqrt(fpNum); // set result to be equal to the return value of the sqrt function

    cout << "fpNum: " << fpNum << endl;
    cout << "square root of fpNum: " << result << endl;

    int fact5 = factorial(5);
    cout << "The factorial of 5 is " << fact5 << endl;

    printTenTimes('A');

    // uncomment the following to see compile error
    // int someResult = printTenTimes('c');

    // slide 13: passing by reference
    int myValue = 5;
    int doubleResult = doubleValue(myValue);

    cout << myValue << endl;
    cout << doubleResult << endl;

    doubleValueWithRef(myValue);
    cout << myValue << endl;

    // uncomment the next line to see compile error
    // doubleValueWithRef(15);

    // slide 14, using header files
    cout << square(15) << endl;
    if (even(42)) {
        cout << "even" << endl;
    } else {
        cout << "odd" << endl;
    }

    return 0; // the return value for main must be an integer.
              // In main(), a return value of 0 means "everything worked out"
}

// functions that main uses:

int factorial(int number) {
    int result = 1;
    for (int n = number; n > 1; n--) {
        result *= n;
    }
    return result;
}

void printTenTimes(char c) {
    for (int i = 0; i < 10; i++) {
        cout << c;
    }
    cout << endl;
}

int doubleValue(int x) {
    x *= 2;
    return x;
}

void doubleValueWithRef(int &x) {
    x *= 2;
}

int square(int x) {
    return x * x;
}

bool even(int v) {
    return v % 2 == 0;
}
