#include <iostream>
#include <string>
#include <thread>
using namespace std;

class Image
{
public:
    Image(string imageName)
    {
        //this_thread::sleep(1000s);
    }
};

class ImageProxy
{
    Image* pImage;
public:
    ImageProxy(string imageName)
    {
        cout << "Load..." << endl;
        pImage = new Image;
    }
};

int main()
{
    ImageProxy* p = new ImageProxy("aaa.com\\a.png");
}
