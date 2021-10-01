/*
    Segment Tree: Construction + Queries + Update
    Problem: Sum query in a range
*/

#include <bits/stdc++.h>
using namespace std;

// Construction: 1-based indexing

const int MAXN = 100005;
vector<int> seg(4 * MAXN); // we declare vector of size 4 times the value of N

// Build function

void build(vector<int>& arr, int cur_idx, int start, int end) {
    if(start == end) {
        seg[cur_idx] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    // build left half & right half
    build(arr, 2 * cur_idx, start, mid);
    build(arr, 2 * cur_idx + 1, mid + 1, end);

    seg[cur_idx] = seg[2 * cur_idx] + seg[2 * cur_idx + 1];
}

// Query function

int query(int cur_idx, int start, int end, int l, int r) {
    if(start > end) {
        return 0;
    }
    if(l == start && r == end) {
        return seg[cur_idx];
    }

    int mid = (start + end) / 2;

    // In main function, query(0, 0, n-1, l, r);
    return query(2 * cur_idx, start, mid, l, min(r, mid))
            + query(2 * cur_idx + 1, mid + 1, end, max(l, mid+1), r);
}

// Update function

void update(int cur_idx, int l, int r, int pos, int new_val) {
    if(l == r) {
        seg[cur_idx] = new_val;
    }
    else {
        int mid = (l + r) / 2;
        if(pos <= mid) {
            update(2 * cur_idx, l, mid, pos, new_val);
        }
        else {
            update(2 * cur_idx + 1, mid + 1, r, pos, new_val);
        }
        seg[cur_idx] = seg[2 * cur_idx] + seg[2 * cur_idx + 1];
    }
}

/*
    Driver Code:
    int main() {
        vector<int> arr = {1, 2, 3, 4, 5, ...};
        int n = arr.size();
        
        // example function calls

        build(arr, 1, 0, n-1);
        query(4, 0, n-1, 0, 6);
        update(3, 0, 6, 3, 8); 
    }
*/