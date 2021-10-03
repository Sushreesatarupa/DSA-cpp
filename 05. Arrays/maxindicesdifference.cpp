//maximum difference in indices (j-i) such that a[j]>a[i]
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = -1, j, n, p1 = 0, p2;// p1 and p2 keep index values of the 2 elements
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter the elements-\n";
    int a[n];
    while (++i < n)
        cin >> a[i];
    i = -1;
    j = n;

    while (++i < n / 2 && --j >= n / 2)
        if (a[i] < a[j]) //p1 and p2 are intially found by simultaneously traversing the array from the front and end
        {                
            p1 = i;
            p2 = j;
        }

    i = p1;
    j = p2;
    while (i-- >= 0)
        if (a[i] < a[p2]) //array is traversed from p1-1 to 0 to find an element < a[p2]
            p1 = i;

    while (++j < n) //array is traversed from p2+1 to n-1 to find an element > a[p1]
        if (a[p1] < a[j])
            p2 = j;
    cout << "Max difference: \n";
    cout << p2 - p1 << endl; //max diff is found
}
