//顺序栈的实现
#include <assert.h>
#include <cstring>

template <typename VAL_TYPE>
class Stack
{
private:
    VAL_TYPE* top;
    VAL_TYPE* bottom;
    int size;
    int cap;

    enum { INIT_SIZE=100, INCREMENT_SIZE=10 };

public:
    Stack()
    {
        top=bottom=new VAL_TYPE[INIT_SIZE]; //3+2+1
        size=0;
        cap=INIT_SIZE;
    }

    virtual ~Stack()
    {
        delete bottom;
        top=bottom=NULL;
        size=0;
        cap=0;
    }

    void push(VAL_TYPE& val)
    {
        if(size>=cap)
        {
            VAL_TYPE* p=new VAL_TYPE[cap+INCREMENT_SIZE];
            memcpy(p,bottom,cap);
            delete bottom;

            bottom=p;
            top=bottom+size;
            cap+=INCREMENT_SIZE;
        }


        *top++=val;
        size++;
    }

    void pop()
    {
        assert(size!=0);

        top--;
        size--;
    }

    void get_top(VAL_TYPE& val) const
    {
        assert(size!=0);

        val=*(top-1);
    }


    bool empty() const
    {
        return !size;
    }

    int length() const
    {
        return size;
    }
};
