//hacktoberfest2021

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int kadane(int arr[], int num){
        int currentSum = arr[0];
        int maxSum = arr[0];
        for(int i=1; i<num; i++){
            currentSum = max(arr[i], currentSum+arr[i]);
            maxSum=max(maxSum, currentSum);
        }
        return maxSum;
    }
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int wrapsum;
        int nonWrapsum;
        
        nonWrapsum=kadane(arr, num);
        int totalSum=0;
        for(int i=0; i<num;i++){
            totalSum+=arr[i];
            arr[i]=-arr[i];
        }
        wrapsum=totalSum+kadane(arr, num);
        //cout<<max(wrapsum, nonWrapsum);
        if(wrapsum == 0)
          wrapsum = INT_MIN;
        
        return max(wrapsum, nonWrapsum);
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
