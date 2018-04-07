#include <iostream>
#include <mutex>
using namespace std;

class Cursor
{
private:
    Cursor() { }
    Cursor(const Cursor&) = delete;
    void operator=(const Cursor&) = delete;

    static mutex   m;
    static Cursor* pInstance;
public:


    static Cursor& getInstance()
    {
        // 단점 : 최초 생성시 if 를 2번 실행
        // 장점 : 최초 이외에는 Lock 을 수행하지 않는다.
        if ( pInstance == 0 )
        {
            m.lock();
            if ( pInstance == 0 )
                pInstance = new Cursor;
            m.unlock();
        }

        return *pInstance;
    }





};
Cursor* Cursor::pInstance = 0;
mutex   Cursor::m;


int main()
{
    Cursor& c1 = Cursor::getInstance();
}










//
