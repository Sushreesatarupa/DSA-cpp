// C++ program to find triplets in a given
// array whose sum is zero
#include<bits/stdc++.h>
using namespace std;

// function to print triplets with 0 sum
void findTriplets(int arr[], int n)
{
	bool found = false;

	for (int i=0; i<n-1; i++)
	{
		// Find all pairs with sum equals to
		// "-arr[i]"
		unordered_set<int> s;
		for (int j=i+1; j<n; j++)
		{
			int x = -(arr[i] + arr[j]);
			if (s.find(x) != s.end())
			{
				//printf("%d %d %d\n", x, arr[i], arr[j]);
				cout<<"The triplet with 0 sum is: ";
				cout<<x<<" "<<arr[i]<<" "<<arr[j];
				cout<<endl;
				found = true;
			}
			else
				s.insert(arr[j]);
		}
	}

	if (found == false)
		cout << " No Triplet Found" << endl;
}

// Driver code
int main()
{
	cout<<"Enter the number of elements ";
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter the array elements ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	findTriplets(arr, n);
	return 0;
}
