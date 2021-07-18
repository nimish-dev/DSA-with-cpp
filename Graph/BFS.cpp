#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node* next;
};
class queue
{
    private:
        node* front;
        node* rear;
    public:
        queue();
        void enqueue(int x);
        int dequeue();
        bool is_empty();
};
queue::queue()
{
    front=NULL;
    rear=NULL;
}
void queue::enqueue(int x)
{
    node* t=new node;
    t->data=x;
    t->next=NULL;
    if(front==NULL)
    {
        front=rear=t;
    }
    else
    {
        rear->next=t;
        rear=t;
    }
}
int queue::dequeue()
{
    node* p=front;
    int x=p->data;
    front=p->next;
    delete p;
    return x;
}
bool queue::is_empty()
{
    if(front==NULL)
    {
        return true;
    }
    return false;
}
void BFS(int **p,int n);
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
    BFS(p,n);
}
void BFS(int **p,int n)
{
    int i;
    int j;
    queue q;
    int *visited=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        *(visited+i)=0;
    }
    i=1;
    cout<<i<<" ";
    visited[i]=1;
    q.enqueue(i);
    while(!q.is_empty())
    {
        int u=q.dequeue();
        for(int v=1;v<=n;v++)
        {
            if(p[u][v]==1 && visited[v]==0)
            {
                cout<<v<<" ";
                visited[v]=1;
                q.enqueue(v);
            }
        }
    }
}