#include <iostream>
using namespace std;

// 우주선과 기능추가객체의 공통의 기반 클래스
struct Component
{
    virtual void Fire() = 0;
    virtual ~Component() {}
};


class SpaceCraft : public Component
{
    int color;
    int speed;
public:
    void Fire() { cout << "Space Craft : ----------" << endl;}
};

//---------------
// 기능 추가 클래스의 공통의 기반 클래스
class IDecorator : public Component
{
    Component* craft;
public:
    IDecorator( Component* p) : craft(p) {}

    void Fire() { craft->Fire();}
};


class LeftMissile : public IDecorator
{
public:
    LeftMissile( Component* p) : IDecorator(p) {}

    void Fire()
    {
        IDecorator::Fire();
        cout << "Left Missile : >>>>>>>>" << endl;
    }
};

class RightMissile : public IDecorator
{
public:
    RightMissile( Component* p) : IDecorator(p) {}

    void Fire()
    {
        IDecorator::Fire();
        cout << "Rigth Missile : >>>>>>>>" << endl;
    }
};


int main()
{
    SpaceCraft sc;

    LeftMissile  lm(&sc);
    RightMissile rm(&lm);

    rm.Fire();
}







//
