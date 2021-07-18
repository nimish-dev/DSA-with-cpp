//Program to implement all the functions for the linked list

//Library file inclusion

#include<iostream>
using namespace std;

//Node class declaration with two components of data and next node pointer

class node
{
    public:
        int data;
        node* next;
};

//Linked_list class declaration with one private element of head node pointer and several functions to implement some tasks

class linked_list
{
    private:
        node* head;
    public:
        linked_list(){head=NULL;}
        linked_list(int A[],int n);
        node* get_head();
        void display();
        void recursive_display(node* p);
        int count();
        int sum();
        int max();
        int min();
        bool search(int key);
        void insert(int pos,int x);
        void delete_element(int pos);
        bool is_sorted();
        void remove_duplicates();
        void reverse();
};

node* newnode(int x);   //Function to create newnode 

//Constructor to create and initialize linked list with some values

linked_list::linked_list(int A[],int n)
{
    node* last,*t;
    head=new node;
    head->data=A[0];;
    head->next=NULL;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=newnode(A[i]);
        last->next=t;
        last=t;
    }
}

//Functions to create a newnode

node* newnode(int x)
{
    node* p=new node;   //Create new node using new operator in heap
    p->data=x;  //Enter the data into newly created node
    p->next=NULL;   //Initialize the next node pointer of newly created node to NULL
    return p;   //Return the pointer to the new node
}

//Class function to get the head node address for further implementation of recursive display

node* linked_list::get_head()
{
    return head;
}

//class function to display the contents of the list

void linked_list::display()
{
    node* p=head;   //Start from the head node
    while(p!=NULL)  //Continue till the node pointer is not NULL
    {
        cout<<p->data<<" "; //Print the data
        p=p->next;  //Update the next node tracker
    }
    cout<<"\n";
}

//class function to display the list contents recursively

void linked_list::recursive_display(node* p)
{
    linked_list l1; //Create a temporary list
    if(p!=NULL) //Till the node pointer not reaches NULL value
    {
        cout<<p->data<<" "; //Print the data value at that node
        l1.recursive_display(p->next);  //Call the function recursively
    }
    else
    {
        return;
    }
}

//Class function to count the number of nodes in the list

int linked_list::count()
{
    node* p=head;   //Start from the head node
    int cnt=0;  //Initialize the count value to 0
    while(p!=NULL)  //Continue till the node tracker is not NULL
    {
        cnt++;  //Increase the count
        p=p->next;  //Update the node tracker
    }
    return cnt; //Return the final count of the list
}

//Class sum function to get the sum of all the elements of the list

int linked_list::sum()
{
    node* p=head;   //Start from the head node
    int add=0;  //Initialize the add variable to 0 to store the total sum value
    while(p!=NULL)
    {
        add=add+p->data;    //For every iteration add the node data value to the add variable
        p=p->next;  //Update the next node tracker
    }
    return add; //Return the fiinal added value
}

//Class function to find the maximum element in the list

int linked_list::max()
{
    node* p=head;
    int max=p->data;    //Initialize the max variable to the head node data value
    while(p!=NULL)
    {
        if(max<p->data) //If some other node data is greater than the max then update max to that data value
        {
            max=p->data;
        }
        p=p->next;  //Then update the next node pointer
    }
    return max; //Return the max value
}

//Class function to find the maximum element in the list

int linked_list::min()
{
    node* p=head;
    int min=p->data;    //Initialize the min variable to the head node data value
    while(p!=NULL)
    {
        if(min>p->data) //If some other node data is lesser than the min then update min to that data value
        {
            min=p->data;
        }
        p=p->next;  //Then update the next node pointer
    }
    return min; //Return the max value
}

//Search class function to search for a given element in the list if it is present or not

bool linked_list::search(int key)
{
    node* p=head;
    while(true)
    {
        if(p==NULL) //If it is empty list or the end of the list arrived then return the false for searching
        {
            return false;
        }
        else if(p->data==key)   //If the element is found at any position return true
        {
            return true;
        }
        p=p->next;  //Update the next node tracker
    }
}

//Insert class function to insert an element at any particular position

void linked_list::insert(int pos,int x)
{
    if(pos==0)  //If the inserting position is as the head node then---
    {
        node* t=newnode(x);
        t->next=head;
        head=t; //Just update the head node pointer and return back to the calling function
        return;
    }
    node* p=head;
    for(int i=0;i<pos-1;i++)    //For some other position of insertion traverse to the node just before taht position
    {
        p=p->next;
    }
    node* t=newnode(x); //Create new node
    t->next=p->next;    //Update the next node pointer of newly created node to the next node pointer of already existion node which we traced
    p->next=t;  //Then update the last traced node with the address of the newly created node
}

