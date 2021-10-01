#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{
    return (a < b);
}

int max_cutted_rope_pieces(int length, int a, int b, int c)
{
    int res;
    if (length == 0)
    {
        return 0;
    }
    if (length < 0)
    {
        return -1;
    }
    res = max({max_cutted_rope_pieces(length - a, a, b, c), max_cutted_rope_pieces(length - b, a, b, c), max_cutted_rope_pieces(length - c, a, b, c)}, comp);
    if (res == -1)
    {
        return -1;
    }
    else
    {
        return res + 1;
    }
}

int main()
{
    // while(1)
    // {
    int length, a, b, c;
    cin >> length;
    cin >> a >> b >> c;
    cout << max_cutted_rope_pieces(length, a, b, c);
    // }
} 
