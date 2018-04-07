// ICalc.h

// 참조계수를 책임지는 함수는 인터페이스에 있어야 한다.

struct IRefCount            // IUnknown
{
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual ~IRefCount()  {}
};

struct ICalc : public IRefCount
{
    virtual int Add(int a, int b) = 0;
    virtual int Sub(int a, int b) = 0;

    virtual ~ICalc() {}
};
