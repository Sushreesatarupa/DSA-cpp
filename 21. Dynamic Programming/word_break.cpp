/*
    This is a very famous DP problem in which we have to break string in to words that are present in the dictionay.
    Problem Link: https://www.interviewbit.com/problems/word-break/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 10000000000000007
ll wordBreak(string A, vector<string> &B) {
    map<string, int> hash;
    for(int i = 0; i < B.size(); i++)
    hash[B[i]] = 1;
    ll n = A.length();
    ll dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i; j++)
        {
            int l = j, r = j+i;
            string wd = A.substr(j,i+1);
            if(hash[wd])
            dp[l][r] = 1;
            else
            {
                for(int k = l; k < r; k++)
                dp[l][r] = dp[l][r] | (dp[l][k]&dp[k+1][r]);
            }
        }
    }
    return dp[0][n-1];
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    t=1;
    while(t--)
    {
        string s;
        cin>>s;
        ll n;
        cin>>n;
        vector<string> dictionary(n);
        for(int i = 0; i < n; i++)
        cin>>dictionary[i];
        cout<<wordBreak(s, dictionary);
    }
}
