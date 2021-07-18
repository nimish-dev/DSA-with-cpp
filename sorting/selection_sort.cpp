//Program to implement selection sort algorithm


//Header file inclusion part

#include<iostream>
using namespace std;

void selection_sort(int *p,int n); //Function prototype declaration
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
    selection_sort(p,n);   //Calling the function 
    cout<<"\nThe sorted array is : ";   //Printing the sorted output
    for(int i=0;i<n;i++)
    {
        cout<<*(p+i)<<" ";
    }
}
void selection_sort(int *p,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int k=i;
        for(int j=i;j<n;j++)
        {
            if(*(p+j)<*(p+k))
            {
                k=j;
            }
        }
        swap(*(p+i),*(p+k));
    }
}