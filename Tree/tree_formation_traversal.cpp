#include<iostream>
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
        tree(){root=NULL;}
        node_t* tree_formation(int pre[],int in[],int start,int end);
        void postorder(node_t* p);
};
int searchInorder(int inArray[], int inStart, int inEnd, int data);
node_t* tree::tree_formation(int pre[],int in[],int start,int end)
{
    static int preindex=0;
    if(start>end)
    {
        return NULL;
    }
    node_t* node=new node_t;
    node->data=pre[preindex++];
    node->left=NULL;
    node->right=NULL;
    int index=searchInorder(in,start,end,node->data);
    node->left=tree_formation(pre,in,start,index-1);
    node->right=tree_formation(pre,in,index+1,end);
    return node;
}
int searchInorder(int in[], int start, int end, int data)
{
    for (int i=start; i<=end; i++){
        if (in[i] == data){
            return i;
        }
    }
    return -1;
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
int main()
{
    tree T;
    int preorder[] = {1,2,4,5,3,6,7};
    int inorder[] = {4,2,5,1,6,3,7};
    int size=sizeof(inorder)/sizeof(inorder[0]);
    node_t* p=T.tree_formation(preorder,inorder,0,size-1);
    cout<<"\nThe postorder traversal of the tree is : ";
    T.postorder(p);
}