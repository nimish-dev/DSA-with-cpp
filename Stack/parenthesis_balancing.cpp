#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
class parenthesis
{
    private:
        char* p;
        int n;
    public:
        parenthesis(){}
        void create();
        bool parenthesis_check();
};
void parenthesis::create()
{
    cout<<"Enter the length of the array : ";
    cin>>n;
    p=new char[n];
    cout<<"Enter the array contents : ";
    for(int i=0;i<n;i++)
    {
        cin>>*(p+i);
    }
}
bool parenthesis::parenthesis_check()
{
    if(n%2!=0)
    {
        return false;
    }
    stack<char> s;
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        {
            if((*(p+i)=='(')||(*(p+i)=='{')||(*(p+i)=='['))
            {
                s.push(*(p+i));
            }
            else
            {
                return false;
            }
        }
        else
        {
            if((*(p+i)=='(')||(*(p+i)=='{')||(*(p+i)=='['))
            {
                s.push(*(p+i));
            }
            else
            {
                char t=s.top();
                if((t=='(' && *(p+i)==')')||(t=='{' && *(p+i)=='}')||(t=='[' && *(p+i)==']'))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if(s.empty())
    {
        return true;
    }
    return false;
}
int main()
{
    parenthesis p;
    p.create();
    bool res=p.parenthesis_check();
    if(res)
    {
        cout<<"It is balanced parenthesis\n";
    }
    else
    {
        cout<<"It is unbalanced parenthesis\n";
    }
}