#include<iostream>
using namespace std;
void pair_sum(int arr[],int n,int sum);
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
    cout<<"Enter the sum to be found : ";
    int sum;
    cin>>sum;
    pair_sum(arr,n,sum);    
}
void pair_sum(int arr[],int n,int sum)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    int res[max+1]={0};
    cout<<"The sum pairs are :\n";
    for(int i=0;i<n;i++)
    {
        if((sum-arr[i])<0)
        {
            continue;
        }
        if(res[sum-arr[i]]!=0)
        {
            cout<<"("<<sum-arr[i]<<","<<arr[i]<<")\n";
            res[arr[i]]=1;
        }
        else
        {
            res[arr[i]]=1;
        }
    }
}