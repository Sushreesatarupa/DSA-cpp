#include <bits/stdc++.h>
using namespace std;

// swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// sorting function
void bubbleSort(int arr[], int n)
{
    bool swapped;
    for (int i = 0; i < n; i++)
    {
        swapped = false;
        for (int j = 1; j < n - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(&arr[j - 1], &arr[j]);
                swapped = true;
            }
        }
        if (!swapped) // if not swapped then the array is sorted, come out of the loop
        {
            break;
        }
    }
}
//  to print the array
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
// Driver code
int main()
{
    int arr[] = {65, 2, 34, 12, 22, 94, 43, 77, 55};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, len);
    cout << "Sorted array: \n";
    printArray(arr, len);
    return 0;
}
