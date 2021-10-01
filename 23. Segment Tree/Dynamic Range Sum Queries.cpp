// Problem: https://cses.fi/problemset/task/1648
// Solution: Segment Tree

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
long long seg[N*4];
 
void build(int l, int r, int idx)
{
	if(l == r) return void(scanf(" %lld",&seg[idx]));
	int mid = (l+r)>>1;
	build(l, mid, idx<<1), build(mid+1, r, idx<<1|1);
	seg[idx] = seg[idx<<1] + seg[idx<<1|1];
}
 
void update(int l, int r, int idx, int a, int b)
{
	if(!(l <= a && a <= r)) return ;
	if(l == r) return void(seg[idx] = b);
	int mid = (l+r)>>1;
	update(l, mid, idx<<1, a, b), update(mid+1, r, idx<<1|1, a, b);
	seg[idx] = seg[idx<<1] + seg[idx<<1|1];
}
 
long long query(int l, int r, int idx, int a, int b)
{
	if(r < a || b < l) return 0;
	if(a <= l && r <= b) return seg[idx];
	int mid = (l+r)>>1;
	return query(l, mid, idx<<1, a, b) + query(mid+1, r, idx<<1|1, a, b);
}
 
int main()
{
	int n, q;
	scanf(" %d %d",&n,&q);
	build(1, n, 1);
	while(q--)
	{
		int op, a, b;
		scanf(" %d %d %d",&op,&a,&b);
		if(op == 1) update(1, n, 1, a, b);
		else printf("%lld\n",query(1, n, 1, a, b));
	}
	return 0;
}
