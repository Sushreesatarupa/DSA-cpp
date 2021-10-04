#include <bits/stdc++.h>
using namespace std;

// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
bool find3Numbers(int A[], int arr_size, int sum)
{
	int l, r;

	// Fix the first element as A[i]
	for (int i = 0; i < arr_size - 2; i++)
	{

		// Fix the second element as A[j]
		for (int j = i + 1; j < arr_size - 1; j++)
		{

			// Now look for the third number
			for (int k = j + 1; k < arr_size; k++)
			{
				if (A[i] + A[j] + A[k] == sum)
				{
					cout << "Triplet is " << A[i] <<
						", " << A[j] << ", " << A[k];
					return true;
				}
			}
		}
	}

	// If we reach here, then no triplet was found
	return false;
}

/* Driver code */
int main()
{
	int A[] = { 1, 4, 45, 6, 10, 8 };
	int sum = 22;
	int arr_size = sizeof(A) / sizeof(A[0]);
	find3Numbers(A, arr_size, sum);
	return 0;
}


