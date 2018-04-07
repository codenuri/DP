#include <iostream>
using namespace std;

class Cursor
{
    int x, y;

private:
    Cursor() { }
    Cursor(const Cursor&) = delete;
    void operator=(const Cursor&) = delete;

public:
    static Cursor& getInstance()
    {
        static Cursor instance;
        return instance;
    }
};

int main()
{
    //Cursor c1, c2;
    Cursor& c1 = Cursor::getInstance();
    Cursor& c2 = Cursor::getInstance();
    cout << &c1 << endl;
    cout << &c2 << endl;

    //Cursor c3 = c1;
}










//
