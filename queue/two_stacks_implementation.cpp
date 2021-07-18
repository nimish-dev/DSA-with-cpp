#include<iostream>
#include<stack>
using namespace std;
class queue
{
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        queue(){}
        void enqueue(int x);
        int dequeue();
        void display();
};
void queue::enqueue(int x)
{
    s1.push(x);
}
int queue::dequeue()
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    int x=s2.top();
    s2.pop();
    return x;
}
void queue::display()
{
    if(s2.empty())
    {
        cout<<"The queue is empty!\n";
        return;
    }
    while(!s2.empty())
    {
        cout<<s2.top()<<" ";
        s1.push(s2.top());
        s2.pop();
    }
}
int main()
{
    queue q;
    cout<<"How many values you want to insert into the queue : ";
    int n;
    cin>>n;
    cout<<"Start entering the values : ";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.enqueue(x);
    }
    cout<<"How many values you want to dequeue : ";
    cin>>n;
    cout<<"\nthe dequeued list is : ";
    for(int i=0;i<n;i++)
    {
        cout<<q.dequeue()<<" ";
    }
    cout<<"\nAfter dequeueing the list is : ";
    q.display();
}