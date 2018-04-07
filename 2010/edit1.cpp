#include <iostream>
#include <string>
#include <conio.h>  // getch()
using namespace std;

class Edit
{
    string data;
public:
    string getData()
    {
        data.clear();

        while( 1 )
        {
            char c = getch();

            if ( c == 13 ) break;

            if ( isdigit(c) )
            {
                data.push_back(c);
                cout << c;
            }
        }
        cout << endl;
        return data;
    }
};


int main()
{
    Edit edit;

    while(1)
    {
        string s = edit.getData();
        cout << s << endl;
    }
}








































//
