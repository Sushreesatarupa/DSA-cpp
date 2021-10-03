//Top-Down Approch ( Recursive approach)

#include <bits/stdc++.h>
using namespace std;

#define mx 1000000

int dp[mx + 1];

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int res;

    res = fib(n - 1) + fib(n - 2);

    dp[n] = res;

    return dp[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= mx; ++i)
        {
            dp[i] = -1;
        }
        cout << fib(n) << endl;
    }
    return 0;
} 

