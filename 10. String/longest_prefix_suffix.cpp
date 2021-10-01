#include <bits/stdc++.h>
using namespace std;
typedef long long  int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define PRIME 1000000007
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPR(i, a, b) for (int i = a; i >= b; i--)
const int SIZE = 1e5 + 5;

// calculates longest proper prefix which is also a proper suffix.
// see https://cp-algorithms.com/string/prefix-function.html for more details

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s("abab");
    cout<<prefix_function(s).back();
	
	return 0;
}
