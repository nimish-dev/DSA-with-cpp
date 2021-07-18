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
        int poly_evaluation();

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
    poly p;
    int res=p.poly_evaluation();
    cout<<"The polynomial is evaluated into "<<res<<" \n";
}