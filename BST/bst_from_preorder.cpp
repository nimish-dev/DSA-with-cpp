#include<iostream>
#include<stack>
using namespace std;
class node_t
{
    public:
        int data;
        node_t* left;
        node_t * right;
};
class BST
{
    private:
        node_t* root;
    public:
        BST(){root=NULL;}
        void tree_formation(int q[],int n);
        node_t* get_root();
        void postorder(node_t* p);
        void inorder(node_t* p);
};
void BST::tree_formation(int q[],int n)
{
    node_t* t=new node_t;
    t->data=q[0];
    t->left=NULL;
    t->right=NULL;
    root=t;
    stack<node_t*> s;
    node_t* p=root;
    for(int i=1;i<n;)
    {
        if(q[i]<p->data)
        {
            node_t* t=new node_t;
            t->data=q[i];
            t->left=NULL;
            t->right=NULL;
            p->left=t;
            s.push(p);
            p=p->left;
            i++;
        }
        else if(q[i]>p->data)
        {
            if(!s.empty())
            {
                node_t* m=s.top();
                if(q[i]<m->data)
                {
                    node_t* t=new node_t;
                    t->data=q[i];
                    t->left=NULL;
                    t->right=NULL;
                    p->right=t;
                    p=p->right;
                    i++;
                }
                else
                {
                    p=s.top();
                    s.pop();
                }
            }
            else
            {
                node_t* t=new node_t;
                t->data=q[i];
                t->left=NULL;
                t->right=NULL;
                p->right=t;
                p=p->right;
                i++;
            }
        }
    }
    while(!s.empty())
    {
        s.pop();
    }
}
node_t* BST::get_root()
{
    return root;
}
void BST::postorder(node_t* p)
{
    if(p==NULL)
    {
        return;
    }
    postorder(p->left);
    postorder(p->right); 
    cout<<p->data<<" "; 
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
int main()
{
    BST B;
    cout<<"Enter the number of elements : ";
    int n;
    cin>>n;
    int* p=new int[n];
    cout<<"Enter the values in preorder : ";
    for(int i=0;i<n;i++)
    {
        cin>>*(p+i);
    }
    B.tree_formation(p,n);
    node_t* q=B.get_root();
    cout<<"\nThe postorder traversal of the tree is : ";
    B.postorder(q);
    cout<<"\nThe inorder traversal of the tree is : ";
    B.inorder(q);
}