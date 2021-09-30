#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
    int maximum=arr[0];
    int cnt=0;
    for(int i=0;i < n; i++){
        if(arr[i]>0){
            cnt++;
        }
        maximum=max(maximum,arr[i]);
    }
    if(!cnt){
        return maximum;
    }
	 
	int max_so_far = 0;
	int max_ending_here = 0;
	for (int i = 0; i < n; i++)
	{
    	max_ending_here = max_ending_here + arr[i];
    	if(max_ending_here < 0)
    	{
        	max_ending_here = 0;
    	}
    	if(max_so_far < max_ending_here)
    	{
        	max_so_far = max_ending_here;    
    	}
	}	
	return max_so_far;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends