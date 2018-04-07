#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    list<int> s = { 1,2,3,4};

    auto p1 = s.begin();
    auto p2 = s.end();

    //reverse_iterator< list<int>::iterator > p3(p2); // --p2 로 초기화
    reverse_iterator< list<int>::iterator > p4(p1); // --p1 로 초기화

    auto p3 = make_reverse_iterator(p2);

    //cout << *p3 << endl; // 4
    //++p3;   // --
    //cout << *p3 << endl; // 3

    //for_each( p1, p2, [](int a) { cout << a << endl;});
    for_each( p3, p4, [](int a) { cout << a << endl;});


}















//
