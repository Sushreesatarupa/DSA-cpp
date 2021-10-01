// Link problem : https://www.spoj.com/problems/AU7_5/

#include <cstdio>
#define MOD 5000011
using namespace std;
int dp[100001];

int main()
{
    int c, n, k;
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d %d", &n, &k);
        dp[1] = 2;
        for (int i = 2; i <= n; i++)
        {
            if (i - k - 1 > 0)
                dp[i] = (dp[i - 1] + dp[i - k - 1]) % MOD;
            else
                dp[i] = i + 1;
        }
        printf("%d\n", dp[n] % MOD);
    }
}