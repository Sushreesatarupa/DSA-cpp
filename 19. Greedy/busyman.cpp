#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


bool cmp(pii p1, pii p2) {
    return p1.ss < p2.ss;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    w(x) {
        int n;
        cin >> n;
        vector<pair<int, int> > v(n);
        //v.clear();
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v[i] = {x, y};
        }


        sort(v.begin(), v.end(), cmp);
        /*  for(int i=0;i<n;i++){
                cout<<v[i].ff<<","<<v[i].ss<<endl;

            }*/
        int ans = 0;
        int last = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (v[i].ff >= last) {
                ans++;
                last = v[i].ss;
            }
        }
        cout << ans << "\n";
    }

}

int32_t main()
{
    clock_t begin = clock();
    c_p_c();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}