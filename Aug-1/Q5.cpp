// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        
       long long q=0;
       int r=-1;
      bool sign=(dividend<0)^(divisor<0);
      dividend = abs(dividend);
      divisor  = abs(divisor);
      
       while(dividend>divisor<<++r);
       while (r>=0){
           q*=2;
           if(dividend>=divisor<<r){
               dividend-=divisor<<r;
               q++;
           }
           r--;
       }
       return (sign)?-q:q;
       
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}
  // } Driver Code Ends
