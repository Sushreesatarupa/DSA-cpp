// C++ program to sort a
// binary array in one pass
#include <bits/stdc++.h>
using namespace std;

/*Function to put all 0s on
left and all 1s on right*/
void segregate0and1(int arr[],
					int size)
{
	int type0 = 0;
	int type1 = size - 1;
	
	while(type0 < type1)
	{
		if(arr[type0] == 1)
		{
			swap(arr[type0],
				arr[type1]);
			type1--;
		}
		else
		type0++;
	}
}

// Driver Code
int main()
{
	int arr[] = {0, 1, 0, 1, 1, 1};
	int i, arr_size = sizeof(arr) /
					sizeof(arr[0]);

	segregate0and1(arr, arr_size);

	cout << "Array after segregation is ";
	for (i = 0; i < arr_size; i++)
		cout << arr[i] << " ";

	return 0;
}
