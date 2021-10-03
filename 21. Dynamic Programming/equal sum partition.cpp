#include<iostream>
using namespace std;
bool subset_sum(int arr[],int sum,int n)
{
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            t[i][j]=false;
            if(j==0)
            t[i][j]=true;
        }
    }
     for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
            else
            t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}
int main()
{
    int arr[]={1,3,5,9};
    int s=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        s=s+arr[i];
    }
    if(s%2!=0)
    std::cout << "false" << std::endl;
    else
   { int flag=subset_sum(arr,s/2,n);
    if(flag)
    cout<<"true"<<endl;
    else
    cout<<"no"<<endl;
       
   }
    
}