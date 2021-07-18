#include<iostream>
#include<math.h>
using namespace std;
struct node
{
    int data;
    node* next;
};
void radix_sort(int *p,int n);
int get_index(int x,int pass);
void insert_node(int x,int y,node** p);
int remove(node** p,int n);
void print(int* p,int n);
int main()
{
    cout<<"Enter the size of the array : "; //Getting the size of the array
    int n;
    cin>>n;
    int *p=new int[n];  //Creating a blank array for the size entered above using dynamic memory allocation
    cout<<"Enter "<<n<<" elements for the array in unsorted order : ";
    for(int i=0;i<n;i++)
    {
        cin>>*(p+i);
    }
    radix_sort(p,n);
    print(p,n);
}
void radix_sort(int *p,int n)
{
    node** q=new node*[10];
    for(int i=0;i<10;i++)
    {
        *(q+i)=NULL;
    }
    int max=*p;
    for(int i=1;i<n;i++)
    {
        if(max<*(p+i))
        {
            max=*(p+i);
        }
    }
    int pass=0;
    while(max>0)
    {
        pass++;
        max=max/10;
    }
    for(int i=0;i<pass;i++)
    {
        for(int j=0;j<n;j++)
        {
            int pos=get_index(*(p+j),i);
            insert_node(*(p+j),pos,q);
        }
        int k=0;
        for(int j=0;j<10;)
        {
            while(*(q+j)!=NULL)
            {
                *(p+k)=remove(q,j);
                k++;
            }
            j++;
        }
    }
}
int get_index(int x,int pass)
{
    return (int)(x/pow(10,pass))%10;
}
void insert_node(int x,int y,node** p)
{
    node* t=new node;
    t->data=x;
    t->next=NULL;
    if(*(p+y)==NULL)
    {
        *(p+y)=t;
        return;
    }
    node* m=*(p+y);
    while(m->next!=NULL)
    {
        m=m->next;
    }
    m->next=t;
}
int remove(node** p,int n)
{
    node* m=*(p+n);
    *(p+n)=m->next;
    int x=m->data;
    delete m;
    return x;
}
void print(int *p,int n)
{
    cout<<"The sorted array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<*(p+i)<<" ";
    }
    cout<<"\n";
}