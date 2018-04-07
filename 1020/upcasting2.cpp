#include <iostream>
using namespace std;

class Animal
{
    int age;
public:
    virtual void Cry() { cout << "Animal Cry" << endl;}
};

class Dog : public Animal
{
    int color;
public:
    // override
    virtual void Cry()  { cout << "Dog Cry" << endl;}
};

int main()
{
    Dog d;
    Animal* p = &d;

    p->Cry();
}







































//
