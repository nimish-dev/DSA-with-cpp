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
class tree
{
    private:
        node_t* root;
    public:
        tree();
        void insert();
        void preorder(node_t* p);
        void inorder(node_t* p);
        void postorder(node_t* p);
        void preorder_interative();
        void inorder_interative();
        void postorder_interative();
        void level_order();
        int node_count(node_t* p);
        int height(node_t* p);
        int leaf_count(node_t* p);
        int one_child(node_t* p);
        int two_child(node_t* p);
        node_t* get_root();
        void destroy_tree(node_t* p);
};
tree::tree()
{
    root=NULL;
}
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
queue::queue()
{
    front=NULL;
    rear=NULL;
}
node_t* tree::get_root()
{
    return root;
}
void tree::insert()
{
    root=new node_t;
    cout<<"Enter the data : ";
    int x;
    cin>>x;
    root->data=x;
    root->left=NULL;
    root->right=NULL;
    queue q;
    q.enqueue(root);
    while(!q.is_empty())
    {
        node_t* p=q.dequeue();
        cout<<"Enter left child value of node value "<<p->data<<" : ";
        cin>>x;
        if(x!=-1)
        {
            node_t* t=new node_t;
            t->data=x;
            t->left=NULL;
            t->right=NULL;
            q.enqueue(t);
            p->left=t;
        }
        cout<<"Enter right child value of node value "<<p->data<<" : ";
        cin>>x;
        if(x!=-1)
        {
            node_t* t=new node_t;
            t->data=x;
            t->left=NULL;
            t->right=NULL;
            q.enqueue(t);
            p->right=t;
        }
    }
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
void tree::inorder(node_t* p)
{
    if(p==NULL)
    {
        return;
    }
    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);  
}
void tree::postorder(node_t* p)
{
    if(p==NULL)
    {
        return;
    }
    postorder(p->left);
    postorder(p->right); 
    cout<<p->data<<" "; 
}
void tree::preorder_interative()
{
    stack<node_t*> s;
    node_t* p=root;
    while((p!=NULL)||(!s.empty()))
    {
        if(p!=NULL)
        {
            cout<<p->data<<" ";
            s.push(p);
            p=p->left;
        }
        else
        {
            p=s.top();
            s.pop();
            p=p->right;
        }
    }
}
void tree::inorder_interative()
{
    stack<node_t*> s;
    node_t* p=root;
    while((p!=NULL)||(!s.empty()))
    {
        if(p!=NULL)
        {
            s.push(p);
            p=p->left;
        }
        else
        {
            p=s.top();
            s.pop();
            cout<<p->data<<" ";
            p=p->right;
        }
    }
}

void tree::postorder_interative()
{
    stack<intptr_t> s;
    node_t* p=root;
    intptr_t temp;
    while((p!=NULL)||(!s.empty()))
    {
        if(p!=NULL)
        {
            temp=reinterpret_cast<intptr_t>(p);
            s.emplace(temp);
            p=p->left;
        }
        else
        {
            temp=s.top();
            s.pop();
            if(temp>0)
            {
                s.push(-1*temp);
                p=reinterpret_cast<node_t*>(temp)->right;
            }
            else
            {
                cout<<reinterpret_cast<node_t*>(-1*temp)->data<<" ";
                p=NULL;
            }
        }
    }
}

void tree::level_order()
{
    queue q;
    q.enqueue(root);
    node_t* p;
    cout<<root->data<<" ";
    while(!q.is_empty())
    {
        p=q.dequeue();
        if(p->left!=NULL)
        {
            cout<<p->left->data<<" ";
            q.enqueue(p->left);
        }
        if(p->right!=NULL)
        {
            cout<<p->right->data<<" ";
            q.enqueue(p->right);
        }
    }
}
int tree::node_count(node_t* p)
{
    if(p!=NULL)
    {
        int x=node_count(p->left);
        int y=node_count(p->right);
        return x+y+1;
    }
    return 0;
}
int tree::height(node_t* p)
{
    if(p!=NULL)
    {
        int x=height(p->left);
        int y=height(p->right);
        return (x>y)?(x+1):(y+1);
    }
    return 0;
}

int tree::leaf_count(node_t* p)
{
    if(p!=NULL)
    {
        int x=leaf_count(p->left); 
        int y=leaf_count(p->right);
        return (p->left==NULL && p->right==NULL)?x+y+1:x+y;
    }
    return 0;
}

int tree::one_child(node_t* p)
{
    if(p!=NULL)
    {
        int x=one_child(p->left);
        int y=one_child(p->right);
        return ((p->left!=NULL && p->right==NULL) || (p->left==NULL && p->right!=NULL))?x+y+1:x+y;
    }
    return 0;
}

int tree::two_child(node_t* p)
{
    if(p!=NULL)
    {
        int x=two_child(p->left);
        int y=two_child(p->right);
        return (p->left!=NULL && p->right!=NULL)?x+y+1:x+y; 
    }
    return 0;
}

void tree::destroy_tree(node_t* p)
{
    if(p!=NULL)
    {
        destroy_tree(p->left);
        destroy_tree(p->right);
        delete p;
    }
}
int main()
{
    tree T;
    T.insert();
    node_t* p=T.get_root();
    cout<<"\nThe preorder traversal of the tree is : ";
    T.preorder(p);
    cout<<"\nThe inorder traversal of the tree is : ";
    T.inorder(p);
    cout<<"\nThe postorder traversal of the tree is : ";
    T.postorder(p);
    cout<<"\nThe preorder traversal of the tree iteratively is : ";
    T.preorder_interative();
    cout<<"\nThe inorder traversal of the tree iteratively is : ";
    T.inorder_interative();
    cout<<"\nThe postorder traversal of the tree iteratively is : ";
    T.postorder_interative();
    cout<<"\nThe level order traversal of the tree is : ";
    T.level_order();
    cout<<"\nTotal number of nodes in the tree is : "<<T.node_count(p)<<"\n";
    cout<<"The height of the tree is : "<<T.height(p)-1<<"\n";
    cout<<"The number of leaf nodes in tree is : "<<T.leaf_count(p)<<"\n";
    cout<<"The number of nodes with one child is : "<<T.one_child(p)<<"\n";
    cout<<"The number of nodes with two child is : "<<T.two_child(p)<<"\n";
    T.destroy_tree(p);
}