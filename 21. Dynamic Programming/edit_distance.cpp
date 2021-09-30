/*Given two strings str1 and str2. You can perform 3 operations on str1. i.e,

Insert a character
Remove a character
Replace a character
The cost of all the above operations is the same. Find the minimum number of operations that are required to convert ‘str1’ into ‘str2’.
Example:

Input: str1="sitting",  str2="kitten"
Output: 3
Explanation: 2 Replace and 1 Remove operation can be performed, i.e, replace character 's' with 'k' and character 'i' with 'e' and remove last character 'g'. 

Constraints: 1<=n,m<=2000

Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/

#include<bits/stdc++.h>
using namespace std;
// Recursive DP with Memoization (Top Down Approach) 

vector<vector<int>> dp(2005,vector<int>(2005,-1));
int edit_distance(string str1, string str2, int n, int m)
{
    // If string 2 is empty then remove all character of string 1
    if(m==0) return n;  
    // If string 1 is empty then insert all character of string 2
    if(n==0) return m;  

    int &ans=dp[n][m];
    // If dp[i][j] is already computed before then return result else store 
    if(ans!=-1) return ans;    

    //If at ith index both are same no operations needed to be performed 
    if(str1[n-1]==str2[m-1]) {
        return ans=edit_distance(str1,str2,n-1,m-1); 
    }
    // Consider all possible Operations 
    int insert = edit_distance(str1,str2,n,m-1); 
    int remove = edit_distance(str1,str2,n-1,m);
    int replace = edit_distance(str1,str2,n-1,m-1); 

    return ans=1+min({insert,remove,replace});
}

int main() {
    string str1, str2; cin>>str1>>str2;
    int n=str1.size(), m=str2.size();
    int ans=edit_distance(str1,str2,n,m);
    cout<<"The answer is: "<<ans;
    return 0;
}
