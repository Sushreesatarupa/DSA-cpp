#include<bits/stdc++.h>
using namespace std;
#define ln "\n";
#define TC() int t; cin >> t; while(t--)
#define IO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){}

void LCS(string X, string Y, int n, int m){
	int dp[n+1][m+1];

	for(int i = 0; i < n+1; i++) dp[i][0] = 0;
	for(int j = 0; j < m+1; j++) dp[0][j] = 0;

	for(int i = 1; i < n+1; i++){
		for(int j = 1; j < m+1; j++){
			if(X[i-1] == Y[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	// Printing LCS (actually printing the LPS)
	int i = n, j = m;
	string s;
	while(i > 0 && j > 0){
		if(X[i-1] == Y[j-1]){
			s.push_back(X[i-1]);
			i--; j--;
		}
		else{
			if(dp[i-1][j] > dp[i][j-1])
				i--;
			else
				j--;
		}
	}
	cout << s << " " << s.size();
}

// Longest Palindromic Subsequence (LPS) -> variation of LCS (Longest Common Subsequence)
int main(){

	IO();
	// TC() solve();
	
	string a = "agbcba";
	string b(a); // stored the copy of a in b, so that we can reverse b and use the actual a
	reverse(b.begin(),b.end());

	LCS(a, b, a.size(), b.size());

	return 0;
}