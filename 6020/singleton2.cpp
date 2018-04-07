#include <iostream>
using namespace std;

/*
class Cursor
{
    int x, y;

private:
    Cursor() { cout << "Cursor()" << endl; }
    Cursor(const Cursor&) = delete;
    void operator=(const Cursor&) = delete;

    static Cursor instance;
public:
    static Cursor& getInstance()
    {
        return instance;
    }
};
Cursor Cursor::instance;
*/
/*
class Cursor
{
    int x, y;

private:
    Cursor() { cout << "Cursor()" << endl; }
    Cursor(const Cursor&) = delete;
    void operator=(const Cursor&) = delete;

public:
    // lazy intialization
    static Cursor& getInstance()
    {
        static Cursor instance;
        return instance;
    }
};
*/

class Cursor
{
    int x, y;

private:
    Cursor() { cout << "Cursor()" << endl; }
    Cursor(const Cursor&) = delete;
    void operator=(const Cursor&) = delete;

    static Cursor* pInstance;
public:
    static Cursor& getInstance()
    {
        if ( pInstance == 0 )
            pInstance = new Cursor;
        return *pInstance;
    }
};
Cursor* Cursor::pInstance = 0;

int main()
{
    Cursor& c1 = Cursor::getInstance();

}










//
