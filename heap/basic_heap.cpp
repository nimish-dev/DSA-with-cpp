#include<iostream>
using namespace std;
void heap_conv(int *p,int n);
class node_t
{
    public:
        int data;
        node_t* left;
        node_t* right;
};
class Heap
{
    private:
        node_t* root;
    public:
        Heap(){root=NULL;}
        void create_heap(int *p,int n);
};

class node
{
    public:
        node_t* data;
        node* next;
};
class queue
{
    private:
        node* front;
        node* rear;
    public:
        queue();
        void enqueue(node_t* x);
        node_t* dequeue();
        bool is_empty();
};
queue::queue()
{
    front=NULL;
    rear=NULL;
}
void queue::enqueue(node_t* x)
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
node_t* queue::dequeue()
{
    node* p=front;
    node_t* x=p->data;
    front=p->next;
    delete p;
    return x;
}
bool queue::is_empty()
{
    if(front==NULL)
    {
        return true;
    }
    return false;
}
void Heap::create_heap(int *p,int n)
{
    
}
int main()
{
    cout<<"Enter the size of the array : ";
    int n;
    cin>>n;
    int *p=new int[n+1];
    cout<<"Enter "<<n<<" values : ";
    for(int i=1;i<=n;i++)
    {
        cin>>*(p+i);
    }
    cout<<"The original array is : ";
    for(int i=1;i<=n;i++)
    {
        cout<<*(p+i)<<" ";
    }
    heap_conv(p,n);
    cout<<"\nThe Heap array is : ";
    for(int i=1;i<=n;i++)
    {
        cout<<*(p+i)<<" ";
    }
    Heap H;
    H.create_heap(p,n);
}
void heap_conv(int *p,int n)
{
    for(int i=n;i>1;i--)
    {
        int j=i;
        while( j>1 && p[j]>p[j/2])
        {
            swap(p[j],p[j/2]);
            j=j/2;
        }
    }
}