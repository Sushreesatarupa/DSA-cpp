// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
   //Function to return the number of set bits 
    int setBits(int N) {
        int cnt = 0;
        while(N > 0) {
            if(N % 2 == 1)
                cnt++;
            N = N >> 1;
        }
        return cnt;
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
  // } Driver Code Ends
