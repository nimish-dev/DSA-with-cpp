#include<iostream>
#include<string.h>
using namespace std;
void permutation(char str[],int len,int k);
int main()
{
    char str[30];
    cout<<"Enter a string in small letters only : ";
    cin>>str;
    int len=strlen(str);
    permutation(str,len,0);
}

void permutation(char str[],int len,int k)
{
    static int A[20]={0};
    static char res[20];
    if(str[k]=='\0')
    {
        res[k]='\0';
        cout<<res<<"\n";
    }
    else
    {
        for(int i=0;str[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                res[k]=str[i];
                A[i]=1;
                permutation(str,len,k+1);
                A[i]=0;
            }
        }
    }
}