#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int> const &a)
{
    int n = a.size();
    const int INF = 1e9;
    
    vector<int> d(n + 1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[j - 1] < a[i] && a[i] < d[j])
                d[j] = a[i];
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];

    int ans = LIS(a);
    cout << ans << endl;
}