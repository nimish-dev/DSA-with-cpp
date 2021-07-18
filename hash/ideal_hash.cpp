#include<iostream>
using namespace std;
int ideal_hash(int *P,int n,int key);
int hash_fun(int x);
int search(int *p,int key,int max);
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
    cout<<"Enter the key you want to search : ";
    int key;
    cin>>key;
    int res=ideal_hash(p,n,key);
    if(res==1)
    {
        cout<<"The key is found!\n";
    }
    else
    {
        cout<<"The key is not found!\n";
    }
}
int ideal_hash(int *p,int n,int key)
{
    int max=*p;
    for(int i=1;i<n;i++)
    {
        if(max<*(p+i))
        {
            max=*(p+i);
        }
    }
    int *hash_tab=new int[max+1];
    for(int i=0;i<=max;i++)
    {
        *(hash_tab+i)=0;
    }
    for(int i=0;i<n;i++)
    {
        int res=hash_fun(*(p+i));
        (*(hash_tab+res))++;
    }
    return search(hash_tab,key,max);
}
int hash_fun(int x)
{
    return x;
}
int search(int *p,int key,int max)
{
    int index=hash_fun(key);
    if(key>max)
    {
        return 0;
    }
    if(*(p+index)!=0)
    {
        return 1;
    }
    return 0;
}
