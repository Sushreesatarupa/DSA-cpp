#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i=-1, n, pos = -1, p = 0;
    cin>>n;
    int a[n];
    while(++i<n)
    {
        cin>>a[i];
        if(a[i] > a[i-1] && i>0)
            pos = i-1;
        if(a[i]>a[p]) 
           p = i;   
    }  
    
    if(pos == -1)
      for(i = 0; i<n/2; i++)
      {
          int temp = a[i];
          a[i] = a[n-i-1];
          a[n-1-i] = temp;
      } 
    else
    {
        
        for(i = pos+1; i<n; i++)
            if(a[i]>a[pos] && a[i]<a[p])
                p = i;    
                 
        int temp = a[pos];
        a[pos] = a[p];
        a[p] = temp;


        for(i = pos+1; i<(n+pos+1)/2; i++)
        {
            int temp = a[i];
            a[i] = a[n-i];
            a[n-i] = temp;
        }

    }
    for(i=0; i<n; i++)
        cout<<a[i]<<" ";
    
}