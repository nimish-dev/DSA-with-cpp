#include<iostream>
#include<string.h>
using namespace std;
void pallindrome(char str[],int len);
int main()
{
    char str[30];
    cout<<"Enter a string : ";
    cin>>str;
    int len=strlen(str);
    pallindrome(str,len);
}

void pallindrome(char str[],int len)
{
    for(int i=0,j=len-1;i<j;i++,j--)
    {
        if(str[i]!=str[j])
        {
            cout<<"The given string is not pallindrome\n";
            return;
        }
    }
    cout<<"The given string is pallindrome\n";
}