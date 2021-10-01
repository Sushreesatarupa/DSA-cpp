#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    void rotateArr(int arr[], int d, int n){
        // code here
        int rotate[d];
       for(int i=0;i<d;i++){
           rotate[i] = arr[i];
       }
       for(int i=d;i<n;i++){
           arr[i-d] = arr[i];
       }
         int j = 0;
       for(int i=n-d;i<n;i++){
           arr[i] = rotate[j];
           j++;
    }
    }
};


// { Driver Code Starts
int main() {
	int t;
	//taking testcases
	cin >> t;
	while(t--){
	    int n, d;
	    //input n and d
	    cin >> n >> d;
	    int arr[n];
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
  }
	    cout << endl;
	}
	return 0;
}  // } Driver Code Ends
