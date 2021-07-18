#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
void bin_sort(int *p,int n);
void insert(node** p,int x);
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
    bin_sort(p,n);
    cout<<"The sorted array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<*(p+i)<<" ";
    }
}
void bin_sort(int *p,int n)
{
    int max=*p;
    for(int i=1;i<n;i++)
    {
        if(max<*(p+i))
        {
            max=*(p+i);
        }
    }
    node** q=new node*[max+1];
    for(int i=0;i<=max;i++)
    {
        *(q+i)=NULL;
    }
    int k=0;
    for(int i=0;i<n;i++)
    {
        insert(q,*(p+i));
    }
    for(int i=0;i<=max;i++)
    {
        if(*(q+i)!=NULL)
        {
            node* m=*(q+i);
            while(m!=NULL)
            {
                *(p+k)=m->data;
                k++;
                m=m->next;
            }
        }
   }
}
void insert(node** p,int x)
{
    node* t=new node;
    t->data=x;
    t->next=NULL;
    if(*(p+x)==NULL)
    {
        *(p+x)=t;
        return;
    }
    node* m=*(p+x);
    while(m->next!=NULL)
    {
        m=m->next;
    }
    m->next=t;
}