#include <iostream>
using namespace std;
void reverse_array(int arr[],int n)
{
	int start=0;
	int end=n-1;
	while(start<end)
	{
		int temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
	}
	cout<<"array is reversed using while loop:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<< " ";
	}
	cout<<endl;
	cout<<"array reversed using for loop"<<endl;
}
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
		reverse_array(A,n);
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
