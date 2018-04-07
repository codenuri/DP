#include <iostream>
using namespace std;

struct ISync
{
    virtual void Lock() = 0;
    virtual void UnLock() = 0;
    virtual ~ISync() {}
};

template<typename T> class List
{
    ISync* pSync = 0;
public:
    void setSync(ISync* p) { pSync = p;}

    void push_front(const T& a)
    {
        if ( pSync != 0 ) pSync->Lock();
        //...
        if ( pSync != 0 ) pSync->UnLock();
    }
};

class MutexLock : public ISync
{
    // mutex m;
public:
    virtual void Lock()  {}
    virtual void UnLock() {}
};

List<int> s;

int main()
{
    MutexLock m;
    s.setSync(&m);

    s.push_front(10);


    NoLock m2;
    s.setSync(&m2);

}
