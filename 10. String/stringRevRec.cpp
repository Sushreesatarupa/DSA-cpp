#include<bits/stdc++.h>
using namespace std;

string reverseString(string s)
{
    //base case
    if(s.length()==0)
    {
        return "";
    }
    
    return reverseString(s.substr(1))+s[0];//recursive function 
}

int main()
{
    string s;
    cout<<"Enter the string to be reversed ";
    getline(cin,s);

    cout<<"Original string is "<<s<<endl; //string before reversal

    string r = reverseString(s);
    cout<<"Reversed string is "<<r<<endl; //reversed string

    return 0;
}