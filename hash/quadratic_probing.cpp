#include<iostream>
using namespace std;
void quad_probing(int *p,int n);
int hash_fun(int x);
void insert(int *p,int index,int x);
int search(int *p,int key);
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
    quad_probing(p,n);
}
void quad_probing(int *p,int n)
{
    int* hash_tab=new int[10];
    for(int i=0;i<10;i++)
    {
        *(hash_tab+i)=-1;
    }
    for(int i=0;i<n;i++)
    {
        int index=hash_fun(*(p+i));
        insert(hash_tab,index,*(p+i));
    }
    cout<<"The hash table is : \n";
    for(int i=0;i<10;i++)
    {
        cout<<*(hash_tab+i)<<"\n";
    }
    cout<<"Enter the key you want to search for : ";
    int key;
    cin>>key;
    int res=search(hash_tab,key);
    if(res==1)
    {
        cout<<"The saerched key is found!\n";
    }
    else
    {
        cout<<"The searched key is not found!\n";
    }
}
int hash_fun(int x)
{
    return x%10;
}
int i_fun(int i)
{
    return i*i;
}
void insert(int *p,int index,int x)
{
    for(int i=0;i<10;i++)
    {
        int y=(index+i_fun(i))%10;
        if(*(p+y)==-1)
        {
            *(p+y)=x;
            return;
        }
    }
}
int search(int *p,int key)
{
    int index=hash_fun(key);
    for(int i=0;i<10;i++)
    {
        int y=(index+i_fun(i))%10;
        if(*(p+y)==key)
        {
            return 1;
        }
        else if(*(p+y)==-1)
        {
            return 0;
        }
    }
    return 0;
}