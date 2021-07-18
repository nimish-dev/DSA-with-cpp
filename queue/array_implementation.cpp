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
    cout<<"Enter the size of the array : ";
    cin>>size;
    p=new int[size];
    front=-1;
    rear=-1;
}
void queue::enqueue(int n)
{
    cout<<"Enter "<<n<<" vallues to enqueue into the queue :\n";
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(rear!=size-1)
        {
            rear++;
            *(p+rear)=x;
        }
        else
        {
            cout<<"Queue is full\n";
            break;
        }
    }
}
void queue::display()
{
    int m=front;
    if(front==rear)
    {
        cout<<"The queue is empty\n";
        return;
    }
    while(m!=rear)
    {
        m++;
        cout<<*(p+m)<<" ";
    }
    cout<<"\n";
}
int queue::dequeue()
{
    if(front==rear)
    {
        cout<<"Nothing to dequeue\n";
        return;
    }
    int m=front;
    front++;
    return *(p+front);
}
int main()
{
    queue q;
    cout<<"How many elements you want to enter into the array : ";
    int n;
    cin>>n;
    q.enqueue(n);
    cout<<"The queue is : ";
    q.display();
    cout<<"The dequeued element is : "<<q.dequeue();
    cout<<"The queue after dequeue : ";
    q.display();
}

