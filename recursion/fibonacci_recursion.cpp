#include<iostream>
using namespace std;

int fibo(int n);
int array[100] = {0};

int main()
{
	int n;
	cout<<"Enter the value of n : ";
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		array[i]=-1;
	}
	cout<<fibo(n);
}

int fibo(int n)
{
	if(n<=1)
	{
		array[n]=n;
		return n;
	}
	else
	{
		if(array[n-2]==-1)
		{
			array[n-2]=fibo(n-2);
		}
		if(array[n-1]==-1)
		{
			array[n-1]=fibo(n-1);
		}
		return array[n-1]+array[n-2];
	}
	
}