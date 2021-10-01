#include <bits/stdc++.h>
using namespace std;

/*
    Author : Aarti Rathi
*/

int main()
{
    int m,n;
    cout<<"Enter the length of array 1 : ";
    cin>>m;

    cout<<"\nEnter the length of array 2 : ";
    cin>>n;
    
    int arr1[m],arr2[n];

    cout<<"\nEnter the values of array 1 \n";
    for(int i=0;i<m;i++)
    {
        cin>>arr1[i];
    }
    cout<<"\nEnter the values of array 2 \n";
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    
    int i = 0, j = 0, k = m - 1;
    while (i <= k && j < n) 
    {
        if (arr1[i] < arr2[j])
            i++;
        else {
            swap(arr2[j++], arr1[k--]);
        }
    }

    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);

    cout << "After Merging \nFirst Array: ";
    for (int i = 0; i < m; i++)
        cout << arr1[i] << " ";
    cout << "\nSecond Array: ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    return 0;
}


/* 

OUTPUT :

Enter the length of array 1 : 6

Enter the length of array 2 : 4

Enter the values of array 1 
1
5
9
10
15
20

Enter the values of array 2 
2
3
8
13
After Merging 
First Array: 1 2 3 5 8 9 
Second Array: 10 13 15 20

*/