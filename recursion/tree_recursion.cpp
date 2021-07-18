#include<iostream>
using namespace std;

void func(int n);

int main()
{
	cout<<"Enter the number : ";
	int n;
	cin>>n;
	func(n);
}

void func(int n)
{
	if(n>0)
	{
		cout<<n<<" ";
		func(n-1);
		func(n-1);
	}
}