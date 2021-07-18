#include<iostream>
using namespace std;
class toeplitz
{
    private:
        int n;
        int size;
        int *p;
    public:
        toeplitz();
        void display();
};
toeplitz::toeplitz()
{
    cout<<"Enter the order of the matrix : ";
    cin>>n;
    size=(2*n)-1;
    p=new int[size];
    cout<<"Enter "<<size<<" elements for the matrix :\n";
    for(int i=0;i<size;i++)
    {
        cin>>*(p+i);
    }
}
void toeplitz::display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i-j)<=0)
            {
                cout<<*(p+j-i)<<" ";
            }
            else
            {
                cout<<*(p+n+i-j-1)<<" ";
            }
        }
        cout<<"\n";
    }
}
int main()
{
    toeplitz m;
    m.display();
}