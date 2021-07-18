#include<iostream>
using namespace std;
void merge(int *p,int l,int mid,int h);
void merge_sort(int *p,int l,int h);
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
    merge_sort(p,0,n-1);
    cout<<"The sorted array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<*(p+i)<<" ";
    }
}
void merge_sort(int *p,int l,int h)
{
    if(l==h)
    {
        return;
    }
    int mid;
    while(l<h)
    {
        mid=(l+h)/2;
        merge_sort(p,l,mid);
        merge_sort(p,mid+1,h);
        merge(p,l,mid,h);
        l=h;
    }
}
void merge(int *p,int l,int mid,int h)
{
    int i=l;
    int j=mid+1;
    int k=0;
    int r[100];
    while((i<=mid)&&(j<=h))
    {
        if(*(p+i)>*(p+j))
        {
            r[k]=*(p+j);
            j++;
            k++;
        }
        else if(*(p+i)<*(p+j))
        {
            r[k]=*(p+i);
            i++;
            k++;
        }
    }
    while(j<=h)
    {
        r[k]=*(p+j);
        j++;
        k++;
    }
    while(i<=mid)
    {
        r[k]=*(p+i);
        i++;
        k++;
    }
    k=0;
    for(int i=l;i<=h;i++)
    {
        *(p+i)=r[k];
        k++;
    }
}