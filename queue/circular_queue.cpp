#include<iostream>
using namespace std;
class queue
{
    private:
        int size;
        int front;
        int rear;
        int *p;
    public:
        queue();
        void enqueue(int n);
        void display();
        int dequeue();
};
queue::queue()
{
    front=0;
    rear=0;
    cout<<"Enter the size of the array : ";
    cin>>size;
    p=new int[size];
}
void queue::enqueue(int x)
{
    if(((rear+1)%size)==front)
    {
        cout<<"Queue is full\n";
        return;
    }
    rear=(rear+1)%size;
    *(p+rear)=x;
}
void queue::display()
{
    int m=front;
    if(((m+1)%size)==rear)
    {
        cout<<"The queue is empty\n";
        return;
    }
    while((m%size)!=rear)
    {
        m=(m+1)%size;
        cout<<*(p+m)<<" ";
    }
    cout<<"\n";
}
int queue::dequeue()
{
    front=(front+1)%size;
    return *(p+front);
}
int main()
{
    queue q;
    cout<<"How many values you want to enter : ";
    int n;
    cin>>n;
    cout<<"Start entering the values : ";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.enqueue(x);
    }
    cout<<"The queue contents are : ";
    q.display();
    cout<<"The dequeued element from the queue is : "<<q.dequeue()<<"\n";
    q.enqueue(3);
    cout<<"Queue after another enqueue operation is : ";
    q.display();
}