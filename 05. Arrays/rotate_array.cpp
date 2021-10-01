/***
Rotate array elements one by one
Given an array, rotate the array by one position in clock-wise direction. 
 
Example 1:
Input:
N = 5
a[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4
Explanation: 
1 2 3 4 5  when rotated by 1 element, it becomes  5 1 2 3 4.

Example 2:
Input:
N = 8
a[] = {9, 8, 7, 6, 4, 2, 1, 3}
Output:
3 9 8 7 6 4 2 1
Explanation: 
9, 8, 7, 6, 4, 2, 1, 3 when rotated by 1 element, it becomes 3 9 8 7 6 4 2 1.
 
Your Task:
Your task is to complete the function rotateFunction() which takes the array a[] and its size N as inputs and modify the array.
 
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
 
Constraints:
1<=N<=105
0<=a[i]<=105
**/




#include<bits/stdc++.h>
using namespace std;

void rotateFunction(int a[],int n) {
     int t=a[n-1];
    for(int i=n-1;i>=1;i--)
        a[i]=a[i-1];
    a[0]=t;
}

int main() {
    int n;
    cin>>n;
    
    int a[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    rotateFunction(a,n);
    
    for(int i=0;i<n;i++)
        cout<<a[i];
    
    cout<<"\n";
    
    return 0;
    
}
