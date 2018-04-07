#include <iostream>
using namespace std;

template<typename T> struct Node
{
    T   data;
    Node* next;
    Node( const T& d, Node* n) : data(d), next(n) {}
};

template<typename T> struct IEnumerator
{
    virtual ~IEnumerator() {}
    virtual bool MoveNext() = 0;
    virtual T&  GetObject() = 0;
};


template<typename T> class SlistEnumerator : public IEnumerator<T>
{
    Node<T>* current = 0;
public:
    SlistEnumerator( Node<T>* p = 0) : current(p) {}

    virtual bool MoveNext()
    {
         current = current->next;
         return current;
    }
    virtual T&  GetObject() { return current->data; }
};

template<typename T> struct IEnumerable
{
    virtual ~IEnumerable() {}
    virtual IEnumerator<T>* GetEnumerator()  = 0;
};


template<typename T> class slist : public IEnumerable<T>
{
    Node<T>* head = 0;
public:
    virtual IEnumerator<T>* GetEnumerator()
    {
        return new SlistEnumerator<T>( head);
    }

    void push_front(const T& n) { head = new Node<T>(n, head);}
    T  front()                  { return head->data;}
};


template<typename T> void Show( IEnumerator<T>* p )
{
    do
    {
        cout << p->GetObject() << endl;
    } while( p->MoveNext() );
}

int main()
{
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    int* p1 = x;
    Show( p1);

    slist<int> s;

    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);

    IEnumerator<int>* p = s.GetEnumerator();

    Show( p );
    delete p;
}









//
