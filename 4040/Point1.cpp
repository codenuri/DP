#include <iostream>
#include "Point1.h"
using namespace std;

Point::Point( int a, int b) : x(a), y(b) {}

void Point::Print() const
{
    cout << x << ", " << y << endl;
}
