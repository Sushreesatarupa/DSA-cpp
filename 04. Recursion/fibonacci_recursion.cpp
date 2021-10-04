#include <bits/stdc++.h>
using namespace std;
#define int long long
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

signed main() {
    cout << "please enter n " << endl;
    int n;
    cin >> n;
    cout << fibonacci(n);

    return 0;
}
