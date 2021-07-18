#include<iostream>
using namespace std;
int str_len(char str[]);
void change_case(char str[]);
void vowels_consonants(char str[]);
void reverse_str(char str[],int len);
int main()
{
    char str[30];
    cout<<"Enter a string : ";
    gets(str);
    int len=str_len(str);
    cout<<"Length of the string is "<<len<<"\n";
    change_case(str);
    vowels_consonants(str);
    reverse_str(str,len);
}

int str_len(char str[])
{
    int len=0;
    for(int i=0;str[i]!='\0';i++)
    {
        len++;
    }
    return len;
}

void change_case(char str[])
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>64 && str[i]<91)
        {
            str[i]=str[i]+32;
        }
        else if(str[i]>96 && str[i]<123)
        {
            str[i]=str[i]-32;
        }
    }
    cout<<"String after the case change is : "<<str<<"\n";
}

void vowels_consonants(char str[])
{
    int vcount=0;
    int ccount=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if((str[i]>64 && str[i]<91) || (str[i]>96 && str[i]<123))
        {
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
            {
                vcount++;
            }
            else
            {
                ccount++;;
            }
        }        
    }
    cout<<"In the string :\n Vowels = "<<vcount<<"\nConsonants = "<<ccount<<"\n";
}

void reverse_str(char str[],int len)
{
    for(int i=0,j=len-1;i<j;i++,j--)
    {
        swap(str[i],str[j]);
    }
    cout<<"The reversed string is : "<<str<<"\n";
}