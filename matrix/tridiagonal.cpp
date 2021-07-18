#include<iostream>
using namespace std;
class tridiagonal
{
    private:
        int n;
        int size;
        int *p;
    public:
        tridiagonal();
        void display();
};
tridiagonal::tridiagonal()
{
    cout<<"Enter the order of the matrix : ";
    cin>>n;
    size=(3*n)-2;
    p=new int[size];
    cout<<"Enter "<<size<<" elements for the matrix :\n";
    for(int i=0;i<size;i++)
    {
        cin>>*(p+i);
    }
}
void tridiagonal::display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i-j)==0)
            {
                cout<<*(p+n+i-1)<<" ";
            }
            else if((i-j)==1)
            {
                cout<<*(p+i-1)<<" ";
            }
            else if((i-j)==-1)
            {
                cout<<*(p+i-1+(2*n))<<" ";
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
    tridiagonal m;
    m.display();
}