#include <iostream>
using namespace std;

class SpaceCraft
{
    int color;
    int speed;
public:
    void Fire() { cout << "Space Craft : ----------" << endl;}
};

int main()
{
    SpaceCraft sc;
    sc.Fire();
}
