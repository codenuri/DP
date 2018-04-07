// PointImpl.cpp
#include <iostream>
#include "PointImpl.h"
using namespace std;

PointImpl::PointImpl( int a, int b) : x(a), y(b) {}

void PointImpl::Print() const
{
    cout << x << ", " << y << endl;
}
