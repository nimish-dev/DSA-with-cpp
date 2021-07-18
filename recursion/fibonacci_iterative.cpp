#include<iostream>
using namespace std;

int fibo(int n);

int main()
{
	int n;
	cout<<"Enter x and n values : ";
	cin>>n;
	cout<<fibo(n);
}

int fibo(int n)
{
	int f1=0;
	int f2=1;
	for(int i=0;i<n-1;i++)
	{
		int temp=f1+f2;
		f1=f2;
		f2=temp;
	}
	return f2;
}