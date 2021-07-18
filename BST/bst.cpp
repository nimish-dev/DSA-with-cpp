#include<iostream>
#include<stack>
using namespace std;
class node_t
{
    public:
        int data;
        node_t* left;
        node_t* right;
};
class BST
{
    private:
        node_t* root;
    public:
        BST(){root=NULL;}
        void create(int q[],int n);
        void inorder(node_t* p);
        void insert(int x);
        node_t* get_root();
        node_t* search(int x);
        node_t* remove(node_t* p,int x);
        int height(node_t *p) ;
        node_t* inpre(node_t* p);
        node_t* insucc(node_t* p);
};
void node_add(node_t* p,int x);
void BST::create(int q[],int n)
{
    node_t* t=new node_t;
    t->data=q[0];
    t->left=NULL;
    t->right=NULL;
    root=t;
    for(int i=1;i<n;i++)
    {
        node_add(root,q[i]);
    }
}

void node_add(node_t* p,int x)
{
    node_t* t=new node_t;
    t->data=x;
    t->left=NULL;
    t->right=NULL;
    while(1)
    {
        if(x>p->data)
        {
            if(p->right==NULL)
            {
                p->right=t;
                return;
            }
            else
            {
                p=p->right;
            }
        }
        else if(x<p->data)
        {
            if(p->left==NULL)
            {
                p->left=t;
                return;
            }
            else
            {
                p=p->left;
            }
        }
    }
}
node_t* BST::get_root()
{
    return root;
}
void BST::inorder(node_t* p)
{
    if(p==NULL)
    {
        return;
    }
    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);  
}
void BST::insert(int x)
{
    node_add(root,x);
}
node_t* BST::search(int x)
{
    node_t* p=root;
    while(p!=NULL)
    {
        if(p->data==x)
        {
            return p;
        }
        else if(p->data>x)
        {
            p=p->left;
        }
        else
        {
            p=p->right;
        }
    }
    return NULL;
}
node_t* BST::remove(node_t* p,int x)
{
    if(p==NULL)
    {
        return NULL;
    }
    if(p->left==NULL && p->right==NULL)
    {
        if(p==root)
        {
            root=NULL;
        }
        delete p;
        return NULL;
    }

    node_t* q;
    if(x>p->data)
    {
        p->right=remove(p->right,x);
    }
    else if(p->data>x)
    {
        p->left=remove(p->left,x);
    }
    else
    {
        if(height(p->left)>height(p->right))
        {
            q=inpre(p->left);
            p->data=q->data;
            p->left=remove(p->left,q->data);
        }
        else
        {
            q=insucc(p->right);
            p->data=q->data;
            p->right=remove(p->right,q->data);
        }
    }
    return p;
}
int BST::height(node_t *p) 
{
    int x;
    int y;
    if (p == nullptr){
        return 0;
    }
    x = height(p->left);
    y = height(p->right);
    return x > y ? x + 1 : y + 1;
}
node_t* BST::inpre(node_t* p)
{
    while(p!=NULL && p->right!=NULL)
    {
        p=p->right;
    }
    return p;
}
node_t* BST::insucc(node_t* p)
{
    while(p!=NULL && p->left!=NULL)
    {
        p=p->left;
    }
    return p;
}
int main()
{
    BST B;
    cout<<"Enter the number of elements : ";
    int n;
    cin>>n;
    int* p=new int[n];
    cout<<"Enter the values : ";
    for(int i=0;i<n;i++)
    {
        cin>>*(p+i);
    }
    B.create(p,n);
    node_t* q=B.get_root();
    cout<<"\nThe inorder traversal of the tree is : ";
    B.inorder(q);
    int x;
    cout<<"\nEnter the value you want to insert into the tree : ";
    cin>>x;
    B.insert(x);
    cout<<"\nThe inorder traversal of the tree is : ";
    B.inorder(q);
    cout<<"\nEnter the key value you want to search into the tree : ";
    cin>>x;
    node_t* res=B.search(x);
    cout<<"The key is found at "<<res<<" in the tree\n";
    cout<<"\nEnter the value you want to delete from the tree : ";
    cin>>x;
    node_t* m=B.remove(q,x);
    cout<<"\nThe inorder traversal of the tree is : ";
    B.inorder(q);
}