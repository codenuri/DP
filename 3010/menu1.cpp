#include <iostream>
#include <string>
#include <vector>
using namespace std;


class BaseMenu
{
    string title;
public:
    BaseMenu( string s) : title(s) {}

    string getTitle() const { return title;}

    virtual void command() = 0; // !!
};

class MenuItem : public BaseMenu
{
    int id;
public:
    MenuItem(string s, int n) : BaseMenu(s),  id(n) {}

    virtual void command()
    {
        cout << getTitle() << endl;
        getchar();
    }
};

int main()
{
    MenuItem m("sound", 11); // ok..

}




//









//
