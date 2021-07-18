#include<iostream>
using namespace std;

void func1(int n);
void func2(int n);

int main()
{
	cout<<"Enter a number : ";
	int n;
	cin>>n;
	func1(n);
}

void func1(int n)
{
	if(n>0)
	{
		cout<<n<<" ";
		func2(n-1);
	}
}

void func2(int n)
{
	if(n>0)
	{
		cout<<n<<" ";
		func1(n/2);
	}
}