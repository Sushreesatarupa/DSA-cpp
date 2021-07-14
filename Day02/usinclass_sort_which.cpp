#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n)
    {
	    
        int i = -1, posn1=0, posn2=0, flag = 0, posn[n] = {0};
        while(++i<n)
        {
            int j = -1;
            while(++j<n)
            {
                if((arr[i]>arr[j] && j>i) || (arr[i]<arr[j] && j<i))
                {
                    if(flag == 0)
                    {
                        posn1 = i;
                        flag ++; 
                    }  
                    posn[i] += 1;
                    break;
                }        
                   
            }
            if(posn[i] == 0 && flag)
            {
                posn2 = i-1;
                break;
            }
            else if(i == n-1 && flag)
                posn2 = i;

        }
    
    return {posn1, posn2};
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}