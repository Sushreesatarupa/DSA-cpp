#include <bits/stdc++.h>
using namespace std;

int numTrees(int n) {
          vector<int>arr(n+1,0);
        arr[0]=arr[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
             arr[i]+=arr[j-1]*arr[i-j];
            }
        }
        
        return arr[n];
    }

int main()
{
  int n;
  cin>>n;
  cout<<numTrees(n);

    return 0;
}