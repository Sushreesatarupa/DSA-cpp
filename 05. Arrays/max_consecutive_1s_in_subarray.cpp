//max 1s in sub array
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m)
    {
        int n0[n]; //stores indices of 0 in array
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
        
        int j = 0, x, max = 0;
        if(k<=m) //number of 0s present <= max flips allowed
        {
            return n; //length of array, since all 0s can be flipped
        }
        
        else if(k == 0)
            return n;
            
        else
        {
            for(x = 0; x+m<=k; x++) //logically flipping consecutive m 0s in array 
            {
                //ex - {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}
                if(x == 0 && x+m < k)
                   j = n0[m]; //intially  = 5, all elements before 3rd 0
                else if(x+m == k)
                   j = n-n0[x-1]-1; //from end of array to the next element from 3rd last 0
                else
                   j = n0[x+m] - n0[x-1] - 1; //length between (x-1)th 0 and (x+m)th 0
              
                if(j>max) //j is length of consecutive 1s after logical flipping of consecutive m 0s
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
