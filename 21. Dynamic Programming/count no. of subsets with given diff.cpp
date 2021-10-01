#include <iostream>
using namespace std;                                 //TARGET SUM IS SAME AS THIS
class starry
{
    public:
    int count (int arr[],int sum,int n)
    {
        int t[n][sum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                t[i][j]=0;
                if(j==0)
                t[i][j]=1;
            }
        }
         for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
              if(arr[i-1]<=j)
              t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
              else
              t[i][j]=t[i-1][j];
            }
        }
        return t[n][sum];
              
              
    }
};   
int main()
{
    starry ob;
    int arr[]={1,1,2,3};
    int diff=1;
    int n=sizeof(arr)/sizeof(arr[0]);
    int total_sum=0,sum;
    for(int i=0;i<n;i++)
    {
        total_sum+=arr[i];
    }
    sum=(diff+total_sum)/2;
    cout<<ob.count(arr,sum,n);
}