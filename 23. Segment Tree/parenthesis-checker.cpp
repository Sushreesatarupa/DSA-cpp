
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        int n= x.length();
        stack <char> a;
        int d=0,b=0;
        if(x[0]=='}' || x[0]==')'||x[0]==']') return false;
        for(int i=0;i<n;i++){
            if(x[i]=='{' || x[i]=='('||x[i]=='[') d++;
            if(x[i]=='}' || x[i]==')'||x[i]==']') b++;
        }if(d!=b)return false;
        for(int i=0;i<n;i++){
            if(x[i]=='{' || x[i]=='('||x[i]=='[') 
              a.push(x[i]);
            if(x[i]=='}' || x[i]==')'||x[i]==']') {
              if ((x[i]=='}' && a.top()=='{') || (x[i]==')' && a.top()=='(')||(x[i]==']' && a.top()=='[')) {
                a.pop();
                }   
            }
        }
        if(a.size()==0) return true;
        else return false;
    }
};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
