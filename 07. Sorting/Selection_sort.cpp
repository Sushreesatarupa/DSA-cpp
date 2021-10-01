//By Sai Prachodhan Devulapalli
// C++ program for implementation of selection sort
#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
  //Swapping using temp method like first storing value in third variable and using that we swap
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		// Swap the found minimum element with the first element using call by reference
		swap(&arr[min_idx], &arr[i]);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	for (int i=0; i < size; i++)
		cout << arr[i] << " ";
	cout << '/n';
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
  //You can also use *arr instead of arr[] 
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}
