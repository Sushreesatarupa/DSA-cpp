#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i=-1, n, lmax = 1;
    cin>>n;
    int a[n];
    while(++i<n)
        cin>>a[i];

    i = 0; int posr = 0, posn = 0;   
    while(i<n-1)
    {
        while(i<n-1 && a[i]<a[i+1])
           i++; //gives posn of end of ascent
        while(i<n-1 && a[i]>a[i+1])
        {
            if(i<n-1 && a[i]>a[i+1])
               posn = i+1;
            i++;//gives posn of end of descent
        }
        lmax = max(lmax, i - posr + 1);
        posr = posn;
           
    }
    cout<<lmax<<endl;
}