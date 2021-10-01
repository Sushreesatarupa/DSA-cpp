/*
spiral Traversal of array
Input:
            1, 2, 3, 4, 5
            6, 7, 8, 9, 10
            11, 12, 13, 14, 15
            16, 17, 18, 19, 20
            21, 22, 23, 24, 25

Output: 
1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13

Time Complexity: O(r*c)
Auxiliary Space: O(r*c)
*/
#include <iostream>
#include <vector>
using namespace std;

//function to print spiral traversal of array.
void Spiral(vector<vector<int>> const &X)
{
    // base case
    if (X.size() == 0)
    {
        return;
    }

    int top = 0, bottom = X.size() - 1;
    int left = 0, right = X[0].size() - 1;

    while (1)
    {
        if (left > right)
        {
            break;
        }
        // print top row
        for (int i = left; i <= right; i++)
        {
            cout << X[top][i] << " ";
        }
        top++;

        if (top > bottom)
        {
            break;
        }
        // print right column
        for (int i = top; i <= bottom; i++)
        {
            cout << X[i][right] << " ";
        }
        right--;

        if (left > right)
        {
            break;
        }
        // print bottom row
        for (int i = right; i >= left; i--)
        {
            cout << X[bottom][i] << " ";
        }
        bottom--;

        if (top > bottom)
        {
            break;
        }
        // print left column
        for (int i = bottom; i >= top; i--)
        {
            cout << X[i][left] << " ";
        }
        left++;
    }
}

//driver code starts
int main()
{
    vector<vector<int>> mat =
        {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}};

    //calling of the function.
    Spiral(mat);

    return 0;
}