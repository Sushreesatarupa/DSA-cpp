#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 105;
const int MOD = 1e9 + 7;
int ans, ct[N][N];
char a[N + 1][N + 1];
int n, m, str, end1;
bool vis[N][N];

void dijkstra(int str1, int end2){
    set<pair<int, pair<int, int> > > s;
    s.insert({0, {str1, end2}});
    // cost ---- ith cordinate, jth cordinate;
    while(!s.empty()){
        int cost = s.begin()->first;
        int i = s.begin()->second.first, j = s.begin()->second.second;
        ct[i][j] = cost;
        s.erase(s.begin());
        vis[i][j] = 1;
        if(i + 1 <= m and a[i + 1][j] != '*' and !vis[i + 1][j]){
            s.insert({cost + 1, {i + 1, j}});
            vis[i + 1][j] = true;
        }
        if(i - 1 >= 1 and a[i - 1][j] != '*' and !vis[i - 1][j]){
            s.insert({cost + 1, {i - 1, j}});
            vis[i - 1][j] = true;
        }
        if(j + 1 <= n and a[i][j + 1] != '*' and !vis[i][j + 1]){
            s.insert({cost + 1, {i, j + 1}});
            vis[i][j + 1] = true;
        }
        if(j - 1 >= 1 and a[i][j - 1] != '*' and !vis[i][j - 1]){
            s.insert({cost + 1, {i, j - 1}});
            vis[i][j - 1] = true;
        }
        if(j + 1 <= n and i + 1 <= m and a[i + 1][j + 1] != '*' and !vis[i + 1][j + 1]){
            s.insert({cost + 1, {i + 1, j + 1}});
            vis[i + 1][j + 1] = true;
        }
        if(j + 1 <= n and i - 1 >= 1 and a[i - 1][j + 1] != '*' and !vis[i - 1][j + 1]){
            s.insert({cost + 1, {i - 1, j + 1}});
            vis[i - 1][j + 1] = true;
        }
        if(j - 1 >= 1 and i - 1 >= 1 and a[i - 1][j - 1] != '*' and !vis[i - 1][j - 1]){
            s.insert({cost + 1, {i - 1, j - 1}});
            vis[i - 1][j - 1] = true;
        }
        if(j - 1 >= 1 and i + 1 <= m and a[i + 1][j - 1] != '*' and !vis[i + 1][j - 1]){
            s.insert({cost + 1, {i + 1, j - 1}});
            vis[i + 1][j - 1] = true;
        }
    }
}

void solve(){
    cin >> n >> m >> end1 >> str;
    for(int i = m; i >= 1; --i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    dijkstra(str, end1);
    int mx = 0;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            mx = max(mx, ct[i][j]);    
    cout << mx << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}
