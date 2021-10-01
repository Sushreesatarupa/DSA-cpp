// Link problem : https://www.e-olymp.com/en/problems/66

#include <algorithm>
#include <iostream>

using namespace std;
int n, h1, m1, h2, m2, say, temp;

struct t_time
{
    int start;
    int finish;
} meets[1002];

bool cmp(t_time x, t_time y)
{
    if (x.finish == y.finish)
        return x.start < y.start;

    return x.finish < y.finish;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
        meets[i].start = h1 * 60 + m1;
        meets[i].finish = h2 * 60 + m2;
    }

    sort(meets, meets + n, cmp);
    say = 1;
    temp = meets[0].finish;

    for (int i = 1; i < n; i++)
    {
        if (meets[i].start >= temp)
        {
            say++;
            temp = meets[i].finish;
        }
    }

    cout << say << endl;
    return 0;
}