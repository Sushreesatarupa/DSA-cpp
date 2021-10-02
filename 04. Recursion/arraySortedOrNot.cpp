// Checking if the given array is sorted or not using Recursion

#include<bits/stdc++.h>
using namespace std;

bool sorted (int arr[], int n) {
	if (n==1) {
		return true;
	}
	bool restOfArray = sorted(arr+1, n-1);
	return (arr[0] < arr[1] && restOfArray);
}

int main() 
{
	int n;
	cout<<"Enter array size"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter elements of aarray"<<endl;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	if (sorted(arr,n)) {
		cout<<"Sorted"<<endl;
	} else {
		cout<<"Not Sorted"<<endl;
	}
	
	return  0;
}
