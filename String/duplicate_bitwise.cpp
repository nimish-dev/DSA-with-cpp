#include<iostream>
#include<string.h>
using namespace std;
void duplicate(char str[],int len);
int main()
{
    char str[30];
    cout<<"Enter a string in small letters only : ";
    cin>>str;
    int len=strlen(str);
    duplicate(str,len);
}

void duplicate(char str[],int len)
{
    int h=0,x=0;
    for(int i=0;str[i]!='\0';i++)
    {
        x=1;
        x=x<<(str[i]-97);
        if((x & h)>0)
        {
            cout<<str[i]<<" is repeated\n";
        }
        else
        {
            h=x | h;
        }
    }
}