//Program to implement polynomial using linked list

#include<iostream>
using namespace std;

//Node class
//It will contain three slots named coefficient,exponent and the next node pointer

class node
{
    public:
        int coeff;
        int exp;
        node* next;
};

//Poly class
//To declare the polynomial class with it's head node pointer as private entity

class poly
{
    private:
        node* head;
    public:
        poly(){head=NULL;}  //Constructor for the poly class
        void create();  //Create function for creation of the list
        int value();    //Value function to evaluate the polynomial with some base value
        ~poly(){}
};

int power(int x,int y); //Power function to calculate the exponentiation of the variable
node* newnode(int x,int y); //Function to create a newnode with some coefficient and exponent value

//Create function block
//Here we create the linked list which will contain the coefficient,exponent and the next node pointer

void poly::create()
{
    int n;
    cout<<"Enter the number of terms in the polynomial : ";
    cin>>n;
    cout<<"Start entering "<<n<<" terms as coeff and exponent :\n";
    head=new node;
    int x,y;
    cin>>x>>y;
    head->coeff=x;  //By default assignment of the head node
    head->exp=y;
    node* last;
    head->next=NULL;
    last=head;  //Uppdate the last node pointer to point to the last node in the list
    for(int i=1;i<n;i++)    //Start loop for other node's data except the head node
    {
        cin>>x>>y;
        node* t=newnode(x,y);   //Create the new node and store it's location in a temporary node pointer variable
        last->next=t;   //Update the last node next node pointer value
        last=t; //Update the last node value
    }
}

//Newnode function block
//It will take two argument as coefficient and exponent
//And insert then into a newly craeted node
//And return the node address back to the calling function

node* newnode(int x,int y)
{
    node* t=new node;
    t->coeff=x;
    t->exp=y;
    t->next=NULL;
    return t;
}

//Value function to evaluate the polynomial

int poly::value()
{
    int x;
    cout<<"Enter the base value for polynomial : ";
    cin>>x;
    node* p=head;   //Start the tracker from the head node and continue the calculations till it reaches the last node
    int res=0;
    while(p!=NULL)
    {
        int pow=power(x,p->exp);    //Get the result of the exponential function
        pow=pow*p->coeff;
        res+=pow;   //Then update the result value
        p=p->next;  //Update the next node pointer value
    }
    return res; //return the result to the calling function
}

//Power function block
//It calculates the exponential expression
//It takes two argument 
//One base and other exponent

int power(int x,int y)
{
    int prod=1;
    for(int i=0;i<y;i++)
    {
        prod*=x;
    }
    return prod;
}

//main function block

int main()
{
    poly p1;    //An object of polynomial class is created
    p1.create();    //Then the values are assigned to the list and the list is updated for the newly created object
    int res=p1.value(); //Getting the polynomial evaluation
    cout<<"The value of the polynomial is "<<res<<"\n";
}