/*
Problem can be found here : https://leetcode.com/problems/n-th-tribonacci-number/

*/

#include <bits/stdc++.h>
using namespace std;

int tribonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<n<<"th tribonacci number is: "<< tribonacci(n)<<endl;
    return 0;
}
