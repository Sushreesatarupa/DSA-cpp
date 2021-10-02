
// Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;

// } Driver Code Ends

//User function Template for C++

// Complete this function
int sumOfDigits(int n)
{
    //Your code here
    if (n < 10)
        return n;
    return (n % 10) + sumOfDigits(n / 10);
}

// { Driver Code Starts.

int main()
{
    int T;

    //taking testcases
    cin >> T;
    while (T--)
    {
        int n;

        //taking input n
        cin >> n;

        //calling method sumOfDigits()
        cout << sumOfDigits(n) << endl;
    }
    return 0;
} // } Driver Code Ends