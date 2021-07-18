#include<iostream>
using namespace std;
#define I 32767
void dijkstra(int **cost,int *A,int *B,int n,int m,int source,int *trace);
int min(int *B,int* trace,int n);
void copy(int *A,int *B,int n);
void update(int *A,int *B,int n,int x);
int main()
{
    cout<<"Enter the number of node : ";
    int n;
    cin>>n;
    int **cost=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        cost[i]=new int[n+1];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==j)
            {
                cost[i][j]=0;
            }
            else
            {
                cost[i][j]=I;
            }
        }
    }
    cout<<"How many edges are there in the graph?\n";
    int m;
    cin>>m;
    cout<<"Enter the details of edges as start,end and weight :\n";
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        cost[x][y]=z;
    }
    cout<<"Enter the source : ";
    int source;
    cin>>source;
    int *A=new int[n];
    int *B=new int[n];
    int *trace=new int [n];
    for(int i=0;i<=n;i++)
    {
        A[i]=I;
        B[i]=cost[source][i];
        trace[i]=0;
    }
    dijkstra(cost,A,B,n,m,source,trace);
    cout<<"The path from source is : \n";
    for(int i=1;i<=n;i++)
    {
        cout<<source<<" --> "<<i<<" = "<<A[i]<<"\n";
    }
}
void dijkstra(int **cost,int *A,int *B,int n,int m,int source,int *trace)
{
    trace[source]=1;
    int x=cost[source][source];
    for(int i=0;i<n;i++)
    {
        update(A,B,n,x);
        int index=min(B,trace,n);
        x=B[index];
        copy(A,B,n);
        for(int j=1;j<=n;j++)
        {
            B[j]=cost[index][j];
        }
    }
}
int min(int *B,int* trace,int n)
{
    int y=I;
    int index=0;
    for(int i=1;i<=n;i++)
    {
        if(trace[i]==0)
        {
            if(y>B[i])
            {
                y=B[i];
                index=i;
            }
        }
    }
    trace[index]=1;
    return index;
}
void copy(int *A,int *B,int n)
{
    for(int i=1;i<=n;i++)
    {
        A[i]=B[i];
    }
}
void update(int *A,int *B,int n,int x)
{
    for(int j=1;j<=n;j++)
    {
        if((x+B[j])<A[j])
        {
            B[j]=x+B[j];
        }
        else
        {
            B[j]=A[j];
        }
    }
}