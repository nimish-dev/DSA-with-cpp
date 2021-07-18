#include<iostream>
using namespace std;
void quick_sort(int *p,int l,int h);
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
    quick_sort(p,0,n-1);
    cout<<"The sorted array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<*(p+i)<<" ";
    }
}
void quick_sort(int *p,int l,int h)
{
    if(l>=h)
    {
        return;
    }
    int mid=(l+h)/2;
    int i=l;
    int j=h;
    while(i<j)
    {
        while(*(p+i)<*(p+mid))
        {
            i++;
        }
        while(*(p+j)>*(p+mid))
        {
            j--;
        }
        swap(*(p+i),*(p+j));
        if(mid==i)
        {
            mid=j;
        }
        else if(mid==j)
        {
            mid=i;
        }
    }    
    quick_sort(p,l,mid);
    quick_sort(p,mid+1,h);
}
