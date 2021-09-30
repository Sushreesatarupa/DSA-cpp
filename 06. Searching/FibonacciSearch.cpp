#include<iostream>
using namespace std;

//fibonacci search of elemet on sorted array arr of size n
//iterative approach
//time : O(log(n))
//space : O(1) 
//f(n)~c*1.62^n
//O(log₁.₆₂(n)) not better than Binary search O(log₂(n))
int FibonacciSearch(int arr[], int n, int element){
    int f2=0;
    int f1=1;
    int f0=f2+f1;

    while(f0<n){
        f2=f1;
        f1=f0;
        f0=f1+f2;
    }
    int offset=-1;
    while(f0>1){
        int i = min(offset+f2,n-1);
        if(arr[i]<element){
            f0=f1;
            f2=f0-f2;
            f1=f0-f2;
            offset=i;
        }
        else if(arr[i]>element){
            f0=f2;
            f1=f1-f2;
            f2=f0-f1;
        }
        else return i;
    }
    if (arr[n-1] == element)
            return n-1;
    return -1;
}
int main(){
    int arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
    int n=sizeof(arr)/sizeof(int);
    for (int i=0;i<=n;i++)
    {
        if(i!=FibonacciSearch(arr,n,i))
            cout<<"failled at "<<i<<" with output "<<FibonacciSearch(arr,i,n)<<endl;
    }
    cout<<endl;
}