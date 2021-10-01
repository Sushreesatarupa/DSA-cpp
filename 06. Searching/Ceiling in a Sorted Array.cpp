#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll int M = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
     int *arr = new int[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int x;
    cin >> x;

    int low = 0, high = n - 1, mid, flag = 0;
    while (low <= high) {
      mid = (low + high) / 2;
      if (x == arr[mid]) {
        cout << "Ceiling of " << x << " is: " << mid << "\n";
        flag = 1;
        break;
      } else if (arr[mid] < x) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    if (flag == 0) {
      if (arr[mid] < x) {
        if ((mid + 1) > n - 1) {
          cout << "Ceiling of " << x << " doesn't exist in array\n";
          break;
        }
        cout << "Ceiling of " << x << " is: " << arr[mid + 1] << "\n";
      } else {
        if ((mid) > n - 1) {
          cout << "Ceiling of " << x << " doesn't exist in array\n";
          break;
        }
        cout << "Ceiling of " << x << " is: " << arr[mid] << "\n";
      }
    }

  }
  return 0;
}
