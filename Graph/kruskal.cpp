#include<iostream>
using namespace std;
void kruskal(int **edge,int *set,int *included,int **path,int m,int n);
int min(int **edge,int m,int n,int *set,int *included);
int find(int u,int *set);
void inclusion(int u,int *set,int v);
void print(int **path,int n);
void weight(int **path,int n);
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
            p[i][j]=-1;
        }
    }
    cout<<"How many edges you want to enter in the graph : ";
    int m;
    cin>>m;
    cout<<"Enter "<<m<<" details as starting and ending node and the weight : \n";
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        p[x][y]=z;
        p[y][x]=z;
    }
    int **edge=new int*[3];
    for(int i=0;i<m;i++)
    {
        edge[i]=new int[m];
    }
    int k=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(p[i][j]!=-1)
            {
                edge[0][k]=i;
                edge[1][k]=j;
                edge[2][k]=p[i][j];
                k++;
            }
        }
    }
    int *set=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        set[i]=-1;
    }
    int *included=new int[m];
    for(int i=0;i<m;i++)
    {
        included[i]=0;
    }
    int **path=new int*[3];
    for(int i=0;i<3;i++)
    {
        path[i]=new int[n-1];
    }
    kruskal(edge,set,included,path,m,n);
    print(path,n);
    weight(path,n);
}
void kruskal(int **edge,int *set,int *included,int **path,int m,int n)
{
    int i=0;
    while(i<n-1)
    {
        int index=min(edge,m,n,set,included);
        if(index>=0)
        {
            path[0][i]=edge[0][index];
            path[1][i]=edge[1][index];
            path[2][i]=edge[2][index];
            i++;
        }
        else
        {
            continue;
        }
    }
}
int min(int **edge,int m,int n,int *set,int *included)
{
    int mini=32767;
    int u=0;
    for(int j=0;j<m;j++)
    {
        if((mini>edge[2][j])&&(included[j]==0))
        {
            mini=edge[2][j];
            u=j;
        }
    }
    int x=find(edge[0][u],set);
    int y=find(edge[1][u],set);
    if(x!=y)
    {
        inclusion(x,set,y);
        included[u]=1;
        return u;
    }
    else
    {
        included[u]=1;
        return -1;
    }
}
int find(int u,int *set)
{
    while(set[u]>0)
    {
        u=set[u];
    }
    return u;
}
void inclusion(int u,int *set,int v)
{
    if(set[u]<set[v])
    {
        set[u]=set[u]+set[v];
        set[v]=u;
    }
    else
    {
        set[v]=set[u]+set[v];
        set[u]=v;
    }
}
void print(int **path,int n)
{
    cout<<"The kruskal's algorithm path is :\n";
    for(int i=0;i<n-1;i++)
    {
        cout<<"( "<<path[0][i]<<" , "<<path[1][i]<<" ) ";
    }
}
void weight(int **path,int n)
{
    cout<<"\nThe total weight of kruskal's algorithm is : ";
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
        sum+=path[2][i];
    }
    cout<<sum<<"\n";
}