#include<iostream>
using namespace std;

float comb(int n,int r);
int fact(int n);

int main()
{
	cout<<"Enter the values of n and r : ";
	int n,r;
	cin>>n>>r;
	cout<<comb(n,r);
}

float comb(int n,int r)
{
	int f=fact(r);
	int prod=1;
	for(int i=0;i<r;i++)
	{
		prod*=(n-i);
	}
	return prod/(float)f;
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