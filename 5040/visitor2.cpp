#include <iostream>
#include <list>
using namespace std;

// 방문자(visitor)의 인터페이스
template<typename T> struct IVisitor
{
    virtual void visit(T& elem) = 0;
    virtual ~IVisitor() {}
};

template<typename T> class TwiceVisitor : public IVisitor<T>
{
public:
    virtual void visit(T& elem) { elem = elem * 2;}
};

template<typename T> class ShowVisitor : public IVisitor<T>
{
public:
    virtual void visit(T& elem) { cout << elem << endl;}
};
//------------------------
// 방문의 대상의 인터페이스
template<typename T> struct IAcceptor
{
    virtual void accept( IVisitor<T>* p) = 0;
    virtual ~IAcceptor()  {}
};

template<typename T> class List : public list<T>, public IAcceptor<T>
{
public:
    using list<T>::list; // c++11 생성자 상속
    virtual void accept( IVisitor<T>* p)
    {
        // 모든 요소를 방문자에게 전달.
        for( auto& e : *this)
            p->visit(e);
    }
};

template<typename T> class TripleVisitor : public IVisitor<T>
{
public:
    virtual void visit(T& elem) { elem = elem * 3;}
};

int main()
{
    List<int> s = { 1,2,3,4,5,6,7,8,9,10};

    TwiceVisitor<int> tv;
    s.accept(&tv);

    TripleVisitor<int> trv;
    s.accept(&trv);

    ShowVisitor<int> sv;
    s.accept(&sv);


    //s.triple_all_element();
}













//
