#include<iostream>
using namespace std;
 int main()
 {
     int i, j, n, m;
     int arr[100][100], trs[100][100];
     cout << "Enter the number of rows:" << endl;
     cin >> n;
     cout << "Enter the number of colums:" << endl;
     cin >> m;
     cout << "Enter the elements of matrix:" << endl;
     for (i = 0; i < n; i++)
     {
         for(j = 0; j < m; j++)
         {
             cin >> arr[i][j];
         }
     }
     
     // transpose of the matrix
     for(i = 0; i < n; i++)
     {
         for(j = 0; j < m; j++)
         {
            trs[j][i] = arr[i][j];
         }
     }
     
     cout << "Transposed matrix:" << endl;
     for ( i = 0; i < m; i++)
     {
         for( j = 0; j < n; j++)
         {
             cout << trs[i][j] << "  ";
         }
         cout << endl; 
     }
     
     return 0;
 }