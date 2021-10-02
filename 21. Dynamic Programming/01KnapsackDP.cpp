#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int KnapsackDp(int fw, int values[], int weight[], int n)
{
    int dp[n+1][fw+1];
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    for(int i=0; i<=fw; i++)
        dp[0][i] = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=fw; j++)
        {
            if(weight[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(values[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]);
            }
        }
    }
    return dp[n][fw];
}
int main()
{
    int n, fw;
    cin>>n;
    cin>>fw;
    int values[n], weight[n];
    for(int i=0; i<n; i++)
        cin>>values[i];
    for(int i=0; i<n; i++)
        cin>>weight[i];
    cout<<KnapsackDp(fw, values, weight, n);
    return 0;
}