/*
A square matrix of size N x N. The task is to rotate it by 90 degrees in anti-clockwise
direction without using any extra space. 
example: 
Input:
N = 3 
matrix[][] = {{1, 2, 3},
              {4, 5, 6},
              {5, 6, 7}}
Output: 
Rotated Matrix:
3 6 7
2 5 6
1 4 5

Time Complexity: O(N*N)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

//this function is to swap elements after transpose to
//rotate by 90 degrees.
void toreversecolumns(vector<vector<int>> &arr)
{
    int n1 = arr.size();
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0, k = n1 - 1; j < k; j++, k--)
        {
            swap(arr[j][i], arr[k][i]);
        }
    }
}

//this function is to transpose the matrix.
void totranspose(vector<vector<int>> &arr)
{
    int n1 = arr.size();
    for (int i = 0; i < n1; i++)
    {
        for (int j = i; j < n1; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}
// function which takes the matrix as parameter and
// rotate it by 90 degrees by calling totranspose
// and toreversecolumns function respectively.
void rotateby90(vector<vector<int>> &arr)
{
    totranspose(arr);
    toreversecolumns(arr);
}

//Driver code starts
int main()
{
    vector<vector<int>> X = {{1, 2, 3},
                             {4, 5, 6},
                             {5, 6, 7}};
    rotateby90(X);
    int n1 = X.size();

    //printing the rotated array.
    cout << "The Resultant Rotated array is:" << endl;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            cout << X[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//Driver code ends