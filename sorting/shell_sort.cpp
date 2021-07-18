#include<iostream>
using namespace std;
void shell_sort(int *p,int n);
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
    shell_sort(p,n);
    cout<<"The sorted array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<*(p+i)<<" ";
    }
}
void shell_sort(int *p,int n)
{
    int gap=n/2;
    while(gap>0)
    {
        int i=0;
        int j=i+gap;
        while(j<n)
        {
            if(*(p+i)>*(p+j))
            {
                swap(*(p+i),*(p+j));
            }
            i++;
                j++;
        }
        i--;
        j--;
        while(i>=0)
        {
            if(*(p+i)>*(p+j))
            {
                swap(*(p+i),*(p+j));
            }
            i--;
            j--;
        }
        gap=gap/2;
    }
}