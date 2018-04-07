#include <iostream>
#include <string>
using namespace std;

// 입학 지원서
using Application = string; // class Application {}


// 지원서의 각 단계의 표현을 만드는 빌더 인터페이스
struct IBuilder
{
    virtual ~IBuilder() {}
    virtual void makeName(string name) =  0;
    virtual void makePhone(string phone) =  0;
    virtual void makeAddress(string addr) =  0;

    virtual Application getResult() = 0;
};

// 지원서 만드는 클래스
class Director
{
    string name = "HONG";
    string phone = "010-111-1111";
    string address = "SEOUL KANGNAMGU";
    IBuilder* pBuilder;
public:
    void setBuilder( IBuilder* p ) { pBuilder = p;}

    Application construct()
    {
        pBuilder->makeName(name);
        pBuilder->makePhone(phone);
    //    pBuilder->makeAddress(address);

        return pBuilder->getResult();
    }
};

class XMLBuilder : public IBuilder
{
    Application app;
public:
    virtual void makeName(string name)
    {
        app += "<NAME>" + name + "</NAME>\n";
    }
    virtual void makePhone(string phone)
    {
        app += "<PHONE>" + phone + "</PHONE>\n";
    }
    virtual void makeAddress(string addr)
    {
        app += "<ADDRESS>" + addr + "</ADDRESS>\n";
    }

    virtual Application getResult() { return app;}
};

class TextBuilder : public IBuilder
{
    Application app;
public:
    virtual void makeName(string name)
    {
        app += name + "\n";
    }
    virtual void makePhone(string phone)
    {
        app += phone + "\n";
    }
    virtual void makeAddress(string addr)
    {
        app +=  addr + "\n";
    }

    virtual Application getResult() { return app;}
};

int main()
{
    Director d;
    XMLBuilder xb;
    d.setBuilder(&xb);

    Application app = d.construct();
    cout << app << endl;

    TextBuilder tb;
    d.setBuilder(&tb);
    app = d.construct();
    cout << app << endl;
}






//
