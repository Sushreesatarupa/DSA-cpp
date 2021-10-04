//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string> graycode(int n)
    {
    	vector<string> gray,temp;
    	gray.push_back("0");
    	gray.push_back("1");
        string str="";
    	for(int i=0;i<n-1;i++)
    	{
    		for(int j=0;j<gray.size();j++)
            {
                str='0';
    			temp.push_back(str+gray[j]);
    		}
    		for(int j=gray.size()-1;j>=0;j--)
    		{
    		    str='1';
    			temp.push_back(str+gray[j]);
    		}
    		gray=temp;
    		temp.clear();
	    }
	    return gray;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        Solution ob;
        vector<string> ans= ob.graycode(n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";

        cout<<"\n";
    }
}



  // } Driver Code Ends
