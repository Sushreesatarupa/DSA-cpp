#include <bits/stdc++.h>
using namespace std;
vector<int> wave_sort(vector<int> &v, int n)
{
	for (int i = 0; i < n; i += 2)
	{
		if (v[i] < v[i - 1] and i != 0)
		{
			swap(v[i], v[i - 1]);
		}
		if (v[i] < v[i + 1] and i != n - 1)
		{
			swap(v[i], v[i + 1]);
		}
	}

	return v;
}

int main()
{
	int n;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	wave_sort(v, n);
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}
