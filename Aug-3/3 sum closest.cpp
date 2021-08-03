#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



//User function Template for C++
class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        //Sort the array
        sort(A,A+N);
       
       //initializing the closest sum and difference
	     int closestSum = 0, diff=INT_MAX;
      
	//Find out the closest sum
	for(int i=0;i<N;i++)
	{
		int leftIndex=i+1;
		int rightIndex= N-1;
    
    //Loop to cover all elements
		while(leftIndex < rightIndex)
		{
      //Sum of 3 elements
			int tempSum = A[leftIndex]+ A[rightIndex]+ A[i];
      
      //Difference between target and tempSum
			int targetTempDifference= abs(tempSum - X);
      
      //To check if a closer Sum can be found
			if(targetTempDifference < diff)
			{
				closestSum= tempSum;
				diff= targetTempDifference;
			}
      
      //If tempSum is greater, it means that sum needs to be decreased
			if(tempSum> X)
			{
				rightIndex --;
			}
      
      //If tempSum is smaller, it means that sum needs to be increased
			else
			{
				leftIndex ++;
			}
      
      //If they are equal, it means that the  sum is the ultimate closest
			if(tempSum == X)
			{
        //Go out of function
				return tempSum;
			}
		}
	}
	return closestSum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}  // } Driver Code Ends
