#include<iostream>
using namespace std;

float taylor(int x,int n);
int exp(int m,int n);
int fact(int n);

int main()
{
	int x,n;
	cout<<"Enter x and n values : ";
	cin>>x>>n;
	cout<<taylor(x,n);
}

float taylor(int x,int n)
{
	if(n==1)
	{
		return 1;
	}
	int pow=exp(x,n-1);
	int factorial=fact(n-1);
	float res=pow/(float)factorial;
	return res+taylor(x,n-1);
}

int exp(int m,int n)
{
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