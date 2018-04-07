#include <iostream>
using namespace std;

struct IState
{
    virtual void run() = 0;
    virtual void attack() = 0;
    virtual ~IState() {}
};

class Character
{
    int gold = 0;
    int item = 0;
    IState* state;
public:
    void changeState(IState* p) { state = p;}
    void run()    { state->run(); }
    void attack() { state->attack(); }
};
class NormalState : public IState
{
    virtual void run()   { cout << "run" << endl;}
    virtual void attack(){ cout << "attack" << endl;}
};
class PowerItemState : public IState
{
    virtual void run()   { cout << "fast run" << endl;}
    virtual void attack(){ cout << "power attack" << endl;}
};
int main()
{
    NormalState ns;
    PowerItemState ps;

    Character* p = new Character;
    p->changeState(&ns);
    p->run();
    p->attack();
    
    p->changeState(&ps); // 아이템 획득.
    p->run();
    p->attack();
}







//
