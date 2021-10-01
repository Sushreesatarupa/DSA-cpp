/*
	Topic: Segment Tree
	Problem: Finding the maximum and the number of times it appears

	This code provides the template to solve above stated problem using
	segment tree.
*/

// storing pair of number at each vertex in tree
pair<int, int> seg[4*MAXN];

// function to combine 2 child vertex and form parent vertex

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

// function to build segment tree

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        seg[v] = combine(seg[v*2], seg[v*2+1]);
    }
}

// function to get maximum among the values

pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return seg[v];
    int tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, min(r, tm)), 
                   get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

// function to update values in segment tree

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        seg[v] = make_pair(new_val, 1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        seg[v] = combine(seg[v*2], seg[v*2+1]);
    }
}
