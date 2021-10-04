#include <iostream>
using namespace std;

int main()
{
    int r, c, a[100][100], b[100][100], sum[100][100], i, j;

    cout << "Enter the number of rows: ";
    cin >> r;

    cout << "Enter the number of columns: ";
    cin >> c;

    cout << endl << "Enter the elements of 1st matrix: " << endl;

    // Get elements of first matrix entered by user.
    for (i = 0; i < r; ++i)
    {
     for (j = 0; j < c; ++j)
       {
           cin >> a[i][j];
       }   
    }

    // Get elements of second matrix entered by user.
    cout << endl << "Enter the elements of 2nd matrix: " << endl;
    for (i = 0; i < r; ++i)
    {
       for (j = 0; j < c; ++j)
       {
           cin >> b[i][j];
       }
    }

    // Adding the two matrices
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j) 
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    // Display the result.
    cout << endl << "Sum of the two matrix is: " << endl;
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            cout << sum[i][j] << "  ";
            if (j == c - 1) {
                cout << endl;
            }
        }
    }

    return 0;
}