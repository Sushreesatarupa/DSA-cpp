/*
You are given an array of integers. Find a peak element in it. 
An element of a Array is said to be peak if it is NOT smaller than any of its its neighbours. 
For corner elements, we need to consider only one neighbour. 

Example:
Input: arr[]= {5, 10, 20, 15}
       Output: 20
       Element 20 has neighbours 10 and 15,
       both of them are less than 20.

Input: arr[] = {10, 20, 15, 2, 23, 90, 67}
       Output: 20 or 90
       The element 20 has neighbours 10 and 15, 
       both of them are less than 20, similarly 90 has neighbours 23 and 67.
       
Approach:
  If in the array, the first element is greater than the second or the last element is greater than the second last, print the respective element and terminate the program.
Else traverse the array from the second index to the second last index
If for an element array[i], it is greater than both its neighbours, i.e., array[i] > array[i-1] and array[i] > array[i+1], then print that element and terminate.

Time complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
int findPeak(int arr[], int n)
{
    if (n == 1)      // when either first or last element is the peak element
      return 0;
    if (arr[0] >= arr[1])
        return 0;
    if (arr[n - 1] >= arr[n - 2])
        return n - 1;
		
    		// check if other elements can be the peak element
    for (int i = 1; i < n - 1; i++) {
 
	        // check for the presence of smaller neighbors
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return i;
    }
}
 
// Driver Code
int main()
{
    int arr[] = { 1, 3, 20, 4, 1, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Index of a peak point is "
         << findPeak(arr, n);
    return 0;
}
