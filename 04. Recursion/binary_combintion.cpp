#include<bits/stdc++.h>
using namespace std;

void printPattern(string s, int i) {
    if(i==s.size()) {
        cout<<s<<endl;
        return;
    }
    if(s[i] == '?') {
        s[i] = '0';
        printPattern(s,i+1);

        s[i] = '1';
        printPattern(s,i+1);
    }
    else {
        printPattern(s,i+1);
    }
}

int main() {
    string s;
    cin>>s;
    printPattern(s,0);
    return 0;
}
