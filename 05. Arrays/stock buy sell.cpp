//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        
      //2D vector store all the buy sell days
         vector<vector<int> > allBuySellDays;
      
      //Vector to store each buysellday
        vector<int> buySellDay;
        
        //min stores the minimum value at which stocks can be bought
        //max stores the miaxmum value at which stocks can be sold
        int min=0, max=0, maximumProfit=0;
        
        for(int i=1;i<n;i++)
        {
            
            if(A[i]<A[min])
            {
                if(maximumProfit != 0)
                {
                    maximumProfit=0;
                  
                    //push elements into vector
                    buySellDay.push_back(min);
                    buySellDay.push_back(max);
                    allBuySellDays.push_back(buySellDay);
                    buySellDay.clear();
                    
                }
                min=i,max=i;
            }
            else
            {
                if(A[max]>A[i]  && maximumProfit != 0)
            	{
					          maximumProfit=0;
                  
                    //push elements into vector
                    buySellDay.push_back(min);
                    buySellDay.push_back(max);
                    allBuySellDays.push_back(buySellDay);
                  
                  //clear the vector
                    buySellDay.clear();
                    min=i,max=i;
				}
				else
                max=i;
            }
            if(maximumProfit <(A[max]-A[min]))
            {
                maximumProfit= A[max]-A[min];
            }
        }
        
        if(maximumProfit != 0)
                {
                    //push elements into vector
                    buySellDay.push_back(min);
                    buySellDay.push_back(max);
                    allBuySellDays.push_back(buySellDay);
                    buySellDay.clear();
                }
                
    return allBuySellDays;
        
    }
};

// { Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}

  // } Driver Code Ends//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
         vector<vector<int> > allBuySellDays;
        vector<int> buySellDay;
        
        int min=0, max=0, maximumProfit=0;
        
        for(int i=1;i<n;i++)
        {
            if(A[i]<A[min])
            {
                if(maximumProfit != 0)
                {
                    maximumProfit=0;
                    //push elements into vector
                    buySellDay.push_back(min);
                    buySellDay.push_back(max);
                    allBuySellDays.push_back(buySellDay);
                    buySellDay.clear();
                    
                }
                min=i,max=i;
            }
            else
            {
                if(A[max]>A[i]  && maximumProfit != 0)
            	{
					maximumProfit=0;
//                    cout<<min<<max<<endl;
                    //push elements into vector
                    buySellDay.push_back(min);
                    buySellDay.push_back(max);
                    allBuySellDays.push_back(buySellDay);
                    buySellDay.clear();
                    min=i,max=i;
				}
				else
                max=i;
            }
            if(maximumProfit <(A[max]-A[min]))
            {
                maximumProfit= A[max]-A[min];
            }
        }
        
        if(maximumProfit != 0)
                {
                    //push elements into vector
                    buySellDay.push_back(min);
                    buySellDay.push_back(max);
                    allBuySellDays.push_back(buySellDay);
                    buySellDay.clear();
                }
                
    return allBuySellDays;
        
    }
};

// { Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}

  // } Driver Code Ends
