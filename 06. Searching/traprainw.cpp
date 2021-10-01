#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i=-1, n, pos = 0, por = 0, rain = 0, j;
    cin>>n;
    int a[n];
    while(++i<n)
    {
        cin>>a[i];
    } 
    i = 0;
    while(i<n-1)
    {
        while(i<n-1 && a[i + 1]<a[i])
            i++;
         
        while(i<n-1 && a[i+1]>a[i])
        {
            if(a[i+2]<a[i+1] || i+1 == n-1)
            {
                por = i+1;   
                for(j = pos+1; j<por; j++)
                    rain += (a[pos]<a[por])?a[pos]-a[j] : a[por] - a[j];
                
                pos = por;   
            }
            i++;
        }   
    }  
    cout<<rain<<endl; 
}