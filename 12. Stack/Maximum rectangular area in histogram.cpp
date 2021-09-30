#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<int> s;
 
    long long max_area = 0; 
    long long tp;  // To store top of stack
    long long area_with_top; 
                      
    long long i = 0;
    while (i < n)
    {
       
        if (s.empty() || arr[s.top()] <= arr[i])
            s.push(i++);
 
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top
 
            area_with_top = arr[tp] * (s.empty() ? i :
                                   i - s.top() - 1);
 
            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
     while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = arr[tp] * (s.empty() ? i :
                                i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends