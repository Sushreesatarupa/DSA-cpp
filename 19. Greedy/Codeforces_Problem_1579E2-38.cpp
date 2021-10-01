// Problem Link: https://codeforces.com/contest/1579/problem/E2

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 10000000000000007
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(int i = x; i >= y; i--)
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<"\n";
#define err1(a) cout<<#a<<" "<<a<<"\n"
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<"\n"
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<"\n"
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<"\n"
#define vint vector<int>
#define vl vector<long>
#define vll vector<long long>
#define um unordered_map
#define pb push_back
#define pll pair<ll,ll>
#define mone cout<<-1<<"\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define nl cout<<"\n"
#define all(x) x.begin(),x.end()
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
#define INF 1000000000000000000
const ll mx = 1e9;
ll check(map<ll, ll> &ft, ll x)
{
	ll s = 0;
	for (; x > 0; x -= (x & -x))
		s += ft[x];
	return s;
}
void update(map<ll, ll> &ft, ll x)
{
	for (; x <= 2 * mx + 10; x += (x & -x))
		ft[x] += 1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	clock_t tStart = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll arr[n];
		FOR(i, n)
		cin >> arr[i];
		deque<ll> q;
		q.push_back(arr[0]);
		ll ans = 0;
		map<ll, ll> ft;
		map<ll, ll> hash;
		update(ft, arr[0] + mx + 1);
		++hash[arr[0] + mx + 1];
		For(i, 1, n - 1)
		{
			ll a = check(ft, 2 * mx + 10), b = check(ft, arr[i] + mx + 1);
			//err3(a, b, hash[arr[i] + mx + 1]);
			if ((a - b) < (b - hash[arr[i] + mx + 1]))
				ans += (a - b);
			else
				ans += b - hash[arr[i] + mx + 1];
			update(ft, arr[i] + mx + 1);
			++hash[arr[i] + mx + 1];
		}
		cout << ans << "\n";
	}
#ifndef ONLINE_JUDGE
	printf("\nRun Time -> %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
}