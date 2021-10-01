//Required Libraries For execution
#include<iostream>
#include<string.h>
using namespace std;

//Funtion to reverse the string
int rev_string(string S)
{
    if( S.length() == 0 )// length() return length of string and as it becomes 0 it will 
    {
        return 0;
    }
    else{
        rev_string(S.substr(1));// substr() function return the sub string of string on which it is applied it has mainly two parameter as starting and ending point (if ending not given it will take remaning whole string)
    }
        
    cout<< S[0]; //It Will print starting character of each sub-string
}

//Main Program
int main()
{
    string S;
    cout<<"Enter some string to reverse it ::";
    cin>>S;
    rev_string(S);
    return 0;
}
