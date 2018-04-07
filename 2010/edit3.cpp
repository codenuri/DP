#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


// validation 을 위한 인터페이스
struct IValidator
{
    virtual bool validate(string s, char c) = 0;
    virtual bool iscomplete(string s)  { return true;}

    virtual ~IValidator() {}
};

// 주민 번호 : 801    1   확인.



class Edit
{
    string data;
    //---------------------
    IValidator* pVal = 0;
public:
    void setValidator(IValidator* p ) { pVal = p;}
    //---------------------------

    string getData()
    {
        data.clear();

        while( 1 )
        {
            char c = getch();

            if ( c == 13 &&
                ( pVal == 0 || pVal->iscomplete(data)  ) ) break;

            if ( pVal == 0 || pVal->validate(data, c) )
            {
                data.push_back(c);
                cout << c;
            }
        }
        cout << endl;
        return data;
    }
};

class LimitDigitValidator : public IValidator
{
    int value;
public:
    LimitDigitValidator(int n) : value(n) {}

    virtual bool validate( string s, char c )
    {
        return s.size() < value && isdigit(c);
    }

    virtual bool iscomplete( string s)
    {
        return s.size() == value;
    }
};


int main()
{
    Edit edit;
    LimitDigitValidator v(5);
    edit.setValidator(&v);

    while(1)
    {
        string s = edit.getData();
        cout << s << endl;
    }
}








































//
