// This is a program to find the frequency of the repeated elements in an array

// Header file inclusion
#include <iostream>
using namespace std;

// Function Definition
void duplicate_sorted_freq(int arr[], int n);

// Main function is starting here
int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int *arr = new int[n]; //Creating an array dynamically
    cout << "\nEnter " << n << " elements in any order: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    duplicate_sorted_freq(arr, n); //Calling the function to show the frequency of repeated elements
}

// Function to find the frequency of the repeated elements is starting here
void duplicate_sorted_freq(int arr[], int n)
{
    int max = arr[0]; //Initializing the max variable with the first element

    //Loop to find out the maximum element in the array
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int *res = new int[max]{0}; //Initializing another array dynamically to store the frequency of each and every element

    //Loop to iterate over array and increase the frequency on it's every occurance
    for (int i = 0; i < n; i++)
    {
        res[arr[i] - 1]++;
    }
    cout << "The repeated elements are :\n";
    for (int i = 0; i < max; i++)
    {
        if (res[i] > 1)
        {
            cout << i + 1 << "---" << res[i] << "\n";
        }
    }
}