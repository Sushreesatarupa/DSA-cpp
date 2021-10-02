#include<iostream>
#include <bits/stdc++.h>
 
#include<vector> 
using namespace std;
class Solution {
public:
int min(int a,int b)
{
    if(a<b)
    return a; 
    else
    return b;
}
int subset_sum(int arr[],int range,int n)
{
    bool t[n+1][range+1];
     vector<int>v;
    int ans=INT_MAX;  
    int mid=range/2;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<range+1;j++)
        {
            if(i==0)
            t[i][j]=false;
            if(j==0)
            t[i][j]=true;
        }
    }
     for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<range+1;j++)
        {
            if(arr[i-1]<=j)
            t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
            else
            t[i][j]=t[i-1][j];
        }
    }
   
    for(int j=1;j<mid+1;j++)
    {
        if(t[n][j]==true)
        {
            v.push_back(j);
        }
    } 
    for(int i:v)
    {
        ans=min(ans,range-(2*i));
    }
    return ans;
}
};
int main()
{
    Solution ob;
    int arr[]={1,3,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    cout<<ob.subset_sum(arr,sum,n);
}