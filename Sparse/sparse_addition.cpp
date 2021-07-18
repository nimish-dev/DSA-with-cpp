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
void add(struct sparse *s1,struct sparse *s2,struct sparse *s)
{
    s->num=s1->num+s1->num;
    s->p=new element[s->num];
    s->m=s1->m;
    s->n=s1->n;
    if((s1->m!=s2->m) || (s1->n!=s2->n))
    {
        cout<<"The addition is not possible\n";
        return;
    }
    else
    {
        int k=0,i,j;
        for(i=0,j=0;((i<s1->num)&&(j<s2->num));)
        {
            if(s1->p[i].a < s2->p[j].a)
            {
                s->p[k].a=s1->p[i].a;
                s->p[k].b=s1->p[i].b;
                s->p[k].x=s1->p[i].x;
                k++;
                i++;
            }
            else if(s1->p[i].a > s2->p[j].a)
            {
                s->p[k].a=s2->p[j].a;
                s->p[k].b=s2->p[j].b;
                s->p[k].x=s2->p[j].x;
                k++;
                j++;
            }
            else
            {
                if(s1->p[i].b < s2->p[j].b)
                {
                    s->p[k].a=s1->p[i].a;
                    s->p[k].b=s1->p[i].b;
                    s->p[k].x=s1->p[i].x;
                    k++;
                    i++;
                }
                else if(s1->p[i].b > s2->p[j].b)
                {
                    s->p[k].a=s2->p[j].a;
                    s->p[k].b=s2->p[j].b;
                    s->p[k].x=s2->p[j].x;
                    k++;
                    j++;
                }
                else
                {
                    s->p[k].a=s1->p[i].a;
                    s->p[k].b=s1->p[i].b;
                    s->p[k].x=s1->p[i].x + s2->p[j].x;
                    i++;
                    j++;
                    k++;
                }
            }
        }
        while(i<s1->num)
        {
            s->p[k++]=s1->p[i++];
        }
        while(j<s2->num)
        {
            s->p[k++]=s2->p[j++];
        }
        s->num=k;
    }
}
int main()
{
    struct sparse A;
    struct sparse B;
    struct sparse C;
    create(&A);
    create(&B);
    add(&A,&B,&C);
    cout<<"\nMatrix A is :\n";
    display(&A);
    cout<<"\nMatrix B is :\n";
    display(&B);
    cout<<"\nMatrix C is :\n";
    display(&C);
}