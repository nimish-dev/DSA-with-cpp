#include<iostream>
using namespace std;

int exp(int m,int n);

int main()
{
	int m,n;
	cout<<"Enter m,n values : ";
	cin>>m>>n;
	cout<<exp(m,n);
}

int exp(int m,int n)
{
	// if (n>0)
	// {
	// 	return m*exp(m,n-1);
	// }
	// else
	// {
	// 	return 1;
	// }

	if(n==0)
	{
		return 1;
	}
	if(n%2==0)
	{
		return exp(m*m,n/2);
	}
	else
	{
		return m*exp(m*m,n/2);
	}
}