#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node* next;
};
void chaining(int *p,int n);
int hash_fun(int x);
int search(node** p,int key);
void insert(node** p,int n,int x);
int remove(node** p,int key);
int main()
{
    cout<<"Enter the size of the array : ";
    int n;
    cin>>n;
    int *p=new int[n];
    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>*(p+i);
    }
    chaining(p,n);
}
void chaining(int *p,int n)
{
    node** hash_tab=new node*[10];
    for(int i=0;i<10;i++)
    {
        *(hash_tab+i)=NULL;
    }
    for(int i=0;i<n;i++)
    {
        int index=hash_fun(*(p+i));
        insert(hash_tab,index,*(p+i));
    }
    int res,key;
    cout<<"Enter the key you want to delete : ";
    cin>>key;
    res=remove(hash_tab,key);
    if(res==0)
    {
        cout<<"The key is not found! S0, couldn't be deleted\n";
    }
    else
    {
        cout<<"The key is found and deleted!\n";
    }
}
int hash_fun(int x)
{
    return x%10;
}
void insert(node** p,int n,int x)
{
    node* t= new node;
    t->data=x;
    t->next=NULL;
    if(*(p+n)==NULL)
    {
        *(p+n)=t;
        return;
    }
    node* m=*(p+n);
    node* k=NULL;
    if(m->data>x)
    {
        t->next=m;
        *(p+n)=t;
        return;
    }
    while(m!=NULL)
    {
        if(m->data<x)
        {
            k=m;
            m=m->next;
        }
        else
        {
            break;
        }
    }  
    t->next=k->next;
    k->next=t;
    return;  
}
int search(node** p,int key)
{
    int index=hash_fun(key);
    node* m=*(p+index);
    while(m!=NULL)
    {
        if(m->data==key)
        {
            return 1;
        }
        m=m->next;
    }
    return 0;
}
int remove(node** p,int key)
{
    int res=search(p,key);
    if(res==0)
    {
        return 0;
    }
    int index=hash_fun(key);
    node* m=*(p+index);
    node* k=NULL;
    if(m->data==key)
    {
        *(p+index)=m->next;
    }
    while(m!=NULL)
    {
        if(m->data==key)
        {
            k->next=m->next;
            delete m;
            return 1;
        }
        k=m;
        m=m->next;
    }
    return 0;
}
