#include <iostream>
using namespace std;

int sum_of_array(int n, int arr[])
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return arr[n - 1] + sum_of_array(n - 1, arr);
    }
}    
int main()
{
    int n, arr[10];
    cin >> n; 
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << sum_of_array(n, arr);
    return 0;
}
