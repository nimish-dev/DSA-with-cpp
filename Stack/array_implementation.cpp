#include<iostream>
using namespace std;
class Array
{
    private:
        int top=-1;
        int size=10;
        int *p;
    public:
        Array();
        void insert();
        void display();
        int Top();
        int pop();
        bool isempty();
};
Array::Array()
{
    p=new int[10];
}
void Array::insert()
{
    cout<<"Enter the number of elements you want to enter into the stack : ";
    int n;
    cin>>n;
    if(n>size)
    {
        cout<<"Stack overflow!\n";
        return;
    }
    cout<<"Start entering "<<n<<" values :\n";
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        top++;
        if(top!=size-1)
        {
            *(p+top)=x;
        }
        else
        {
            cout<<"Stack overflow!\n";
            return;
        }
    }
}
void Array::display()
{
    cout<<"The stack array contenet is : ";
    for(int i=0;i<=top;i++)
    {
        cout<<*(p+i)<<" ";
    }
    cout<<"\n";
}
int Array::Top()
{
    return *(p+top);
}
int Array::pop()
{
    int x=*(p+top);
    top=top-1;
    return x;
}
bool Array::isempty()
{
    if(top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    Array A;
    A.insert();
    A.display();
    cout<<"The element at the top of the stack : "<<A.Top()<<"\n";
    cout<<"The popped element : "<<A.pop()<<"\n";
    A.display();
    bool res=A.isempty();
    if(res)
    {
        cout<<"The stack is empty\n";
    }
    else
    {
        cout<<"The stack is not empty\n";
    }
}