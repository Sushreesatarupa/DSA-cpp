#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long size=ceil(sqrt(n));
        if(n>=size*size-size+1)cout<<size<<" "<<size*size-n+1<<endl;
        else
            cout << n - (size * size - size + 1 - (size - 1)) + 1<<" "<<size<<endl;
    }
}
