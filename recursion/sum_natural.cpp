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
	if(n==0)
	{
		return 0;
	}
	return func(n-1)+n;
}