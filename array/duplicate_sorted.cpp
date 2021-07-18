#include<iostream>
using namespace std;
void duplicate_sorted(int arr[],int n);
int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter "<<n<<" elements in any order: \n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    duplicate_sorted(arr,n);    
}
void duplicate_sorted(int arr[],int n)
{
    int a=0;
    cout<<"The repeated elements are : ";
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            if(a!=arr[i])
            {
                a=arr[i];
                cout<<a<<" ";
            }
        }
    }
}