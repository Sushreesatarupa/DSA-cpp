#include <iostream>

using namespace std;

int main()
{
    int n, i;
    float sum = 0.0, average;
    cout << "Enter the numbers of data: ";
    cin >> n;
    float num[n];
    for (i = 0; i < n; ++i)
    {
        cout << endl << i + 1 << ". Enter number: ";
        cin >> num[i];
        sum += num[i];
    }

    cout << endl << "Sum = " << sum;

    average = sum / n;
    cout << endl << "Average = " << average;

    return 0;
}