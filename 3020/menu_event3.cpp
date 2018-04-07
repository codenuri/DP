#include "menu.hpp"


class MenuItem : public BaseMenu
{
    int id;

    void (Dialog::*handler)();
    Dialog* target;

public:
    void setHandler( void(*f)() ) { handler = f;}

    MenuItem(string s, int n) : BaseMenu(s),  id(n) {}

    virtual void command()
    {
        handler();
    }
};







class Dialog : public IMenuListener
{
public:
    virtual void doCommand(int id)
    {
        //cout << "Dialog doCommand" << endl;
        switch( id )
        {
        case 11: cout << "11" << endl; break;
        case 12: cout << "12" << endl; break;
        }
    }
};

int main()
{
    Dialog dlg;
    MenuItem m1( "Add Student " , 11);
    MenuItem m2( "Remove Student " , 12);

    m1.setListener(&dlg);
    m2.setListener(&dlg);


    m1.command();
    m2.command();
}














//
