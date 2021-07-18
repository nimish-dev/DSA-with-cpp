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
        node* head;
    public:
        linked_list(){head=NULL;}
        linked_list(int A[],int n);
        node* get_head();
        void display();
        void recursive_display(node* p);
        int count();
        int sum();
        int max();
        int min();
        bool search(int key);
        void insert(int pos,int x);
        void delete_element(int pos);
};
node* newnode(int x);
linked_list::linked_list(int A[],int n)
{
    node* last,*t;
    head=new node;
    head->data=A[0];;
    head->next=NULL;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=newnode(A[i]);
        last->next=t;
        last=t;
    }
};
node* newnode(int x)
{
    node* p=new node;
    p->data=x;
    p->next=NULL;
    return p;
}
node* linked_list::get_head()
{
    return head;
}
void linked_list::display()
{
    node* p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}
void linked_list::recursive_display(node* p)
{
    linked_list l1;
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        l1.recursive_display(p->next);
    }
    else
    {
        return;
    }
}
int linked_list::count()
{
    node* p=head;
    int cnt=0;
    while(p!=NULL)
    {
        cnt++;
        p=p->next;
    }
    return cnt;
}
int linked_list::sum()
{
    node* p=head;
    int add=0;
    while(p!=NULL)
    {
        add=add+p->data;
        p=p->next;
    }
    return add;
}
int linked_list::max()
{
    node* p=head;
    int max=p->data;
    while(p!=NULL)
    {
        if(max<p->data)
        {
            max=p->data;
        }
        p=p->next;
    }
    return max;
}
int linked_list::min()
{
    node* p=head;
    int min=p->data;
    while(p!=NULL)
    {
        if(min>p->data)
        {
            min=p->data;
        }
        p=p->next;
    }
    return min;
}
bool linked_list::search(int key)
{
    node* p=head;
    while(true)
    {
        if(p==NULL)
        {
            return false;
        }
        else if(p->data==key)
        {
            return true;
        }
        p=p->next;
    }
}
void linked_list::insert(int pos,int x)
{
    if(pos==0)
    {
        node* t=newnode(x);
        t->next=head;
        head=t;
        return;
    }
    node* p=head;
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    node* t=newnode(x);
    t->next=p->next;
    p->next=t;
}
void linked_list::delete_element(int pos)
{
    if(pos==0)
    {
        node* p=head;
        head=p->next;
        delete p;
        return;
    }
    node* p=head;
    node* q=NULL;
    for(int i=0;i<pos-1 && p!=NULL;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    delete p;
}
int main()
{
    cout<<"Enter the number of elements : ";
    int n;
    cin>>n;
    int *A=new int[n];
    cout<<"Enter "<<n<<" elements for the list : \n";
    for(int i=0;i<n;i++)
    {
        cin>>*(A+i);
    }
    linked_list list1(A,n);
    list1.display();
    node* p=list1.get_head();
    list1.recursive_display(p);
    int count=list1.count();
    cout<<"\nThe total number of elements in the list is "<<count<<".\n";
    int sum=list1.sum();
    cout<<"Sum of elements for this linked list is "<<sum<<".\n";
    int max=list1.max();
    int min=list1.min();
    cout<<"The maximum value is "<<max<<" & The minimum value is "<<min<<".\n";
    int key;
    cout<<"Enter key to be searched for : ";
    cin>>key;
    bool res=list1.search(key);
    if(res)
    {
        cout<<"The key is found in the list.\n";
    }
    else
    {
        cout<<"The key is not found in the list.\n";
    }
    cout<<"Enter the data and position where you want to insert : ";
    int pos,x;
    cin>>x>>pos;
    list1.insert(pos,x);
    cout<<"\nList after insertion of an element :\n";
    list1.display();
    cout<<"Enter the position you want to remove from the list : ";
    cin>>pos;
    list1.delete_element(pos);
    cout<<"The elements in the list after deleteion of an element : ";
    list1.display();
}