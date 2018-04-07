#include <iostream>
using namespace std;

// CRTP : Curiously Recurring Template Pattern
template<typename TYPE> class Singleton
{
protected:
    Singleton() { }
    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;
public:
    static TYPE& getInstance()
    {
        static TYPE instance;
        return instance;
    }
};

class Mouse : public Singleton< Mouse >
{

};

int main()
{
    Mouse& c1 = Mouse::getInstance();

}










//
