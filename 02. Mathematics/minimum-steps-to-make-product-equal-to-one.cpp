// Given an array arr[] containing N integers.
// In one step, any element of the array can either be increased or decreased by one.
// Find minimum steps required such that the product of the array elements becomes 1.

// Example 1:
// N = 3
// arr[] = {-2, 4, 0}
// output:5

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// -103 ≤ arr[i] ≤ 103

// Solution:
// To make product equal 1, every digit should be either 1 or -1.

// case1: If arr[i] is a positive integer
// steps=arr[i]-1;

// case2: If arr[i] is a negative integer
// steps=abs(arr[i]-1);

// case3: If arr[i] is zero
// steps = 1, always.

// Now, If count of negative integer is even then all negative integer will be -1 ans steps remains same.

// If count of negative integer is odd then steps depend on number of zero
// - if count of zero is 0 then we have to make on negative integer 1. ans=ans+2;
// - if count of zero is more than 0 then we make one zero integer a negative integer(i.e. -1) steps= 1;

int makeProductOne(int arr[], int N)
{
    int ans = 0, cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0)
        {
            ans++;
            cnt0++;
        }
        else if (arr[i] < 0)
        {
            ans + = abs(arr[i] + 1);
            cnt1++;
        }
        else
        {
            ans + = arr[i] - 1;
        }
    }
    if (cnt1 % 2 != 0 && cnt0 == 0)
    {
        ans += 2;
    }
    return ans;
}