#include<iostream>
using namespace std;
class node_t
{
    public:
        node_t* left;
        int data;
        int height;
        node_t* right;
};
class tree
{
    private:
        node_t* root;
    public:
        tree(){root=NULL;}
        node_t* get_root(); 
        node_t* create(node_t* p,int x); 
        int Height(node_t* p); 
        int balance_factor(node_t* p);  
        node_t* LLRotation(node_t* p); 
        void preorder(node_t* p);
        void new_node(int* p,int n);
        node_t* LRRotation(node_t* p); 
        node_t* RRRotation(node_t* p); 
        node_t* RLRotation(node_t* p); 
};


node_t* tree::get_root()
{
    return root;
}
void tree::new_node(int *p,int n)
{
    node_t* t=new node_t;
    t->data=*p;
    t->left=NULL;
    t->right=NULL;
    t->height=1;
    root=t;
    for(int i=1;i<n;i++)
    {
        root=create(root,*(p+i));
    }
}
node_t* tree::create(node_t* p,int x)
{
    if(p==NULL)
    {
        node_t* t=new node_t;
        t->data=x;
        t->left=NULL;
        t->right=NULL;
        t->height=1;
        return t;
    }
    if(x<p->data)
    {
        p->left=create(p->left,x);
    }
    else
    {
        p->right=create(p->right,x);
    }
    p->height=Height(p);
    if(balance_factor(p)==2 && balance_factor(p->left)==1)
    {
        return LLRotation(p);
    }
    else if(balance_factor(p)==2 && balance_factor(p->left)==-1)
    {
        return LRRotation(p);
    }
    else if(balance_factor(p)==-2 && balance_factor(p->right)==-1)
    {
        return RRRotation(p);
    }
    else if(balance_factor(p)==-2 && balance_factor(p->right)==1)
    {
        return RLRotation(p);
    }
    return p;
}
int tree::Height(node_t* p)
{
    int hl=p && p->left?p->left->height:0;
    int hr=p && p->right?p->right->height:0;
    return hl>hr?hl+1:hr+1;
}
int tree::balance_factor(node_t* p)
{
    int hl=p && p->left?p->left->height:0;
    int hr=p && p->right?p->right->height:0;
    return hl-hr;
}
node_t* tree::LLRotation(node_t* p)
{
    cout<<"LL Rotation\n";
    node_t* pl=p->left;
    node_t* plr=pl->right;
    pl->right=p;
    p->left=plr;
    p->height=Height(p);
    pl->height=Height(pl);
    if(p==root)
    {
        root=pl;
    }
    return pl;
}
node_t* tree::LRRotation(node_t* p)
{
    cout<<"LR Rotation\n";
    node_t* pl=p->left;
    node_t* plr=pl->right;
    pl->right=plr->left;
    p->left=plr->right;
    plr->left=pl;
    plr->right=p;
    p->height=Height(p);
    pl->height=Height(pl);
    plr->height=Height(plr);
    if(p==root)
    {
        root=plr;
    }
    return plr;
}
node_t* tree::RRRotation(node_t* p)
{
    cout<<"RR Rotation\n";
    node_t* pl=p->right;
    node_t* plr=pl->left;
    pl->left=p;
    p->right=plr;
    p->height=Height(p);
    pl->height=Height(pl);
    if(p==root)
    {
        root=pl;
    }
    return pl;
}
node_t* tree::RLRotation(node_t* p)
{
    cout<<"RL Rotation\n";
    node_t* pl=p->right;
    node_t* plr=pl->left;
    p->right=plr->left;
    pl->left=plr->right;
    plr->left=p;
    plr->right=pl;
    p->height=Height(p);
    pl->height=Height(pl);
    plr->height=Height(plr);
    if(p==root)
    {
        root=plr;
    }
    return plr;
}
void tree::preorder(node_t* p)
{
    if(p==NULL)
    {
        return;
    }
    cout<<p->data<<" ";
    preorder(p->left);
    preorder(p->right);
}
int main()
{
    tree T;
    cout<<"How many elements you want to insert : ";
    int n;
    cin>>n;
    cout<<"Enter "<<n<<" elements : ";
    int *p=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>*(p+i);
    }
    T.new_node(p,n);
    cout<<"Preorder is : ";
    node_t* root=T.get_root();
    T.preorder(root);
}