#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node* next;
};
class queue
{
    private:
        node* front;
        node* rear;
    public:
        queue();
        void enqueue(int x);
        void display();
        int dequeue();
};
queue::queue()
{
    front=NULL;
    rear=NULL;
}
void queue::enqueue(int x)
{
    node* t=new node;
    t->data=x;
    t->next=NULL;
    if(front==NULL)
    {
        front=rear=t;
    }
    else
    {
        rear->next=t;
        rear=t;
    }
}
void queue::display()
{
    node* p=front;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}
int queue::dequeue()
{
    node* p=front;
    int x=p->data;
    front=p->next;
    delete p;
    return x;
}
int main()
{
    queue q;
    cout<<"How many values you want to insert : ";
    int n;
    cin>>n;
    cout<<"Start entering the values : ";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.enqueue(x);
    }
    cout<<"The queue content is : ";
    q.display();
    cout<<"The dequeued item from the queue is : "<<q.dequeue()<<"\n";
    cout<<"The list after the dequeue operation is : ";
    q.display();
}