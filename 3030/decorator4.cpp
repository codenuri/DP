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

class LeftMissile : public Component
{
    Component* craft;
public:
    LeftMissile( Component* p) : craft(p) {}

    void Fire()
    {
        craft->Fire();
        cout << "Left Missile : >>>>>>>>" << endl;
    }
};

class RightMissile : public Component
{
    Component* craft;
public:
    RightMissile( Component* p) : craft(p) {}

    void Fire()
    {
        craft->Fire();
        cout << "Right Missile : >>>>>>>>" << endl;
    }
};

int main()
{
    SpaceCraft sc;
//    sc.Fire();

    LeftMissile lm(&sc);
//    lm.Fire();

    //RightMissile rm(&sc);
    RightMissile rm(&lm); // 기능추가된 객체에 다시 기능 추가
    rm.Fire();

}







//
