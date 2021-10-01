#include <iostream>
using namespace std;

int  partition(int array[], int lb, int ub)
{
    int pivot = array[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (array[start] <=pivot)
        {
            start++;
        }
        while (array[end] > pivot)
        {
            end--;
        }
        if (start<end)
        {
            swap(array[start],array[end]);
        }



    }
    swap(array[lb],array[end]);
    return end;
}

void quicksort(int array[], int lb, int ub)
{
    if (lb < ub)
    {
        int  pi = partition(array, lb, ub);
        quicksort(array, lb, pi-1 );
        quicksort(array, pi + 1, ub);
    }
}

int main()
{
    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int lb = 0, ub = n - 1;

    quicksort(array, lb, ub);

     for (int i = 0; i < n; i++)
    {
        cout<< array[i]<<" ";
    }
}