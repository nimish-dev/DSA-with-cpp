#include<iostream>
using namespace std;
int ideal_hash(int *P,int n,int key);
int hash_fun(int x);
int search(int *p,int key);
int main()
{
    cout<<"Enter the size of the array : ";
    int n;
    cin>>n;
    int *p=new int[n];
    cout<<"Enter the elements and unit digits should nat be repeated : ";
    for(int i=0;i<n;i++)
    {
        cin>>*(p+i);
    }
    cout<<"Enter the key you want to search : ";
    int key;
    cin>>key;
    int res=ideal_hash(p,n,key);
    if(res!=0)
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
    int *hash_tab=new int[10];
    for(int i=0;i<10;i++)
    {
        *(hash_tab+i)=0;
    }
    for(int i=0;i<n;i++)
    {
        int res=hash_fun(*(p+i));
        *(hash_tab+res)=*(p+i);
    }
    return search(hash_tab,key);
}
int hash_fun(int x)
{
    return x%10;
}
int search(int *p,int key)
{
    int index=hash_fun(key);
    if(*(p+index)==key)
    {
        return 1;
    }
    return 0;
}
