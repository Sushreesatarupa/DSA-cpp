#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<'='<<x<<endl;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define ll long long
int binary_expo(int a,int b);
int dp[1001][1001];
int mod=1e9+7;
void solve()
{
    int n;
    cin>>n;
    string s[n+1];    
    for(int i=0;i<n;i++)
    {
      cin>>s[i];
    }

    
     dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
         if(i) dp[i][j]+=dp[i-1][j];
         if(j) dp[i][j]+=dp[i][j-1];
         if(s[i][j]=='*')
         {
           dp[i][j]=0;
         }
         dp[i][j]=dp[i][j]%mod;

      }
    }
    cout<<dp[n-1][n-1]<<endl;
     
} 
 
int main()
{
 
fastio();
/* #ifndef ONLINE_JUDGE
freopen(     ,  ,stdin);
freopen(     ,   ,stdout);
#endif */
 
solve();
return 0;
 
}
 
 int binary_expo(int a,int b)
{
     int result=1;  
   while(b>0){             
     if(b%2!=0){   result=result*a;  }           
        a=a*a;      
         b=b/2;  
          } 
return result; 
}