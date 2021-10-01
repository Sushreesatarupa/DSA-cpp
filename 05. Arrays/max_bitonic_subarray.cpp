//length of max bitonic subarray- 
//Given an array A[0 … n-1] containing n positive integers, a subarray A[i … j] is bitonic if 
//there is a k with i <= k <= j such that A[i] <= A[i + 1] … = A[k + 1] >= .. A[j – 1] > = A[j]
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i=-1, n, lmax = 1;
    cin>>n;
    int a[n];
    while(++i<n)
        cin>>a[i];

    i = 0; int posr = 0, posn = 0;   
    while(i<n-1)
    {
        while(i<n-1 && a[i]<a[i+1])
           i++; //gives posn of end of ascent
        while(i<n-1 && a[i]>a[i+1])
        {
            if(i<n-1 && a[i]>a[i+1])
               posn = i+1;
            i++;//gives posn of end of descent
        }
        if(lmax < posn - posr + 1)
        {
            fstart = posr; fend = posn;
            lmax = posn - posr + 1;
        }
        posr = posn; //posr- gives beginning of subarray
           
    }
    cout<<"Start and end positions of bitonic sub array: \n"<<fstart+1<<", "<<fend+1; //in layman format
    cout<<"\nLength: "<<lmax<<endl;
}
