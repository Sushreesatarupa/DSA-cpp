#include<iostream>

using namespace std;

int main()
{
    int w, n;
    cin >> n >> w;

    int a[n+1], b[w+1];

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    int dp[n + 1][w + 1];

    for (int i = 0; i <= w;i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n;i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= w;j++)
        {
            if (a[i] <= j)
            {
                dp[i][j] = max(b[i] + dp[i-1][j - a[i]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w];
}