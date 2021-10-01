/* C++ Solution 
 * Problem Link: https://www.codechef.com/problems/BILLRD/
 * About: The question is based on coordinate system.
 */

//Header files
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long int
using namespace std;

//Fuction to solve test case;
void solve()
{
   ll n, k, x, y;
   cin>>n>>k>>x>>y;
   if (x == y)
   {
      x = n;
      y = n;
      cout<<x<<" "<<y<<endl;
   }
   else
   {
      ll q = k % 4;
      if (x > y)
      {
        switch(q)
        {
           case 0: cout<<x-y<<" "<<0<<endl; break;              
           case 1: cout<<n<<" "<<y+n-x<<endl; break;
           case 2: cout<<y+n-x<<" "<<n<<endl; break;
           case 3: cout<<0<<" "<<x-y<<endl; break;
        }
      }
      else if (y > x)
      {
        switch(q)
        {
           case 0 : cout<<0<<" "<<y-x<<endl; break;
           case 1 : cout<<x+n-y<<" "<<n<<endl; break;
           case 2 : cout<<n<<" "<<x+n-y<<endl; break;
           case 3 : cout<<y-x<<" "<<0<<endl; break;                    
        }
      }
    }
}

//Drived code
int main()
{
   fast;
   int t;
   cin>>t;

   while (t--)
   {
     solve();
   }
}
