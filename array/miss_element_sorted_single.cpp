#include<iostream>
using namespace std;
int missing_element(int arr[],int a,int n);
int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter "<<n<<" elements in sorted order: \n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int a=arr[0];
    int res=missing_element(arr,a,n);
    if(res==0)
    {
        cout<<"No missing element is there in the array\n";
    }
    else
    {
        cout<<"The missing element is "<<res<<"\n";
    }
}
int missing_element(int arr[],int a,int n)
{
    for(int i=1;i<n;i++)
    {
        if((arr[i]-i)!=a)
        {
            return a+i;
        }
    }
    return 0;
}