#include <iostream>

using namespace std;

int main(void)
{
  int m1, n1, m2, n2;
  cout << "Enter number of rows in matrix 1: ";
  cin >> m1;
  cout << "Enter number of columns in matrix 1";
  cin >> n1;
  cout << "Enter number of rows in matrix 2: ";
  cin >> m2;
  cout << "Enter number of columns in matrix 2";
  cin >> n2;
  
  if ( m1 == m2 && n1 == n2 ){
    int a[m1][n1], b[m2][n2], c[m1][n1];
    cout << "Enter numbers in matrix 1" << endl;
    for(int i = 0; i < m2; i++){
      for(int j = 0; j < n2; j++){
        cout << "arr1[" << x << "][" << y << "] = ";
        cin >> a[i][j];
      }
    }
    cout << "Enter numbers in matrix 2" << endl;
    for(int i = 0; i < m2; i++){
      for(int j = 0; j < n2; j++){
        cout << "arr2[" << x << "][" << y << "] = ";
        cin >> b[i][j];
      }
    }
    for(int i = 0; i < m2; i++){
      for(int j = 0; j < n2; j++){
        c[i][j] = a[i][j] + b[i][j];
      }
    }
    cout << "Sum of matrix 1 and 2: << endl";
    for(int i = 0; i < m1; i++){
      for(int j = 0; j < n1; j++){
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
  }
  else{
    cout << "Matrix addition not possible" << endl;
  }
  return 0;
}
