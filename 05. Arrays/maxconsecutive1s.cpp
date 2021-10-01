#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m)
    {
        int n0[n];
        int i = 0, k = 0;
        while(i < n)
        {
            if(arr[i] == 0)
            {
                n0[k] = i;
                k++;
            }        
               
            i++;   
        }
        
        //cout<<n0[0]<<" ";
        int j = 0, x, max = 0;
        if(k<=m)
        {
            return n;
        }
        
        else if(k == 0)
            return n;
            
        else
        {
            for(x = 0; x+m<=k; x++)
            {
                if(x == 0 && x+m < k)
                   j = n0[m];
                else if(x+m == k)
                   j = n-n0[x-1]-1;
                else
                   j = n0[x+m] - n0[x-1] - 1;
                //cout<<j<<" ";
                if(j>max)
                  max = j;
            }
            
            return max;
               
        }
    }  
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
} 