// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*
        We traverse n from right to left, hence we right shift it (right shifting divides by 2)
        and we build up the result from left to right, hence we left shift it by 1 place --> multipying by 2 
    */
    unsigned int reverseBits(unsigned int n)
    {
        //code here
       unsigned int result = 0;
       while(n)
       {
           result <<= 1;
           if( n & 1)  // If the current MSB of n is set, then set the LSB of result
                result ^= 1; //XORing with 1, sets the LSB to 1, since 0 ^ 1 = 1
            n >>= 1;
       }

       return result;
    }

    /* Method 2
        unsigned int reverseBits(unsigned int n) {
            //reverse by storing the bits in a 32 length integer array
            vector<int>v(32,0);
            int i = 0;
            while(n>0)
            {
                v[i] = (n%2);
                i++;
                n /= 2;
            }
            uint32_t ans = 0;
            //Traverse this array in reverse and add the corresponding power to ans
            for(int i=31;i>=0;i--)
            {
                ans += v[i] * (1 << (31-i));
            }
            return ans;
        }
        */
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.reverseBits(N);
        cout << cnt << endl;
    }
    return 0;
}
// } Driver Code Ends
