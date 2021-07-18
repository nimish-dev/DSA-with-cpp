#include<iostream>
using namespace std;

void TOH(int n,int A,int B,int C);

int main()
{
	int n;
	cout<<"Enter the number of disks : ";
	cin>>n;
	TOH(n,1,2,3);
}

void TOH(int n,int A,int B,int C)
{
	if(n>0)
	{
		TOH(n-1,A,C,B);
		cout<<"("<<A<<","<<C<<")\n";
		TOH(n-1,B,A,C);
	}
}