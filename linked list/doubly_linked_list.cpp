#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node* prev;
        node* next;
};
class doubly
{
    private:
        node* head;
    public:
        doubly(){head=NULL;}
        void create(int A[],int n);
        void display();
        void insert(int pos,int x);
        void reverse();
        void remove(int n);
};

node* newnode(int x);
void doubly::create(int A[],int n)
{
    head=new node;
    head->data=A[0];
    head->next=NULL;
    head->prev=NULL;
    node* last=head;
    for(int i=1;i<n;i++)
    {
        node* t=newnode(A[i]);
        last->next=t;
        t->prev=last;
        last=t;
    }
}

node* newnode(int x)
{
    node* t=new node;
    t->data=x;
    t->next=NULL;
    t->prev=NULL;
    return t;
}

void doubly::display()
{
    node* p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}


void doubly::insert(int pos,int x)
{
    node* t=newnode(x);
    if(pos==0)
    {
        head->prev=t;
        t->next=head;
        head=t;
        return;
    }
    node* p=head;
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    t->next=p->next;
    t->prev=p;
    p->next=t;
    p=t->next;
    if(p!=NULL)
    {
        p->prev=t;
    }
}

void doubly::reverse()
{
    node* p=head;
    while(p!=NULL)
    {
        swap(p->next,p->prev);
        head=p;
        p=p->prev;
    }
}
void doubly::remove(int n)
{
    node *p=head;
    if(n==1)
    {
        head=p->next;
        head->prev=NULL;
        delete p;
        return;
    }
    node *q=NULL;
    for(int i=0;i<n-1;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    q=p->next;
    if(q!=NULL)
    {
        q->prev=p->prev;
    }
    delete p;
}
int main()
{
    cout<<"Enter the number of data : ";
    int n;
    cin>>n;
    cout<<"Enter "<<n<<" numbers for the array :\n";
    int *A=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>*(A+i);
    }
    doubly d;
    d.create(A,n);
    cout<<"The given list is : ";
    d.display();
    cout<<"Enter the position and data to insert : ";
    int pos,x;
    cin>>x>>pos;
    d.insert(pos,x);
    cout<<"The list after insertion of an element : ";
    d.display();
    d.reverse();
    cout<<"The list after reversal : ";
    d.display();
    cout<<"Enter the position you want to remove : ";
    cin>>pos;
    d.remove(pos);
    cout<<"List after removal of an element : ";
    d.display();
}