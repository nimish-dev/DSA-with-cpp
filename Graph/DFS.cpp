#include<iostream>
#include<stack>
using namespace std;
void DFS(int **p,int n,int *q,int u);
int main()
{
    cout<<"Enter the number of nodes in the graph : ";
    int n;
    cin>>n;
    int **p=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        p[i]=new int[n+1];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            p[i][j]=0;
        }
    }
    cout<<"How many values you want to enter in the graph : ";
    int m;
    cin>>m;
    cout<<"Enter "<<m<<" details as starting and ending node : \n";
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        p[x][y]=1;
        p[y][x]=1;
    }
    int *visited=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        *(visited+i)=0;
    }
    cout<<"DFS representation is : ";
    DFS(p,n,visited,5);
}
void DFS(int **p,int n,int *q,int u)
{
    cout<<u<<" ";
    q[u]=1;
    for(int v=1;v<=n;v++)
    {
        if(p[u][v]==1 && q[v]==0)
        {
            DFS(p,n,q,v);
        }
    }
}