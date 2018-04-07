#include <iostream>
using namespace std;

class SpaceCraft
{
    int color;
    int speed;
public:
    void Fire() { cout << "Space Craft : ----------" << endl;}
};

// 구성(Composition) 통한 기능의 추가.
class LeftMissile
{
    SpaceCraft* craft;
public:
    LeftMissile( SpaceCraft* p) : craft(p) {}

    void Fire()
    {
        craft->Fire(); // 기존 기능 수행.
        cout << "Left Missile : >>>>>>>>" << endl;
    }
};

int main()
{
    SpaceCraft sc;
    sc.Fire();

    LeftMissile lm(&sc);
    lm.Fire();
}







//
