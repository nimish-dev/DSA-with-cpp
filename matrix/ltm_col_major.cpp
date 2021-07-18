#include<iostream>
using namespace std;
int size_calc(int n);
class LTM
{
    private:
        int n;
        int size;
        int* A=new int[size];
    public:
        LTM();
        void display();
};
LTM::LTM(void)
{
    cout<<"Enter the order of the matrix : ";
    cin>>n;
    size=size_calc(n);
    cout<<"Enter "<<size<<" elements for the matrix : \n";
    for(int i=0;i<size;i++)
    {
        cin>>*(A+i);
    }
}
int size_calc(int n)
{
    return n*(n+1)/2;
}
void LTM::display(void)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<j)
            {
                cout<<"0 ";
            }
            else
            {
                int p=(((2*n)-j+1)*j/2)+(i-j);
                cout<<*(A+p)<<" ";
            }
        }
        cout<<"\n";
    }
}
int main()
{
    LTM m;
    m.display();
}