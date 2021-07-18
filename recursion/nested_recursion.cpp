#include<iostream>
using namespace std;

int func(int n);

int main()
{
	cout<<"Enter a number : ";
	int n;
	cin>>n;
	cout<<func(n);
}

int func(int n)
{
	if(n>100)
	{
		return n-10;
	}
	else
	{
		return func(func(n+11));
	}
}