given an Integer N, our task is to calculate the geometric sum of the given series
series: 1 + 1/3 + 1/9 + 1/27 + … + 1/(3^n) 
    
example:
n=5
output=1.49794
n=7
output=1.49977
    
    
Approach: In this problem, we will be using recursion recursion. 
First we will calculate the last term and call recursion on the remaining n-1 terms 
every time. 
At the end, final sum returned is the result.

//below is the c++ implementation for the same problem

#include <bits/stdc++.h>
using namespace std;
double sum(int n)
{
    if (n == 0)       //base case
        return 1;
    double ans = 1 / (double)pow(3, n) + sum(n - 1);        // calculating the sum each time
    return ans;         //final answer
}
 
int main()
{
    int n = 5;
 
    cout << sum(n) << endl;
 
    return 0;
}
