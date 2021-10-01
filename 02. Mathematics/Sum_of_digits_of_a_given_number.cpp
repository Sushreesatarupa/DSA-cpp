#include <bits/stdc++.h>
using namespace std;

/*
    Author : Aarti Rathi
*/

int main()
{
    int n,sum=0;
    cout<<"Enter the number : ";
    cin>>n;
    while(n>0)
    {
        int r=n%10;
        sum+=r;
        n=n/10;
    }

    cout<<"Sum of digits of a given number is : "<<sum;

    return 0;
}


/* 

OUTPUT :

Enter the number : 1526
Sum of digits of a given number is : 14

*/