/* Search in a 2D matrix
  1) Integers in each row are sorted from left to right.
  2) The first integer of each row is greater
     than the last integer of the previous row.

*/


#include <iostream>
#include <vector>
using namespace std;

// O(m+n)
/*bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int n = matrix.size(), m = matrix[0].size();
    int row = 0, col = m-1;

    int ans = false;
    while (col>=0 && row<n) {
        if(matrix[row][col] < target) {
            row++;
        }
        else if(matrix[row][col] > target) {
            col--;
        }
        else {
            ans = true;
            break;
        }
    }
    return ans;
}*/


//O(log m*n)
bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = n*m-1;

    // doing binary search
    bool ans = false;
    while (low<=high) {
        int mid = low + (high-low)/2;

        if (matrix[mid/m][mid%m]==target) {
            ans = true;
            break;
        }
        if (matrix[mid/m][mid%m] < target) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return ans;
}

int main () {
    int n, m;
    cout << "Enter n and m ";
    cin >> n >> m;

    vector<vector<int>> arr (n, vector<int>(m));

    cout << "\nEnter elements in sorted order\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    int target;
    cout << "\nEnter target ";
    cin >> target;
    bool ans = searchMatrix (arr, target);

    ans == true ? cout << "true" : cout << "false";
}
