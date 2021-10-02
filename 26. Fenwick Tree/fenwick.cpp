//Fenwick Tree for Sum Range Query

#include<bits/stdc++.h>
using namespace std;

class Fenwick {
public:
	int n;
	vector<int>bits;

	//we will make the array of size n+1, because we will use 1 based indexing.
	//this due to the fact that, 0 will be the root of our fenwick tree.
	Fenwick(int n) {
		this->n = n + 1;
		bits.resize(n + 1, 0);
	}

	//to find the sum of first x elements [1,x]
	int sum(int x) {
		x++; //1 based indexing
		int res = 0;
		while (x > 0) {
			res += bits[x];
			x = x - (x & -x);
		}
		return res;
	}

	//to find the sum between a range
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	//to add values to the tree from index x
	void add(int x, int val) {
		x++; // 1 based indexing
		while (x < n) {
			bits[x] = bits[x] + val;
			x = x + (x & -x);
		}
	}

};

int main() {

	int n;
	cin >> n;
	int arr[n];

	Fenwick F(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		F.add(i, arr[i]);
	}

	cout << F.sum(3) << endl; //sum from index [0,3]   
	cout << F.sum(2, 4) << endl; //sum from index [2,4]


	return 0;
}