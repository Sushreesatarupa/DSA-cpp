/* 
Implement Happy number

A happy number is a number defined by the following process:

    Starting with any positive integer, replace the number by the sum of the squares of its digits.
    Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    Those numbers for which this process ends in 1 are happy.

Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:

Input: n = 2
Output: false

 

Constraints:
    1 <= n <= 231 - 1

*/

#include<bits/stdc++.h>

using namespace std; 

//algorithm
class Solution {
public:
    bool isHappy(int n){
	
        while(true){
            long sum = 0;
            while(n != 0){
                int lastDigit = n % 10;
                n /= 10;
                sum += lastDigit * lastDigit;
            }
            if (1 <= sum && sum <= 9){

                if (sum == 1 || sum == 7) return true;
                else return false;
            }
            else n = sum;
        }
    }
};

// Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        if(ob.isHappy(n) == true) cout << "Happy Number" << endl;
        else cout << "Not a Happy Number" << endl;
    }
    return 0;
}