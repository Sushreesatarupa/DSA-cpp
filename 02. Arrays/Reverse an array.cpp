#include <iostream>
using namespace std;
int main() {
  
  //number of test cases
	int t;
	cin>>t;
	for(int test=0;test<t;test++)
	{
      //size of array
	    int n;
	    cin>>n;
    
      //array to store array elements
	    int A[n];
	    for(int i=0;i<n;i++)
	    {
         //Input array elements
	        cin>>A[i];
	    }
	    for(int begin=0;begin<(n/2);begin++)
	    {
     
	        int end= n-1-begin;//last index
        
          //swapping positions
	        int temp= A[begin];
	        A[begin]=A[end];
	        A[end]=temp;
	    }
       //print out the array
	    for(int i=0;i<n;i++)
	    cout<<A[i]<<" ";
	    cout<<endl;
	    
	}
	return 0;
}