//Delete element function to delete a node from the list at a parrticular position

void linked_list::delete_element(int pos)
{
    if(pos==0)  //If the deleting position is head node
    {
        node* p=head;
        head=p->next;   //then just make the head node pointer skip the first node and directly point to the second node
        delete p;   //Delete the first node
        return; //Return back to the calling function so that the control doesn't go further
    }
    node* p=head;   //If the deleting position is something else
    node* q=NULL;   //Then we will use two node pointers to track the current and one back node so that when that position is reached then the two required nodes could be updated appropriately
    for(int i=0;i<pos-1 && p!=NULL;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    delete p;   //Delete the node present at the cureent node pointer
}

//Is the list sorted or not function
//here we will traverse all the node keeping track of the data of the previous node and compare it with the current node
//If the previous node data value is less than the current node data value for every node then the list is sorted elese the list if not sorted

bool linked_list::is_sorted()
{
    node* p=head;
    int x=-65536;   //Initialize the variable with lowest value possible
    while(p->next!=NULL)
    {
        if(x>p->data)   //If for any node the previous node value is greater than the current node value the return false
        {
            return false;
        }
        x=p->data;  //Else update trhe node pointers accordingly
        p=p->next;
    }
    return true;
}

//remove duplicates function 
//To remove the duplicated elements in the list
//Here we will track every node along with the previous node
//If both values are same it indicates that the elements are duplicated
//Then skip the current node to the next node in the list

void linked_list::remove_duplicates()
{
    node* p=head;
    node* q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)    //If the two data values are not equal then just update the node tracker and it's tail
        {
            p=q;
            q=q->next;
        }
        else    //If the data values of two nodes are same
        {
            p->next=q->next;    //Skip the current node by making the tail node point directly to the next node   
            delete q;
            q=p->next;
        }
    }
}

//Reverse function block
//To reverse the node of the list not just elements
//To reverse the list we will use theree node pointers
//To point to previous,cuurent and next node
//Then change the nod epointer values accordingly

void linked_list::reverse()
{
    node* p=head;   //Initialize the current node to the head node
    node* q=NULL;   //Initialize the previous node pointer with NULL
    node* r=NULL;   //Initialize the next node pointer with NULL too
    while(p!=NULL)
    {
        r=q;    //Keep updating all the node pointers
        q=p;
        p=p->next;
        q->next=r;
    }
    q->next=r;
    head=q;
}

//main function block
//To create the linked list class object
//And call the appropriate functions at appropriate time with appropriate arguments

int main()
{
    cout<<"Enter the number of elements : ";
    int n;
    cin>>n;
    int *A=new int[n];  //Dynamic creation of array to hold the values to be inserted in the linked list
    cout<<"Enter "<<n<<" elements for the list : \n";
    for(int i=0;i<n;i++)
    {
        cin>>*(A+i);
    }
    linked_list list1(A,n); //Creating linked list object with two arguments,array and it's size
    list1.display();
    node* p=list1.get_head();
    list1.recursive_display(p);
    int count=list1.count();
    cout<<"\nThe total number of elements in the list is "<<count<<".\n";
    int sum=list1.sum();
    cout<<"Sum of elements for this linked list is "<<sum<<".\n";
    int max=list1.max();
    int min=list1.min();
    cout<<"The maximum value is "<<max<<" & The minimum value is "<<min<<".\n";
    int key;
    cout<<"Enter key to be searched for : ";
    cin>>key;
    bool res=list1.search(key);
    if(res)
    {
        cout<<"The key is found in the list.\n";
    }
    else
    {
        cout<<"The key is not found in the list.\n";
    }
    cout<<"Enter the data and position where you want to insert : ";
    int pos,x;
    cin>>x>>pos;
    list1.insert(pos,x);
    cout<<"\nList after insertion of an element :\n";
    list1.display();
    cout<<"Enter the position you want to remove from the list : ";
    cin>>pos;
    list1.delete_element(pos);
    cout<<"The elements in the list after deleteion of an element : ";
    list1.display();
    res=list1.is_sorted();
    if(res)
    {
        cout<<"The given list is sorted\n";
    }
    else
    {
        cout<<"The given list is unsorted\n";
    }
    list1.remove_duplicates();
    cout<<"The list after the removal of dupllicate elements : ";
    list1.display();
    list1.reverse();
    cout<<"The list after reversal is : ";
    list1.display();
}