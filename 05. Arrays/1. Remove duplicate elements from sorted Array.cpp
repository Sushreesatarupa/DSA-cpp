/***
6. Remove duplicate elements from sorted Array 
Given a sorted array A of size N, delete all the duplicates elements from A.
Note: Don't use set or HashMap to solve the problem.


Example 1:

Input:
N = 5
Array = {2, 2, 2, 2, 2}
Output: 2
Explanation: After removing all the duplicates 
only one instance of 2 will remain.
Example 2:

Input:
N = 3
Array = {1, 2, 2}
Output: 1 2 

Your Task:  
You dont need to read input or print anything. Complete the function remove_duplicate() which takes the array A[] and its size N as input parameters and modifies it in place to delete all the duplicates. The function must return an integer X denoting the new modified size of the array. 
Note: The generated output will print all the elements of the modified array from index 0 to X-1.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 104
1 ≤ A[i] ≤ 106
**/
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int remove_duplicate(int a[], int n)
    {
        // code here
        int j = 0;
        for (int i = 0; i < n - 1; i++)
            if (arr[i] != arr[i + 1])
                arr[j++] = arr[i];

        arr[j++] = arr[n - 1];

        return j;

        // in the above solution we are travrsing oncomplete array and cheaking if
        // curent and curent +1 pointer do not same value tha add current value at position "j"
        //and increment its value by one and return j as "no. of element which is not repeated" so
        // that we can make traversal till that elemnt in updated non - repeated element array...
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int a[N];
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        int n = ob.remove_duplicate(a, N);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends
