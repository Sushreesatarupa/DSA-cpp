#include <bits/stdc++.h>
using namespace std;

//Finding all possible parentheses for a given n

vector<string> ans;
void gen(int n, string s, int open, int close)
{
    if (s.size() == 2 * n)
    {
        ans.push_back(s);
        return;
    }

    if (s.size() <= 2 * n)
    {
        if (open < n)
        {
            open++;
            s.push_back('(');
            gen(n, s, open, close);
            open--;
            s.pop_back();
        }
        if (open > close)
        {
            close++;
            s.push_back(')');
            gen(n, s, open, close);
            close--;
        }
    }

    return;
}


int main()
{
    int n;
    //Input number of parenthese pair required
    cin >> n;
    gen(n, "", 0, 0);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}
