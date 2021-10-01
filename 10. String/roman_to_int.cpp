#include <bits/stdc++.h>
using namespace std;
typedef long long  int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define PRIME 1000000007
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPR(i, a, b) for (int i = a; i >= b; i--)
const int SIZE = 1e5 + 5;

int instance_val(string s) {
    if (s == "IV")
        return 4;
    else if (s == "IX")
        return 9;
    else if (s == "XL")
        return 40;
    else if (s == "XC")
        return 90;
    else if (s == "CD")
        return 400;
    else if (s == "CM")
        return 900;
    return 0;
}
    
int romanToInt(string s) {
    map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int res = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (i + 1 < s.length() && instance_val(s.substr(i, 2))) {
            res += instance_val(s.substr(i, 2));
                i += 1;
        } else {
            int cnt = 1;
            while (i + 1 < s.length() && s[i] == s[i+1]) {
                cnt++;
                i++;
            }
            res += mp[s[i]]*cnt;
        }
    }
    return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s("LVIII");
    cout<<romanToInt(s);
	
	return 0;
}
