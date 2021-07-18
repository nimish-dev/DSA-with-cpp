#include<iostream>
#include<string.h>
using namespace std;
void anagram(char str1[],char str2[],int len1,int len2);
int main()
{
    char str1[30],str2[30];
    cout<<"Enter first string in small letters only : ";
    cin>>str1;
    cout<<"Enter second string in small letters only : ";
    cin>>str2;
    int len1=strlen(str1);
    int len2=strlen(str2);
    anagram(str1,str2,len1,len2);
}

void anagram(char str1[],char str2[],int len1,int len2)
{
    int arr[27]={0};
    if(len1!=len2)
    {
        cout<<"The given strings are not anagram\n";
        return;
    }
    for(int i=0;str1[i]!='\0';i++)
    {
        arr[str1[i]-97]=1;
    }
    for(int i=0;str2[i]!='\0';i++)
    {
        if(arr[str2[i]-97]==0)
        {
            cout<<"The given strings are not anagram\n";
            return;
        }
    }
    cout<<"The given strings are anagram\n";
}