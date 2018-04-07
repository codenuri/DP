#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Edit
{
    string data;
public:

    virtual bool validate(char c)
    {
        return isdigit(c);
    }

    string getData()
    {
        data.clear();

        while( 1 )
        {
            char c = getch();

            if ( c == 13 ) break;

            if ( validate(c) )
            {
                data.push_back(c);
                cout << c;
            }
        }
        cout << endl;
        return data;
    }
};
//--------------------
class AddressEdit : public Edit
{
public:
    virtual bool validate(char c)
    {
        return true;
    }
};

int main()
{
    AddressEdit edit;

    while(1)
    {
        string s = edit.getData();
        cout << s << endl;
    }
}








































//
