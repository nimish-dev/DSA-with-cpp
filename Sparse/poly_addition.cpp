#include<iostream>
using namespace std;
class term
{
    public:
        int coeff;
        int exp;
};
class poly:public term
{
    private:
        int n;
        term* p;
    public:
        poly();
        poly(int x);
        int get_n();
        int poly_evaluation();
        void add(poly *p1,poly *p2,poly *p3);
};
int power(int x,int y);
poly::poly()
{
    cout<<"Enter the number of non-zero terms : ";
    cin>>n;
    p=new term[n];
    cout<<"Enter the coefficient and exponent of each term :\n";
    for(int i=0;i<n;i++)
    {
        cin>>p[i].coeff>>p[i].exp;
    }
}
poly::poly(int x)
{
    this->n=x;
    p=new term[n];
}
int poly::get_n()
{
    return n;
}
void poly::add(poly *p1,poly *p2,poly *p3)
{
    int i,j,k=0;
    for(i=0,j=0;((i<p1->n)&&(j<p2->n));)
    {
        if(p1->p[i].exp > p2->p[i].exp)
        {
            p3->p[k].coeff=p1->p[i].coeff;
            p3->p[k].exp=p1->p[i].exp;
            i++;
            k++;
        }
        else if(p1->p[i].exp < p2->p[j].exp)
        {
            p3->p[k].coeff=p2->p[j].coeff;
            p3->p[k].exp=p2->p[j].exp;
            j++;
            k++;
        }
        else
        {
            p3->p[k].exp=p1->p[i].exp;
            p3->p[k].coeff=p1->p[i].coeff+p2->p[j].coeff;
            k++;
            i++;
            j++;
        }
    }
    while(i<p1->n)
    {
        p3->p[k].coeff=p1->p[i].coeff;
        p3->p[k].exp=p1->p[i].exp;
        i++;
        k++;
    }
    while(j<p2->n)
    {
        p3->p[k].coeff=p2->p[j].coeff;
        p3->p[k].exp=p2->p[j].exp;
        j++;
        k++;
    }
    p3->n=k;
}
int poly::poly_evaluation()
{
    cout<<"Enter the value of x : ";
    int x;
    cin>>x;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int pow=power(x,p[i].exp);
        res=res+(pow*p[i].coeff);
    }
    return res;
}
int power(int x,int y)
{
    int prod=1;
    for(int i=0;i<y;i++)
    {
        prod=prod*x;
    }
    return prod;
}

int main()
{
    poly p1;
    poly p2;
    int n=p1.get_n()+p2.get_n();
    poly p3(n);
    p3.add(&p1,&p2,&p3);
    int res=p3.poly_evaluation();
    cout<<"The polynomial is evaluated into "<<res<<" \n";
}