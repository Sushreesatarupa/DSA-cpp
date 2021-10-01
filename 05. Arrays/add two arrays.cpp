#include<iostream>
using namespace std;
int main()
{
  int first[20], second[20], sum[20], c, n;
 
  cout << "Enter the number of elements in the array ";
  cin >> n;

  cout << "Enter elements of first array" << endl;

  for (c = 0; c < n; c++)
    cin >> first[c];

  cout << "Enter elements of second array" << endl;

  for (c = 0; c < n; c++)
    cin >> second[c];

  cout << "Sum of elements of the arrays:" << endl;

  for (c = 0; c < n; c++) {
    sum[c] = first[c] + second[c];
    cout << sum[c] << endl;
  }
  return 0;
}
