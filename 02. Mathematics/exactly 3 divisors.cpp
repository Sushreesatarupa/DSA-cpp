// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int exactly3Divisors(int N)
    {
        int ctr=0;
        for(int i=2;i<=sqrt(N);i++){
            if(isPrime(i))
                ctr++;
        }
        return ctr;
    }
    
    bool isPrime(int i){
        for(int j=2;j<=sqrt(i);j++)
                if (i%j==0)return false;
        return true;
    }
};

// { Driver Code Starts.


int main()
 {
    int T;
    
    //taking testcases
    cin>>T;
    while(T--)
    {
        int N;
        
        //taking N
        cin>>N;
        Solution ob;
        //calling function exactly3Divisors()
        cout<<ob.exactly3Divisors(N)<<endl;
    }
	return 0;
}  // } Driver Code Ends
