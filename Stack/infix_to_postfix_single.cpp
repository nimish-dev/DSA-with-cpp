#include<iostream>
#include<stack>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;
class infix_to_postfix
{
    private:
        string p;
        string q="";
    public:
        infix_to_postfix(){}
        void create();
        void post_conv();
        void display();
        int post_eval();
};
bool isoperand(char p);
int pre(char p);
void infix_to_postfix::create()
{
    cout<<"Enter the infix expression : ";
    getline(cin,p);
}

void infix_to_postfix::post_conv()
{
    stack<char> s;
    int n=p.length();
    for(int i=0;i<n;)
    {
        if(isoperand(p[i]))
        {
            q+=p[i];
            i++;
        }
        else
        {
            if(s.empty())
            {
                s.push(p[i]);
                i++;
            }
            else
            {
                if(pre(p[i]) >= (pre(s.top())))
                {
                    s.push(p[i]);
                    i++;
                }
                else
                {
                    while(pre(p[i]) <= (pre(s.top())))
                    {
                        q+=s.top();
                        s.pop();
                        if(s.empty())
                        {
                            break;
                        }
                    }
                    s.push(p[i]);
                    i++;
                }
            }
        }
    }
    while(!s.empty())
    {
        q+=s.top();
        s.pop();
    }
}
bool isoperand(char p)
{
    if(p=='+' || p=='-' || p=='*' || p=='/')
    {
        return false;
    }
    return true;
}
int pre(char p)
{
    if(p=='+' || p=='-')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
void infix_to_postfix::display()
{
    cout<<"Infix : "<<p<<"\n";
    cout<<"Postfix : "<<q<<"\n";
}

int infix_to_postfix::post_eval()
{
    stack<int> s;
    int n=p.size();
    for(int i=0;i<n;i++)
    {
        if(isoperand(q[i]))
        {
            char m=q[i];
            char *t=&m;
            int num=atoi(t);
            cout<<num<<"\n";
            s.push(num);
        }
        else
        {
            int n2=s.top();
            s.pop();
            int n1=s.top();
            s.pop();
            switch(q[i])
            {
                case '+':
                    s.push(n1+n2);
                    break;
                case '-':
                    s.push(n1-n2);
                    break;
                case '*':
                    s.push(n1*n2);
                    break;
                case '/':
                    s.push(n1/n2);
                    break;
            }
        }
    }
    return s.top();
}

int main()
{
    infix_to_postfix p;
    p.create();
    p.post_conv();
    p.display();
    int res=p.post_eval();
    cout<<"Final result = "<<res<<"\n";
}