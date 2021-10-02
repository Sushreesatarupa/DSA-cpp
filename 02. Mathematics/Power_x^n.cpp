/*

Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

 

Constraints:

    -100.0 < x < 100.0
    -231 <= n <= 231-1
    -104 <= xn <= 104

 */

//CODE
#include<bits/stdc++.h>

using namespace std; 

//algorithm
class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        while (n) {
            if (n % 2) result = n > 0 ? result * x : result / x;
            x = x * x;
            n /= 2;
        }
        return result;
    }
};

// Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {  
        double x;
        int n;
        cout << "Enter a number(x) to find the Power of it :";
        cin >> x;
        cout << "Enter the Power(n) :";
        cin >> n;
        Solution ob;
        cout << "x raised to power n is: " << ob.myPow(x, n) << endl;
    }
    return 0;
}