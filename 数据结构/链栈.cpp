//链栈的实现
#include <assert.h>

template <typename VAL_TYPE>
class Stack
{
private:
    struct Node
    {
        VAL_TYPE data;
        Node* next;
    };

    Node* top; //栈顶指针
    Node* bottom; //栈底指针
    int size;

public:
    Stack();
    virtual ~Stack();

    void push(const VAL_TYPE& val);
    void pop();
    void get_top(VAL_TYPE& val) const;
    void clear();

    bool empty() const;
    int length() const;

    void traverse(int(*visit)(VAL_TYPE&));
};

template <typename VAL_TYPE>
Stack<VAL_TYPE>::Stack()
{
    top=bottom=NULL;
    size=0;
}

template <typename VAL_TYPE>
Stack<VAL_TYPE>::~Stack()
{
    Node* p=NULL;

    while(top!=NULL)
    {
        p=top->next;
        delete top;
        top=p;
    }

    bottom=NULL;
    size=0;
}

template <typename VAL_TYPE>
void Stack<VAL_TYPE>::clear()
{
    ~Stack();
}

template <typename VAL_TYPE>
void Stack<VAL_TYPE>::push(const VAL_TYPE& val)
{
    Node* new_node=new Node;
    new_node->data=val;
    new_node->next=top;

    top=new_node;
    if(bottom==NULL) bottom=top;
    size++;
}

template <typename VAL_TYPE>
void Stack<VAL_TYPE>::pop()
{
    assert(top!=NULL);

    Node* p=top->next;
    delete top;
    top=p;

    size--;
}

template <typename VAL_TYPE>
void Stack<VAL_TYPE>::get_top(VAL_TYPE& val) const
{
    assert(top!=NULL);
    val=top->data;
}

template <typename VAL_TYPE>
bool Stack<VAL_TYPE>::empty() const
{
    return !size;
}

template <typename VAL_TYPE>
int Stack<VAL_TYPE>::length() const
{
    return size;
}

template <typename VAL_TYPE>
void Stack<VAL_TYPE>::traverse(int(*visit)(VAL_TYPE& val))
{
    Node* p=top;

    while(p!=NULL)
    {
        if(!visit(p->data)) break;
        p=p->next;
    }
}


