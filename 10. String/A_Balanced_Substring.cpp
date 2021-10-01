#include <bits/stdc++.h>

using namespace std;

int main()
{

	int t;
	cin >> t;
	while (t--)
	{

		int n;
		cin >> n;
		string s;
		cin >> s;

		int count_a = 0, count_b = 0;

		for (int i = 0; i < n; i++)
		{

			if (s[i] == 'a')
			{
				count_a += 1;
			}
			else
			{
				count_b += 1;
			}
		}
		if (count_a == 0 || count_b == 0)
		{
			cout << -1 << " " << -1 << "\n";
		}
		else
		{

			int l = 1, r;

			for (int i = 0; i < n - 1; i++)
			{

				if ((s[i] == 'a' && s[i + 1] == 'b') || (s[i] == 'b' && s[i + 1] == 'a'))
				{

					l = i + 1;
					r = i + 2;
					break;
				}
			}

			cout << l << " " << r << "\n";
		}
	}
}