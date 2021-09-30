#include <bits/stdc++.h>
using namespace std;
//Find Length of Longest Common Subsequence

int c = 0;
int lcs(string &s1, string &s2, int l1, int l2, vector<vector<int>> &m)
{
    if (l1 == 0 || l2 == 0)
        return 0;
    if (m[l1][l2] != -1)
    {
        return m[l1][l2];
    }
    if (s1[l1 - 1] == s2[l2 - 1])
    {
        return m[l1][l2] = 1 + lcs(s1, s2, l1 - 1, l2 - 1, m);
    }
    else
    {
        return m[l1][l2] = max(lcs(s1, s2, l1 - 1, l2, m), lcs(s1, s2, l1, l2 - 1, m));
    }
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int>> v(1100, vector<int>(1001, -1));
    int ans = lcs(s1, s2, s1.size(), s2.size(), v);
    cout<<ans<<endl;
    
}



