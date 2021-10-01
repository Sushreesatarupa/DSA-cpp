// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function for finding maximum AND value.
    int maxAND(int arr[], int N)
    {

        /*Time Complexity: O (32 * N)
          Space Complexity: O(1)
          Logic: For the given constraints, we construct the maximum AND answer from MSB to LSB
          if atleast 2 numbers have that bit set, then it will contribute to the maximum AND
        */

        int result = 0, cnt = 0, pattern = 0, mask;
        for (int i = 31; i >= 0; i--)
        {
            mask = 1 << i;
            pattern = (result | mask);
            cnt = 0;
            for (int j = 0; j < N; j++)
            {
                if ((pattern & arr[j]) == pattern)
                    cnt++;
            }

            if (cnt >= 2)
                result |= mask;
        }

        return result;
    }
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
        int arr[N];
        for(int i = 0 ; i < N; i++)
            cin>>arr[i];

        Solution ob;
        int ans = ob.maxAND(arr, N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
