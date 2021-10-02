#include<iostream>
#include<vector>
using namespace std;

// function for bubble sort
vector <int> optimizedBubbleSort(vector<int> v){
    // your code  goes here
    int flag; // declaring a variable which will keep track if the swaping is done or not
    for(int i=0;i<v.size()-1;i++){
        flag=0; // intializing flag with value 0
        for(int j=0;j<v.size()-1-i;j++){
            if(v[j]>v[j+1]) {
                swap(v[j], v[j+1]);
                flag=1;
            }        
    }
    if (flag==0) break; // if no swapping done that means array is already sorted
    }
    
    
}
