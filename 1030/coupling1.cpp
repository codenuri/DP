#include <iostream>
using namespace std;

class Camera
{
public:
    void take() { cout << "take picture" << endl;}
};

class HDCamera
{
public:
    void take() { cout << "take HD picture" << endl;}
};

class People
{
public:
    void useCamera(Camera* p) { p->take(); }
    void useCamera(HDCamera* p) { p->take(); }
};

int main()
{
    People p;
    Camera c;
    p.useCamera(&c);

    HDCamera hc;
    p.useCamera(&hc);
}




















//
