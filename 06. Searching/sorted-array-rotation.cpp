//How many times  a sorted array has been rotated
/*Condition: The array doesnot contain duplicate elements

2 3 5 6 12 89
12 89 2 3 5 6     Circularly sorted array
Rotated twice Anticlockwise*/


#include<iostream>
using namespace std;
int FindRotationCount(int arr[],int n){
    int low=0,high=n-1;
    while(low<=high){
        if(arr[low]<=arr[high]) return low;
        int mid=(low+high)/2;
        int next=(mid+1)%n,prev=(mid+n-1)%n;
        if((arr[mid]<=arr[prev])&&(arr[mid]<=arr[next])) return mid;
        else if(arr[mid]>=arr[low]) low=mid+1;
        else if(arr[mid]<=arr[high]) high=mid-1;
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"No of times array is rotated:"<<FindRotationCount(arr,n);
    return 0;
}

