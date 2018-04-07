#include "menu.hpp"

class MenuItem : public BaseMenu
{
    int id;
public:
    MenuItem(string s, int n) : BaseMenu(s),  id(n) {}

    virtual void command()
    {
        // 변해야 하는 것을 가상함수로.
        doCommand();
    }
    virtual void doCommand() {}
};

class AddStudentMenu : public MenuItem
{
public:
    using MenuItem::MenuItem; // 생성자 상속..

    virtual void doCommand() { cout << "Add Student" << endl; }
};

class RemoveStudentMenu : public MenuItem
{
public:
    using MenuItem::MenuItem;
    virtual void doCommand() { cout << "Remove Student" << endl; }
};

int main()
{
    AddStudentMenu    m1( "Add Student " , 11);
    RemoveStudentMenu m2( "Remove Student " , 12);

    m1.command();
    m2.command();
}














//
