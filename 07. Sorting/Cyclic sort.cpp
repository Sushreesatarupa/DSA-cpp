using namespace std;
#include <iostream> 
// Function sort the array using Cycle sort
void cyclicSort(int arr[], int n)
{
    // count number of memory writes
    int writes = 0;
 
    // traverse array elements and put it to on
    // the right place
    for (int start = 0; start <= n - 2; start++) {
        // initialize item as starting point
        int item = arr[start];
 
        // Find position where we put the item. We basically
        // count all smaller elements on right side of item.
        int pos = start;
        for (int i = start + 1; i < n; i++)
            if (arr[i] < item)
                pos++;
 
        // If item is already in correct position
        if (pos == start)
            continue;
 
        // ignore all duplicate  elements
        while (item == arr[pos])
            pos += 1;
 
        // put the item to it's right position
        if (pos != start) {
            int temp = item;
            item = arr[pos];
            arr[pos] = temp;
            writes++;
        }
 
        // Rotate rest of the cycle
        while (pos != start) {
            pos = start;
 
            // Find position where we put the element
            for (int i = start + 1; i < n; i++)
                if (arr[i] < item)
                    pos += 1;
 
            // ignore all duplicate  elements
            while (item == arr[pos])
                pos += 1;
 
            // put the item to it's right position
            if (item != arr[pos]) {
                int temp = item;
                item = arr[pos];
                arr[pos] = temp;
                writes++;
            }
        }
    }
 
    // Number of memory writes or swaps
    // cout << writes << endl ;
}
 
// Driver program to test above function
int main()
{
    int arr[] = { 1, 8, 3, 9, 10, 10, 2, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cyclicSort(arr, n);
 
    cout << "After sort : " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}