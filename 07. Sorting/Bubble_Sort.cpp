//Bubble sort Code
/*By Pratyaksh Khurana*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //fast I/O
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    //size of array
    int n;  
    cin>>n;
    int array[n];

    //add elements in array 
    for (int i = 0; i < n; i++)
      cin>>array[i];
    
    //algorithmic approach
    for (int j = 0; j < n-1; j++)
    {
        for (int i = 0; i < n-1; i++)
        {
            if(array[i] > array[i+1])
            {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
    
    //printing the array
    for (int i = 0; i < n; i++)
      cout<<array[i]<<" ";

    return 0;
}

/*
Time Complexity 
Best Case - O(n) i.e sorted initially
Worst Case - O(n*n) 
*/
