#include<iostream>
using namespace std;
struct element
{
    int a;
    int b;
    int x;
};
struct sparse
{
    int m;
    int n;
    int num;
    struct element* p;
};
void create(struct sparse *s)
{
    cout<<"Enter the order of the matrix : ";
    cin>>s->m>>s->n;
    cout<<"Enter the number of non zero elements : ";
    cin>>s->num;
    s->p=new element[s->num];
    cout<<"Enter the row,column and value of "<<s->num<<" elements\n";
    for(int i=0;i<s->num;i++)
    {
        cin>>s->p[i].a>>s->p[i].b>>s->p[i].x;
    }
}
void display(struct sparse *s)
{
    int k=0;
    for(int i=0;i<s->m;i++)
    {
        for(int j=0;j<s->n;j++)
        {
            if(s->p[k].a==i && s->p[k].b==j)
            {
                cout<<s->p[k].x<<" ";
                k++;
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<"\n";
    }
}
int main()
{
    struct sparse s;
    create(&s);
    display(&s);
}