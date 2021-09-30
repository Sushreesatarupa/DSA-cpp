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
