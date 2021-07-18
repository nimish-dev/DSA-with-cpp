//Program to represent the sparse matrix using linked list

#include<iostream>
using namespace std;

//Class node definition
//It contains the data,column number and the next node pointer

class node
{
    public:
        int data;
        int col;
        node* next;
};

//class Sparse definition
//It contains the head node pointer in private area

class sparse
{
    private:
        node* head;
    public:
        sparse(){head=NULL;}    //Constructor part of the class
        node* create(); //Function to create the list
        void display(node *p,int n);    //Function to display the list creted at each row
};

node* newnode(int x,int y); //Newnode function definition to crete newnode

//Create function block
//It will crete a list for each row whenever it is called
//It will return the address of the head node back to the calling function

node* sparse::create()
{
    cout<<"Enter the number of elements you want to enter : ";
    int n;
    cin>>n;
    cout<<"Enter "<<n<<" values of data and column number : \n";
    node* last=NULL;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        node* t=newnode(x,y);
        if(head==NULL)
        {
            head=t;
            last=head;
        }
        else
        {
            last->next=t;
            last=t;
        }
    }
    return head;
}

//newnode function block
//To create a new node in the heap section
//insert the data,column number into the node
//And the next node pointer is by default set to NULL

node* newnode(int x,int y)
{
    node* t=new node;
    t->data=x;
    t->col=y;
    t->next=NULL;
    return t;
}

//Display function block
//To display the list creted for each row of the matrix
//It will run for the total column number of times
//Whenver the column number matches with the column entry of the corresponding node we will print the data of that node
//Else we will print 0 

void sparse::display(node* p,int n)
{
    for(int i=0;i<n;i++)
    {
        if(p==NULL)
        {
            cout<<"0 ";
        }
        else if(p->col==i)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        else if(p->col!=i)
        {
            cout<<"0 ";
        }
        else
        {
            cout<<"0 ";
        }
    }
    cout<<"\n";
}

//main function block
//To create the class objects
//Call the required function at appropriate times

int  main()
{
    cout<<"Enter the order of the matrix  : ";
    int m,n;
    cin>>m>>n;
    node* A[m];
    for(int i=0;i<m;i++)
    {
        sparse p;
        A[i]=p.create();
    }
    cout<<"The sparse matrix is :\n";
    for(int i=0;i<m;i++)
    {
        sparse p;
        p.display(A[i],n);
    }
}