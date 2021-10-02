/*
Implement BASIC CALCULATOR

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().


Example 1:

Input: s = "1 + 1"
Output: 2

Example 2:

Input: s = " 2-1 + 2 "
Output: 3

Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23

 

Constraints:

    1 <= s.length <= 3 * 105
    s consists of digits, '+', '-', '(', ')', and ' '.
    s represents a valid expression.
    '+' is not used as a unary operation.
    '-' could be used as a unary operation and in this case, it will not be used directly after a +ve or -ve signs (will be inside parentheses).
    There will be no two consecutive operators in the input.
    Every number and running calculation will fit in a signed 32-bit integer.


*/

#include<bits/stdc++.h>

using namespace std; 

//Algorithm
class Solution {
public:
    int dfs(const string& s, int& i, const int& N){
        int res = 0, sign = 1, num = 0;
        while(i < N && s[i] != ')'){
            if(isdigit(s[i]))
                num = num * 10 + (s[i] - '0');
            else{
                res += sign * num;
                num = 0;
                if(s[i] == '+') sign = 1;
                else if(s[i] == '-') sign = -1;
                else if(s[i] == '('){
                    i++;
                    res = res + sign * dfs(s, i, N);
                }
            }
            i++;
        }
        return res + sign * num;
    }
    
    int calculate(string s) {
        int i=0, N=s.size();
        return dfs(s,i,N);
    }
};

// Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        int n = ob.calculate(s);
        cout << n << endl;
    }
    return 0;
}