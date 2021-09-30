// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S)
    {
       int maxLen = 0;
       int len = 0;
       stack<int> s;
       s.push(-1);
       int i= 0;
       
       
       while(i < S.length())
       {
           if(S[i] == '(')
           {
              s.push(i);
              i++;
           }
           else
           {
               if(!s.empty())
               {
                   s.pop();
               }
               
               if(!s.empty())
               {
                   maxLen = max(maxLen,i - s.top());
               }
               else
                  s.push(i);
               i++;
           }
       }
       return maxLen;
        
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends