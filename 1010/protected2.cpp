#include <iostream>
using namespace std;

class Car
{
public:
    Car() {}

    void Destroy() { delete this;}
protected:
    ~Car(){ cout << "~Car" << endl;}
};

int main()
{
    //Car c; // 스택에 객체를 만들수 없다.

    Car* p = new Car;
    p->Destroy();

    //delete p;
}
