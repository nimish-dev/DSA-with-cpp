#include<iostream>
using namespace std;
void duplicate_sorted_freq(int arr[],int n);
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
    duplicate_sorted_freq(arr,n);    
}
void duplicate_sorted_freq(int arr[],int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    int res[max]={0};
    for(int i=0;i<n;i++)
    {
        res[arr[i]-1]++;
    }
    cout<<"The repeated elements are :\n";
    for(int i=0;i<max;i++)
    {
        if(res[i]>1)
        {
            cout<<i+1<<"---"<<res[i]<<"\n";
        }
    }
}