// Point2.h

//#include "PointImpl.h"
class PointImpl; // forward declaration.. 핵심..

class Point
{
    PointImpl* pImpl;
public:
    Point(int a = 0, int b = 0);

    void Print() const;
};
