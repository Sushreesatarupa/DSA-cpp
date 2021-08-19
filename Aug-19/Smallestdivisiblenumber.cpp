// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    long long getSmallestDivNum(long long n){
        // code here
        long long LCM=1;
        for(long long i=2;i<=n;i++){
            LCM= (LCM*i)/gcd(i,LCM);
        }return LCM;
    }
    long long gcd(long long a, long long b)
    {
      if (b == 0)
          return a;
      return gcd(b, a % b);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<< ob.getSmallestDivNum(n)<<endl;
    }
    return 0;
}  // 
