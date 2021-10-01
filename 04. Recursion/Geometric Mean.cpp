#include <bits/stdc++.h>
using namespace std;
double sum(int n)
{
    if (n == 0)       //base case
        return 1;
    double ans = 1 / (double)pow(3, n) + sum(n - 1);        // calculating the sum each time
    return ans;         //final answer
}
 
int main()
{
    int n = 5;
 
    cout << sum(n) << endl;
 
    return 0;
}
