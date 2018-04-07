#include <iostream>
using namespace std;


template<typename T, typename ThreadModel = NoLock> class List
{
    ThreadModel tm; // 동기화 정책을 담은 클래스
public:
    void push_front(const T& a)
    {
        tm.Lock();
        //...
        tm.Unlock();
    }
};

class MutexLock
{
    // mutex m;
public:
    inline void Lock()   { cout << "mutex lock" << endl;}
    inline void Unlock() { cout << "mutex Unlock" << endl;}
};
class NoLock
{
public:
    inline void Lock()   {}
    inline void Unlock() {}
};
//List<int, NoLock> s;
List<int, MutexLock> s;

int main()
{

    s.push_front(10);

}
