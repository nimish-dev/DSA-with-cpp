//Program to implement the addition of two sparse matrices using linked list storage pattern

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
        sparse(){head=NULL;}    //Construnctor of the class
        node* create(); //Crete function definition
        node* add(node* p,node* q); //Add function definition to add two matrices
        void display(node *p,int n);    //Display function definition to display the matrices
};

node* newnode(int x,int y); //Newnode function defintion

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

//Add function block
//To add two matrices
//Here we are adding two seperate linked lists
//Each list represent the elements correspoinding to one row
//Whenever the column number of two matches then it's data value gets added
//Else whichever is less in column number will be copies into the new list

node* sparse::add(node* p,node* q)
{
    node* last=NULL;
    while((p!=NULL)&&(q!=NULL))
    {
        if(p->col==q->col)
        {
            node* t=newnode(p->data+q->data,p->col);
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
            p=p->next;
            q=q->next;
        }
        else if(p->col>q->col)
        {
            node* t=newnode(q->data,q->col);
            if(head==NULL)
            {
                head=t;
                last=t;
            }
            else
            {
                last->next=t;
                last=t;
            }
            q=q->next;
        }
        else if(p->col<q->col)
        {
            node* t=newnode(p->data,p->col);
            if(head==NULL)
            {
                head=t;
                last=t;
            }
            else
            {
                last->next=t;
                last=t;
            }
            p=p->next;
        }
    }
    while(p!=NULL)
    {
        node* t=newnode(p->data,p->col);
        if(head==NULL)
        {
            head=t;
            last=t;
        }
        else
        {
            last->next=t;
            last=t;
        }
        p=p->next;
    }
    while(q!=NULL)
    {
        node* t=newnode(q->data,q->col);
        if(head==NULL)
        {
            head=t;
            last=t;
        }
        else
        {
            last->next=t;
            last=t;
        }
        q=q->next;
    }
    return head;
}

//main function block
//To create the class objects
//Call the required function at appropriate times

int  main()
{
    cout<<"Enter the order of the matrix  A: ";
    int ma,na;
    cin>>ma>>na;
    node* A[ma];
    for(int i=0;i<ma;i++)
    {
        sparse p;
        A[i]=p.create();
    }
    cout<<"Enter the order of the matrix  B: ";
    int mb,nb;
    cin>>mb>>nb;
    node* B[mb];
    for(int i=0;i<mb;i++)
    {
        sparse p;
        B[i]=p.create();
    }
    node* C[ma];
    if((ma!=mb)||(na!=nb))
    {
        cout<<"Matrix addition is not possible\n";
    }
    else
    {
        for(int i=0;i<ma;i++)
        {
            sparse p;
            C[i]=p.add(A[i],B[i]);  //Calling add function to add the two list corresponding to the same row in two different matrices
        }
    }
    cout<<"Matrix A is :\n";
    for(int i=0;i<ma;i++)
    {
        sparse p;
        p.display(A[i],na);
    }
    cout<<"Matrix B is :\n";
    for(int i=0;i<mb;i++)
    {
        sparse p;
        p.display(B[i],nb);
    }
    cout<<"Matrix C=A+B is :\n";
    for(int i=0;i<ma;i++)
    {
        sparse p;
        p.display(C[i],na);
    }
}