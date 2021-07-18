#include<iostream>
using namespace std;

int fact(int n);

int main()
{
	cout<<"Enter a number : ";
	int n;
	cin>>n;
	cout<<fact(n);
}

int fact(int n)
{
	if(n==0 || n==1)
	{
		return 1;
	}
	else
	{
		return fact(n-1)*n;
	}
}