/* Window Sliding Technique

The technique can be best understood with the window pane in bus, consider a window of length n and the pane which is fixed in it of length k. Consider, initially the pane is at extreme left i.e., at 0 units from the left. Now, co-relate the window with array arr[] of size n and pane with current_sum of size k elements. Now, if we apply force on the window such that it moves a unit distance ahead. The pane will cover next k consecutive elements. 
Consider an array arr[] = {5, 2, -1, 0, 3} and value of k = 3 and n = 5
Applying sliding window technique : 

We compute the sum of first k elements out of n terms using a linear loop and store the sum in variable window_sum.
Then we will graze linearly over the array till it reaches the end and simultaneously keep track of maximum sum.
To get the current sum of block of k elements just subtract the first element from the previous block and add the last element of the current block .
*/


/*
Time Complexity: O(n)
Algo's Objective: Maximum/Minimum Sum of K size subarray

1. window_sum: Store the sum of elements of current window
2. max_sum: Store the maximum sum while iterating through windows
3. While running the for loop, we are removing the 1st element of the current window and adding the rightmost element (not included) of the window.
*/

// O(n) solution for finding maximum sum of
// a subarray of size k
#include <iostream>
using namespace std;

// Returns maximum sum in a subarray of size k.
int maxSum(int arr[], int n, int k)
{
	// n must be greater
	if (n < k) {
		cout << "Invalid";
		return -1;
	}

	// Compute sum of first window of size k
	int max_sum = 0;
	for (int i = 0; i < k; i++)
		max_sum += arr[i];

	// Compute sums of remaining windows by
	// removing first element of previous
	// window and adding last element of
	// current window.
	int window_sum = max_sum;
	for (int i = k; i < n; i++) {
		window_sum += arr[i] - arr[i - k];
		max_sum = max(max_sum, window_sum);
	}

	return max_sum;
}

// Driver code
int main()
{
	int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
	int k = 4;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxSum(arr, n, k);
	return 0;
}