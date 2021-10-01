/* Greedy Algorithm Assign Cookies
You want to give your children some cookies. But, you should give each child at most one cookie.
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. maximize the number of your content children and output the maximum number.

Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1

Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2

*/
#include<stdlib.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int k=0,i=0,childrenss=0;
        while(i<s.size()&&k<g.size()){
    if(s[i]>=g[k]){
        k++;
        i++;
        childrenss++;
    }
            else{
        i++;
        }
        }
    return childrenss;}
int main(){
    int x,z;
    vector<int> s;
    vector<int> po;
    cin>>x>>z;
    for(int p=0;p<x;p++){
        int values;
        cin>>values;
        s.push_back(values);
    }  for(int p=0;p<z;p++){
        int values;
        cin>>values;
        po.push_back(values);
    }
    cout<<findContentChildren(s,po);
    return 0;
}
