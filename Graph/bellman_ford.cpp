#include<iostream>
using namespace std;
#define I 32767
void bellman_ford(int **edge,int *res,int n,int m,int source);
int main()
{
    cout<<"Enter the number of node : ";
    int n;
    cin>>n;
    cout<<"How many edges are there in the graph? \n";
    int m;
    cin>>m;
    int **edge=new int*[3];
    for(int i=0;i<3;i++)
    {
        edge[i]=new int[m];
    }
    cout<<"Enter the edge details as start,end and weight :\n";
    int k=0;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        edge[0][i]=x;
        edge[1][i]=y;
        edge[2][i]=z;
    }
    cout<<"Enter the source vertex : ";
    int source;
    cin>>source;
    int *res=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        if(i==source)
        {
            res[i]=0;
        }
        else
        {
            res[i]=I;
        }
    }    
    bellman_ford(edge,res,n,m,source);
}
void bellman_ford(int **edge,int *res,int n,int m,int source)
{
    for(int i=0;i<n-1;i++)
    {
        int count=0;
        for(int j=0;j<m;j++)
        {
            if((res[edge[0][j]]+edge[2][j])<res[edge[1][j]])
            {
                res[edge[1][j]]=res[edge[0][j]]+edge[2][j];
                count++;
            }
        }
        if(count==0)
        {
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<res[i]<<" ";
    }
}