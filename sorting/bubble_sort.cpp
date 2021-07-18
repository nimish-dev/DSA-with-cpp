//Program to implement bubble sort algorithm

//Header file inclusion part

#include<iostream>
using namespace std;

void bubble_sort(int *p,int n); //Function prototype declaration

//Main function block

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
    bubble_sort(p,n);   //Calling the function 
    cout<<"\nThe sorted array is : ";   //Printing the sorted output
    for(int i=0;i<n;i++)
    {
        cout<<*(p+i)<<" ";
    }
}

//Bubble sort function block
//To sort the unsorted array
//Here we always start from the first element of the array and then subsequently compare two consecutive elements
//If the first element is greter than it's successor then swap the elements
//We will continue this process till (n-1) passes
//Where n=size of the array
//As here a for loop is present inside a while loop which will continue till n-1 passes
//So the time complexity=O(n^2)

void bubble_sort(int *p,int n)
{
    int k=0;
    int flag=0; //Flag is used to track the swap count
    while(k<n)
    {
        int i=0;    //Starting each time from the begining
        for(int j=1;j<n-k;j++)  //Comparing the elements next to each other 
        {
            if(*(p+i)>*(p+j))
            {
                swap(*(p+i),*(p+j));    //swapping the elements 
                flag=1;
            }
            i++;
        }
        if(flag==0) //If there is no swapping after the current comppletion of loop then the array is already sorted
        {
            break;
        }
        k++;    //Keeping the track of the passes
    }
}