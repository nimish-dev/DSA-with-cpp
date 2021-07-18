#include<iostream>
using namespace std;
class matrix
{
    private:
        int n;
        int* A=new int[n];
    public:
        matrix();
        void display();
};

matrix :: matrix(void)
{
    cout<<"Enter the order of the matrix : ";
    cin>>n;
    cout<<"Enter "<<n<<" elements for the matrix : \n";
    for(int i=0;i<n;i++)
    {
        cin>>*(A+i);
    }
}
void matrix :: display(void)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                cout<<*(A+i)<<" ";
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
    matrix m;
    m.display();
}