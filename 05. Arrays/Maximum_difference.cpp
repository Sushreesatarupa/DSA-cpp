//Find maximum value of arr[i] - arr[j], where i < j

#include <iostream>
using namespace std;

void maxDiff(int arr[], int size)
{
    int diff = arr[1] - arr[0];
    int leastVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        diff = max(diff, arr[i] - leastVal);
        leastVal = min(leastVal, arr[i]);
    }
    cout << diff;
}
int main()
{
    int n, d;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Max diff. according to given condition is: ";

    maxDiff(arr, n);
    return 0;
}