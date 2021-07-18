#include<iostream>
#include<stack>
using namespace std;
class node_t
{
    public:
        int data;
        node_t* left;
        node_t* right;
        node_t* parent;
};
class Heap
{
    private:
        node_t* root;
    public:
        Heap(){root=NULL;}
        void create_heap(int *m,int n);
        void preorder(node_t* p);
        node_t* get_root();
        void remove(node_t* p,int * x,int n);
};
class node
{
    public:
        node_t* data;
        node* next;
};
class queue
{
    private:
        node* front;
        node* rear;
    public:
        queue();
        void enqueue(node_t* x);
        node_t* dequeue();
        bool is_empty();
};
node_t* max(node_t* left,node_t* right);
queue::queue()
{
    front=NULL;
    rear=NULL;
}
void queue::enqueue(node_t* x)
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
node_t* queue::dequeue()
{
    node* p=front;
    node_t* x=p->data;
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
void Heap::create_heap(int *m,int n)
{
    stack<node_t*> s;
    queue q;
    node_t* t=new node_t;
    t->data=*(m+1);
    t->left=NULL;
    t->right=NULL;
    t->parent=NULL;
    root=t;
    s.push(t);
    q.enqueue(t);
    for(int i=1;2*i<=n;i++)
    {
        node_t* p=q.dequeue();
        int j=2*i;
        while(j<=((2*i)+1))
        {
            node_t* t=new node_t;
            t->data=*(m+j);
            t->left=NULL;
            t->right=NULL;
            t->parent=p;
            if(p->left==NULL)
            {
                p->left=t;
            }
            else
            {
                p->right=t;
            }
            s.push(t);
            q.enqueue(t);
            j++;
        }        
    }
    while(!q.is_empty())
    {
        q.dequeue();
    }
    while(!s.empty())
    {
        node_t* x=s.top();
        s.pop();
        while(x->parent!=NULL)
        {
            node_t* y=x->parent;
            if(x->data>y->data)
            {
                swap(x->data,y->data);
                x=y;
            }
            else
            {
                break;
            }
        }
    }
}
node_t* Heap::get_root()
{
    return root;
}
void Heap::preorder(node_t *p)
{
    if(p==NULL)
    {
        return;
    }
    cout<<p->data<<" ";
    preorder(p->left);
    preorder(p->right);
}


void Heap::remove(node_t* p,int * x,int n)
{
    stack<node_t*> s;
    queue q;
    q.enqueue(p);
    s.push(p);
    while(!q.is_empty())
    {
        node_t* k=q.dequeue();
        if(k->left!=NULL && k->right!=NULL)
        {
            s.push(k->left);
            s.push(k->right);
            q.enqueue(k->left);
            q.enqueue(k->right);
        }
        else if(k->left!=NULL)
        {
            s.push(k->left);
            q.enqueue(k->left);
        }
        else if(k->right!=NULL)
        {
            s.push(k->right);
            q.enqueue(k->right);
        }
        else
        {
            continue;
        }
    }
    int i=n-1;
    while(!s.empty())
    {
        node_t* m=p;
        node_t* k=s.top();
        s.pop();
        *(x+i)=p->data;
        i--;
        if(i<0)
        {
            break;
        }
        m->data=k->data;
        node_t* u=k->parent;
        if(u->left==k)
        {
            u->left=NULL;
        }
        else
        {
            u->right=NULL;
        }
        delete k;
        while(m->left!=NULL || m->right!=NULL)
        {
            node_t* comp=max(m->left,m->right);
            if(comp->data>m->data)
            {
                swap(m->data,comp->data);
                m=comp;
            }
            else
            {
                break;
            }
        }
    }
}


node_t* max(node_t* left,node_t* right)
{
    if(left==NULL)
    {
        return right;
    }
    if(right==NULL)
    {
        return left;
    }
    return left->data>right->data?left:right;
}
int main()
{
    cout<<"Enter the size of the array : ";
    int n;
    cin>>n;
    int *p=new int[n+1];
    cout<<"Enter "<<n<<" values : ";
    for(int i=0;i<=n;i++)
    {
        cin>>*(p+i);
    }
    Heap H;
    H.create_heap(p,n);
    node_t* root=H.get_root();
    cout<<"The preorder traversal of Heap is : ";
    H.preorder(root);
    H.remove(root,p,n);
    cout<<"The heap sort output is : ";
    for(int i=0;i<n;i++)
    {
        cout<<*(p+i)<<" ";
    }
}