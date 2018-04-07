template<typename T> class smartptr
{
    T* obj;
public:
    smartptr(T* p = 0) : obj(p)
    {
        if ( obj != 0 )
            obj->AddRef();
    }
    smartptr(const smartptr& p) : obj(p.obj)
    {
        if ( obj != 0 )
            obj->AddRef();
    }
    ~smartptr()
    {
        if ( obj != 0 )
            obj->Release();
    }

    T* operator->() { return obj;}
    T& operator*()  { return *obj;}
};
