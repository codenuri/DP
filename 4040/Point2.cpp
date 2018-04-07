// Point2.cpp
#include "PointImpl.h"
#include "Point2.h"

Point::Point(int a, int b)
{
    pImpl = new PointImpl(a, b);
}

void Point::Print() const
{
    pImpl->Print();
}
