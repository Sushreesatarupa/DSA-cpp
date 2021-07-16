#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i=-1, n, p1, m, mi;
    mi = p1 = 0;
    cin>>n;
    int a[n];
    while(++i<n) 
    {
        cin>>a[i];
        if(a[i] == 1)
           mi++;
    }   
    int j = 0;
    for(i=0; i<n; i++)
    {
        m = 0;
        if(a[i] == 0)
          while(a[i] == 0)
          {
              m++;
              i++;
          }  
       
        if(m>p1)
           p1 = m;

    }   
    cout<<p1 + mi<<endl;

}