#include<iostream>
using namespace std;
void prim(int **p,int n,int **path,int *near);
void min(int **p,int n,int **path,int *near);
int min(int **p,int x,int y,int z,int m);
void min(int **p,int *near,int **path,int n,int index);
int weight(int **p,int **path,int n);
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
            p[i][j]=32767;
        }
    }
    cout<<"How many values you want to enter in the graph : ";
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
    int **path=new int*[2];
    for(int i=0;i<2;i++)
    {
        path[i]=new int[n-1];
    }
    int *near=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        *(near+i)=-1;
    }
    
    prim(p,n,path,near);
    cout<<"The prim's path is : \n";
    for(int i=0;i<n-1;i++)
    {
        cout<<"("<<path[0][i]<<","<<path[1][i]<<") ";
    }
    cout<<"\n The total weight of prim's path is : "<<weight(p,path,n)<<"\n";
}
void prim(int **p,int n,int **path,int *near)
{
    min(p,n,path,near);
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(near[j]!=0)
            {
                near[j]=min(p,j,path[0][i-1],path[1][i-1],near[j]);
            }
        }
        min(p,near,path,n,i);
    }
}
void min(int **p,int n,int **path,int *near)
{
    int mini=p[1][1];
    int u=1,v=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(mini>p[i][j])
            {
                mini=p[i][j];
                u=i;
                v=j;
            }
        }
    }
    path[0][0]=u;
    path[1][0]=v;
    near[u]=0;
    near[v]=0;
}
int min(int **p,int x,int y,int z,int m)
{
    if(m==-1)
    {
        return (p[x][y]<p[x][z])?y:z;
    }
    if(p[x][y]<p[x][z])
    {
        if(p[x][y]<p[x][m])
        {
            return y;
        }
        return m;
    }
    else
    {
        if(p[x][z]<p[x][m])
        {
            return z;
        }
        return m;
    }
    return m;
}
void min(int **p,int *near,int **path,int n,int index)
{
    int mini=32767;
    int u=1;
    int v=1;
    for(int i=1;i<=n;i++)
    {
        if(near[i]!=0)
        {
            if(p[i][near[i]]<mini)
            {
                mini=p[i][near[i]];
                u=i;
                v=near[i];
            }
        }
    }
    path[0][index]=u;
    path[1][index]=v;
    near[u]=0;
}
int weight(int **p,int **path,int n)
{
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
        sum+=p[path[0][i]][path[1][i]];
    }
    return sum;
}