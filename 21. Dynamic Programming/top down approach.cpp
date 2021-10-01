#include <iostream>
using namespace std;
class starry
{
   public: 

int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
};

int main() {
    // Write C++ code here
    starry ob;
    int n,w;  //n is the size of array and w is the given wt
    cin>>n>>w;
    int val[n],wt[n],t[n+1][w+1];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];  //wt array
    }
     for(int i=0;i<n;i++)
    {
        cin>>val[i];//value array
    }
     for(int i=0;i<n+1;i++)
    {
         for(int j=0;j<w+1;j++)
        {
           if(i==0||j==0)
           t[i][j]=0;
        }  
    }
    for(int i=1;i<n+1;i++)
    {
         for(int j=1;j<w+1;j++)
        { 
            if(wt[i-1]<=j)//given sub wt is less than actual wt 
            
                t[i][j]=ob.max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);//either we can choose or not
            
            else
            t[i][j]=t[i-1][j];//sub wt is more hence not choose 
        }
    }
    cout<<t[n][w]<<endl;//max profit at last cell of the t array

    return 0;
}