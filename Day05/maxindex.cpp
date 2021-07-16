#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i=-1, j, n, p1 = 0, p2;
    cin>>n;
    int a[n];
    while(++i<n)
        cin>>a[i];
    i = -1; j = n;

    while(++i<n/2 && --j>=n/2)
        if(a[i]<a[j])
        {
            p1=i; p2=j;
        }
        
    i = p1; j = p2;
    while(i-->=0)
        if(a[i]<a[p2])
           p1 = i;
    
    while(++j<n)
        if(a[p1]<a[j])
           p2 = j;

    cout<<p2-p1<<endl;

    
}
