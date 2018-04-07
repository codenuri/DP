#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;

// stack 을 만들어 봅시다.
// list의 함수이름을 stack 처럼 보이도록 변경
/*
template<typename T> class Stack : private list<T>
{
public:
    void push(const T& a) { list<T>::push_back(a);}
    void pop()            { list<T>::pop_back();}
    T&   top()            { return list<T>::back();}
};
*/
/*
template<typename T, typename C = deque<T> > class Stack
{
    C st;
public:
    inline void push(const T& a) { st.push_back(a);}
    void pop()            { st.pop_back();}
    T&   top()            { return st.back();}
};
*/
#include <stack>

int main()
{
    //Stack<int, list<int> > s;
    //Stack<int, vector<int> > s;
    stack<int> s;
    s.push(10);
    s.push(20);

//    s.push_front(20);

    cout << s.top() << endl; // 20
}









//
