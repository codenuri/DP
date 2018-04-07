#include <string>
#include <iostream>

class TextView
{
    std::string data;
    std::string font;
    int         width;
public:
    TextView( std::string s, std::string fo ="나눔고딕", int w=24 )
                : data(s), font(fo), width(w) {}

    void Show() { std::cout << data << std::endl;}
};

// TextView tv("hello");
// tv.Show();
