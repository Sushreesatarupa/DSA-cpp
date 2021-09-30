#include<bits/stdc++.h>
 using namespace std;
// arr is input array of size n
 void InsertionSort(int arr[],int n ){
    for(int i=1; i<n; i++){
        int j=i,key=arr[i];
        while(key<arr[j-1]&&j>0){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=key;
    }   

 }
