/* 
利用栈判断括号
*/

#include <iostream>
#include "Stack.h"
using namespace std;


int show(int& i)
{
    cout<<i<<' ';
    return 1;
}


int main()
{
    //校验一个表达式中的括号是否匹配
    //(1+2)*(3+5)*[3*(4+6)]+6
    
    // ( : 0010 1000  ) : 0010 1001    '('+1 | 1 == ')'
    // [ : 0101 1011  ] : 0101 1101    '['+1 | 1 == ']'
    // { : 0111 1011  } : 0111 1101    '{'+1 | 1 == '}'
    
    string exp;

    cout<<"请输入一个任意的表达式：";
    cin>>exp;

    
    Stack<char> s;
    int flag=1;
    
    int i;
    for(i=0;i<exp.size();i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            s.push(exp[i]); 

        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if(s.empty()) 
            {
                flag=0;
                break;          
            }

            char c;
            s.get_top(c);

            if(((c+1)|1)==exp[i]) s.pop();
            else flag=0;

            /*
            switch(exp[i])
            {
                case ')':
                    {
                        if(c=='(') s.pop();
                        else flag=0;
                    }
                    break;

                case ']':
                    {
                        if(c=='[') s.pop();
                        else flag=0;
                    }
                    break;

                case '}':
                    {
                        if(c=='{') s.pop();
                        else flag=0;
                    }
                    break;
            }
            */
        }

        if(!flag) break;
    }

    if(!flag || !s.empty())
    {
        cout<<"表达式非法！"<<endl;
    }
    else
    {
        cout<<"表达式合法！"<<endl;
    }

    

    /*
    Stack<int> s1;
    
    if(s1.empty())
    {
        cout<<"栈为空！"<<endl;
    }

    s1.push(5);
    s1.push(3);
    s1.push(1);
    s1.push(7);

    s1.traverse(show);
    cout<<endl;

    s1.pop();
    cout<<s1.length()<<endl;


    int i;
    s1.get_top(i);
    cout<<i<<endl;
    */

    return 0;
}
