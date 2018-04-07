#include <iostream>
using namespace std;

template<typename T> class List
{
public:
    void push_front(const T& a)
    {
    //    Lock();
        //...
    //    Unlock();
    }
};

List<int> s; // 멀티 스레드에 안전하지 않다.

int main()
{

    s.push_front(10);

}
