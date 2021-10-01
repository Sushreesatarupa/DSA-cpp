#include<iostream>
#include<vector>
using namespace std;

vector <int> optimizedBubbleSort(vector<int> v){
    // your code  goes here
    int flag;
    for(int i=0;i<v.size()-1;i++){
        flag=0;
        for(int j=0;j<v.size()-1-i;j++){
            if(v[j]>v[j+1]) {
                swap(v[j], v[j+1]);
                flag=1;
            }        
    }
    if (flag==0) break;
    }
    
}