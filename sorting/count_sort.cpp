#include<iostream>
using namespace std;
void count_sort(int *p,int n);
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
    count_sort(p,n);
    cout<<"The sorted array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<*(p+i)<<" ";
    }
}
void count_sort(int *p,int n)
{
    int max=*p;
    for(int i=1;i<n;i++)
    {
        if(*(p+i)>max)
        {
            max=*(p+i);
        }
    }
    int *q=new int[max+1];
    for(int i=0;i<=max;i++)
    {
        *(q+i)=0;
    }
    for(int i=0;i<n;i++)
    {
        *(q+*(p+i))+=1;
    }
    int k=0;
    for(int i=0;i<=max;i++)
    {
        while(*(q+i)!=0)
        {
            *(p+k)=i;
            k++;
            (*(q+i))--;
        }
    }
}