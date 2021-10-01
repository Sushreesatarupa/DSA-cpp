
#include<bits/stdc++.h>
using namespace std;

//leniar search of element on array arr of size n
//time : O(n)
//space : O(1) 
int LeniarSearch(int arr[],int element,int n){
    for(int i=0; i<n;i++)
        if(arr[i]==element)
            return i; 
    return -1;
}

//binary search of elemet on sorted array arr or size hi
//iterative approach
//time : O(log(n))
//space : O(1) 
int BinarySearch(int arr[],int element,int hi){
    int lo=0;hi--;
    while(hi>=lo){
        int mid=(hi+lo)/2;
        if(arr[mid]==element)
            return mid; 
        else if(arr[mid]<element)
            lo=mid+1;
        else
            hi=mid-1;
    }
    return -1;
}
