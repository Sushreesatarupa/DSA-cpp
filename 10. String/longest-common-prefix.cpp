#include <bits/stdc++.h>
using namespace std;

string commonPrefix(vector<string> strs)
{
    string common = strs[0];
    for (int i = 1; i < strs.size(); i++)
    {
        for (int j = 0; j < common.size(); j++)
        {
            if (strs[i][j] != common[j])
            {
                common.resize(j);
            }
            if (common == "")
                return common;
        }
    }
    return common;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n;
        cin >> n;
        vector<string> arr;
        while (n--)
        {
            cin >> s;
            arr.push_back(s);
        }
        cout << commonPrefix(arr) << '\n';
    }
    return 0;
}