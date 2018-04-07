#include <iostream>
using namespace std;

class SpaceCraft
{
    int color;
    int speed;
public:
    void Fire() { cout << "Space Craft : ----------" << endl;}
};

// 상속을 통한 기능의 추가.
class LeftMissile : public SpaceCraft
{
public:
    void Fire()
    {
        SpaceCraft::Fire(); // 기존 기능 수행.
        cout << "Left Missile : >>>>>>>>" << endl;
    }
};

int main()
{
    SpaceCraft sc;
    sc.Fire();

    LeftMissile lm;
    lm.Fire();
}







//
