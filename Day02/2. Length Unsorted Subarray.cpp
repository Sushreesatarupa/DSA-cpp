/**
2. Length Unsorted Subarray 
Given an unsorted array Arr of size N. Find the subarray Arr[s...e] such that sorting this subarray makes the whole array sorted.

Example 1:

Input:
N = 11
Arr[] ={10,12,20,30,25,40,32,31,35,50,60}
Output: 3 8
Explanation: Subarray starting from index
3 and ending at index 8 is required
subarray. Initial array: 10 12 20 30 25
40 32 31 35 50 60 Final array: 10 12 20
25 30 31 32 35 40 50 60
(After sorting the bold part)
Example 2:

Input:
N = 9
Arr[] = {0, 1, 15, 25, 6, 7, 30, 40, 50}
Output: 2 5
Explanation: Subarray starting from index
2 and ending at index 5 is required
subarray.
Initial array: 0 1 15 25 6 7 30 40 50
Final array:   0 1 6 7 15 25 30 40 50
(After sorting the bold part)
Your Task:
You don't need to read input or print anything. Your task is to complete the function printUnsorted() which takes the array of integers arr and n as parameters and returns a pair of integers denoting {s, e}. If no such subarray exists, return {0, 0}.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 107
1 ≤ Arr[i] ≤ 108


**/
