#include<bits/stdc++.h>
using namespace std;

int specialKey(int n) {
    if(n<=6) {
        return n;
    }
    int max = 0;
    for(int b = n-3;b>=1;b--) {
        int curr = (n-b-1)*specialKey(b);
        if(curr>max) {
            max = curr;
        }
    }
    return max;
}

int main() {
    int test;
    cin>>test;
    while(test--) {
        int n;
        cin>>n;
        cout<<specialKey(n)<<endl;
    }
    return 0;
}
