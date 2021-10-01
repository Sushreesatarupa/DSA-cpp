// C++ program for activity selection problem.

#include <bits/stdc++.h>
using namespace std;

void printMaxActivities(int s[], int f[], int n)
{
	int i, j;

	cout <<"Following activities are selected "<< endl;

	i = 0;
	cout <<" "<< i;

	// Consider rest of the activities
	for (j = 1; j < n; j++)
	{
	
	if (s[j] >= f[i])
	{
		cout <<" " << j;
		i = j;
	}
	}
}

int main()
{
	int s[] = {1, 5, 3, 0, 8, 7};
	int f[] = {2, 4, 3, 5, 6, 8};
	int n = sizeof(s)/sizeof(s[0]);
	printMaxActivities(s, f, n);
	return 0;
}

