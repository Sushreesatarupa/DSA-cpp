/*
Given an array, rotate the array by one position in clock-wise direction.
 

Example 1:

Input:
N = 5
A[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4
 

Example 2:

Input:
N = 8
A[] = {9, 8, 7, 6, 4, 2, 1, 3}
Output:
3 9 8 7 6 4 2 1
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function rotate() which takes the array A[] and its size N as inputs and modify the array.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 

Constraints:
1<=N<=105
0<=a[i]<=105

*/


#include <iostream>
#include <stdio.h>
using namespace std;

void rotate(int arr[], int n)
{
    if (n == 1)
    {
        return;
    }

    int t, x;

    t = arr[0];
    arr[0] = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        x = arr[i];
        arr[i] = t;
        t = x;
    }
    return;
}

// Driver code
int main()
{
    int num;
    cout << "Enter the number of elements: \n";
    cin >> num;
    int arr[num]; //create an array with given number of elements
    cout << "Enter elements:" << endl;

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    rotate(arr, n);
    cout << "Array rotated by one is: \n ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
    
}

