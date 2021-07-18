#include<iostream>
using namespace std;
class symmetric
{
    private:
        int n;
        int **p;
    public:
        symmetric();
        void symm_check();
        void display();
};
symmetric::symmetric()
{
    cout<<"Enter the order of the matrix : ";
    cin>>n;
    p=new int*[n];
    for(int i=0;i<n;i++)
    {
        *p=new int[n];
    }
    int size=n*n;
    cout<<"Enter "<<size<<" elements for the matrix :\n";
    for(int i=0;i<n;i++)
    {
        cout<<"hello\n";
        for(int j=0;j<n;j++)
        {
            cin>>*(*(p+i)+j);
            cout<<*(*(p+i)+j)<<"\n";
        }
        cout<<"nimi\n";
    }
    cout<<"hello\n";
}

void symmetric::display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<*(*(p+i)+j)<<" ";
        }
        cout<<"\n";
    }
}
void symmetric::symm_check()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(*(*(p+i)+j)!=*(*(p+j)+i))
            {
                cout<<"The given matrix is not symmentric\n";
                exit;
            }
        }
    }
    cout<<"The given matrix is symmetric\n";
}

int main()
{
    symmetric s;
    cout<<"The given matrix is : \n";
    s.display();
    s.symm_check();
}