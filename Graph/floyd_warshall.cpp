#include<iostream>
using namespace std;
#define I 32767
void floyd_warshall(int **A,int **B,int n);
int min(int x,int y);
int main()
{
    cout<<"Enter the number of node : ";
    int n;
    cin>>n;
    int **A=new int*[n+1];
    int **B=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        A[i]=new int[n+1];
        B[i]=new int[n+1];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==j)
            {
                B[i][j]=0;
                A[i][j]=I;
            }
            else
            {
                B[i][j]=I;
                A[i][j]=I;
            }
        }
    }
    cout<<"Enter the number of edges : ";
    int m;
    cin>>m;
    cout<<"Enter the details of edges as start,end and weight :\n";
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        B[x][y]=z;
    }
    floyd_warshall(A,B,n);
    cout<<"The final route is :\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void floyd_warshall(int **A,int **B,int n)
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                A[i][j]=min(B[i][j],B[i][k]+B[k][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                B[i][j]=A[i][j];
            }
        }
    }
}
int min(int x,int y)
{
    return x>y?y:x;
}