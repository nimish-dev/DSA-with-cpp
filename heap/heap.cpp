#include<iostream>
using namespace std;
int main()
{
    cout<<"How many values you want to enter : ";
    int n;
    cin>>n;
    int *p=new int[n];
    *p=0;
    cout<<"Enter "<<n<<" values : ";
    for(int i=1;i<=n;i++)
    {
        cin>>*(p+i);
    }
    cout<<"The basic array is : [ ";
    for(int i=1;i<=n;i++)
    {
        cout<<*(p+i)<<" ";
    }
    cout<<" ]\n";
    for(int i=2;i<=n;i++)
    {
        int j=i;
        while((*(p+j)>*(p+(j/2)))&& (j!=1))
        {
            swap(*(p+j),*(p+(j/2)));
            j=j/2;
        }
    }
    cout<<"The heap array is : [ ";
    for(int i=1;i<=n;i++)
    {
        cout<<*(p+i)<<" ";
    }
    cout<<" ]\n";
}