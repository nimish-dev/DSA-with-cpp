//Program to implement insertion sort algorithm
//In insertion sort we start the comparision from the end
//We will shift the elements by one position which are greater than the inserting element
//We will stop when we find the element smaller than the inserting element
//Then we will insert the element there

//Header file inclusion part

#include<iostream>
using namespace std;

void insertion_sort(int *p,int n); //Function prototype declaration
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
    insertion_sort(p,n);   //Calling the function 
    cout<<"\nThe sorted array is : ";   //Printing the sorted output
    for(int i=0;i<n;i++)
    {
        cout<<*(p+i)<<" ";
    }
}

//Insertion sort function block
//To sort the unsorted array
//Here we start from the 2nd element in the array
//We will assume the first element to be in sorted position already
//We will compare the picked up element with all the previous elements
//If the picked up element is smaller then it's previous element then we will swap them 
//We will comtimue untill all the previous elements are compared
//Time complexity=O(n^2)
//No. of passes=(n-1)
//No. of comparisions=O(n^2)
//No. of swaps=O(n^2)
//The insertion sort technique is best suited to sort the linked list

void insertion_sort(int *p,int n)
{
    for(int i=1;i<n;i++)
    {
        int x=i;
        for(int j=i-1;j>=0;j--)
        {
            if(*(p+j)>*(p+x))
            {
                swap(*(p+j),*(p+x));
            }
            x=j;
        }
    }
}