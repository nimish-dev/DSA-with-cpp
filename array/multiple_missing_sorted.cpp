#include<iostream>
using namespace std;
void multiple_missing_element(int arr[],int a,int n);
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
    multiple_missing_element(arr,a,n);    
}
void multiple_missing_element(int arr[],int a,int n)
{
    int* res=new int[n],k=0;
    for(int i=1;i<n;)
    {
        if((arr[i]-i)!=a)
        {
            *(res+k)=a+i;
            a=arr[i]-i;
            k++;
            continue;
        }
        i++;
    }
    if(*(res+0)==0)
    {
        cout<<"No missing element is there in the array\n";
    }
    else
    {
        cout<<"The missing element is ";
        for(int i=0;i<k;i++)
        {
            cout<<*(res+i)<<" ";
        }
        cout<<"\n";
    }
}