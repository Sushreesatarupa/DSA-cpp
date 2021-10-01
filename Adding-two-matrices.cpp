/*
Given two matrices A and B having (n1 x m1) and (n2 x m2) dimensions respectively. Add A and B. 

n1 = 2, m1 = 3
A[][] = {{5, 2, 3},
         {4, 6, 9}}

n2 = 2, m2 = 3
B[][] = {{1, 3, 3},
         {2, 3, 3}}

Output: 6 5 6 
        6 9 12


Constraints:
1 <= n1, m1, n2, m2 <= 30
0 <= Ai, Bi <= 100

Time Complexity : O(n1*m1)
Space Complexity : O(n1*m1)
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sumMatrix(const vector<vector<int>> &X, const vector<vector<int>> &Y)
{
    //storing the size of rows and columns.
    int n1 = X.size();
    int m1 = X[0].size();
    int n2 = Y.size();
    int m2 = Y[0].size();

    //list to store the result.
    vector<vector<int>> result;

    //we can add matrices only if both have same no. of rows and columns.
    if (n1 == n2 && m1 == m2)
    {
        result.resize(n1);
        for (int i = 0; i < n1; i++)
        {
            result[i].assign(m1, 0);
            for (int j = 0; j < m1; j++)
                //calculating the sum.
                result[i][j] = X[i][j] + Y[i][j];
        }
    }
    //returning the result.
    return result;
}

//Driver code starts here
int main()
{
    //Initializing two arrays.
    vector<vector<int>> X = {{1, 2, 3},
                             {2, 3, 4},
                             {2, 4, 5}};

    vector<vector<int>> Y = {{3, 2, 3},
                             {2, 7, 4},
                             {6, 9, 5}};
    cout << "sum of resultant array is : " << endl;
    vector<vector<int>> result = sumMatrix(X, Y);
    int n1 = result.size();
    int m1 = result[0].size();

    //printing the resultant array
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
