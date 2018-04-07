#include <iostream>
using namespace std;

class Character
{
    int gold = 0;
    int item = 0;
public:
    void run()    { cout << "run"    << endl; }
    void attack() { cout << "attack" << endl; }
};

int main()
{
    Character* p = new Character;
    p->run();
    p->attack();
}
