#include<iostream>
using namespace std;

float taylor(int x,int n);

int main()
{
	int x,n;
	cout<<"Enter x and n values : ";
	cin>>x>>n;
	cout<<taylor(x,n);
}

float taylor(int x,int n)
{
	static float s=1;
	if(n==1)
	{
		return s;
	}
	float y=x/(float)(n-1);
	y=y*s;
	s=y+1;
	return taylor(x,n-1);
}