/* Question:
    Given a sorted array A[] of N positive integers having all the numbers occurring exactly twice, 
    except for one number which will occur only once. Find the number occurring only once.
    
    Example 1:

    Input:
    N = 5
    A = {1, 1, 2, 5, 5}
    Output: 2
    Explanation: 
    Since 2 occurs once, while
    other numbers occur twice, 
    2 is the answer.
    
    Example 2:

    Input:
    N = 7
    A = {2, 2, 5, 5, 20, 30, 30}
    Output: 20
    Explanation:
    Since 20 occurs once, while
    other numbers occur twice, 
    20 is the answer.
*/    

#include<bits/stdc++.h>

using namespace std;

int search(int a[], int N){
    //code
    int ans = 0;
    for(int i=0;i<N;i++)
    {

        ans^=a[i];
    }
    return ans;
}

int main()
{

    int a[7] = {2, 2, 5, 5, 20, 30, 30};
    cout<<search(a,7);
}
