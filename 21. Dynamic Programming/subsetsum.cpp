#include<iostream>

void main()
{
    int n, sum;
    cin >> n >> sum;

    int a[n];

    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    bool dp[n + 1][sum + 1];

    for (int j = 0; j <= sum;j++)
        dp[0][j] = 0;

    for (int i = 0; i <= n;i++)
        dp[i][0] = 1;

    for (int j = 1; j <= sum;j++)
    {
        for (int i = 1; i <= n;i++)
        {
            dp[i][j] = 0;

            if (a[i - 1] <= j)
            {
                if(dp[i-1][j-a[i-1]]||dp[i-1][j])
                    dp[i][j] = 1;
            }
            else if(dp[i-1][j])
                dp[i][j] = 1;
        }
    }
}