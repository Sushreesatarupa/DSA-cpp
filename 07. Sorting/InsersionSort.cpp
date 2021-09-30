
/*  Sayansree Paria
    email : sayansreeparia@gmail.com
    github : https://github.com/Sayansree
  
    Insertion sort algorithm
*/

#include<bits/stdc++.h>
 using namespace std;

//iterative implementation of Insertion sort
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

////recursive implementation of Insertion sort
  void RecursiveInsertionSort(int arr[],int n ){
    if(n==1)return;
        RecursiveInsertionSort(arr,n-1);
        int j=n-1,key=arr[n-1];
        while(key<arr[j-1]&&j>0){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=key;
 }


///test run code

 int main(){
    int arr[]={8,9,10,1,4,2,4,8,2,5};
    int d=2,n=sizeof(arr)/sizeof(int);
    for(int i:arr)
        cout<<i<<"\t";
        cout<<endl;
    RecursiveInsertionSort(arr,n);//sort
    for(int i:arr)
        cout<<i<<"\t";
     return 0;
}
