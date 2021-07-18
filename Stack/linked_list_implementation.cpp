#include<iostream>
using namespace std;
class node
{
    public: 
        int data;
        node* next;
};
class linked_list
{
    private:
        node* top;
    public: 
        linked_list(){top=NULL;}
        void push();
        int pop();
        int Top();
        bool isempty();
        void display();
};
void linked_list::push()
{
    cout<<"How many elements you want to push into the stack : ";
    int n;
    cin>>n;
    cout<<"Enter "<<n<<" elements to push into the stack :\n";
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        node* t=new node;
        t->data=x;
        t->next=top;
        top=t;
    }
}
void linked_list::display()
{
    cout<<"The contenets of the stack : ";
    node* p=top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}
int linked_list::Top()
{
    return top->data;
}
int linked_list::pop()
{
    int x=top->data;
    node* p=top;
    top=p->next;
    delete p;
    return x;
}
bool linked_list::isempty()
{
    if(top==NULL)
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
    linked_list lst1;
    lst1.push();
    lst1.display();
    cout<<"The element at the top of the stack : "<<lst1.Top()<<"\n";
    cout<<"The popped element : "<<lst1.pop()<<"\n";
    lst1.display();
    bool res=lst1.isempty();
    if(res)
    {
        cout<<"The stack is empty\n";
    }
    else
    {
        cout<<"The stack is not empty\n";
    }

}