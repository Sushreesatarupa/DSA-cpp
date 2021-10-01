#include <bits/stdc++.h>
using namespace std;

// can practice this problem here : https://leetcode.com/problems/longest-palindromic-substring/

/*
Problem Statement :
  Given a string s, return the longest palindromic substring in s.

  Example 1:

  Input: s = "babad"
  Output: "bab"
  Note: "aba" is also a valid answer.
  Example 2:

  Input: s = "cbbd"
  Output: "bb"
*/


/*
Approach :
 let's say we consider string from index i to j
 now dp state :
    s[i..j] is palindrome if and only if s[i+1][j-1] is palindrome and these 2 new terminal characters (s[i] and s[j]) are equal !
    
    for each substring i,j we recur (with base conditions on indices) and by apply condition of palindrome as per dp state
    we now return , and while returning we store the intermediate results (here result = length of palindrome)
    these results are used to solve more subproblems if repeated or overlapped
    
    Time Complexity : O(n2)
    Space Complexity : O(n2)
    
 */

string s,str; //str will contain the lps : Which is updated on each call if longer palindrome is found
int memo[1005][1005]; //initialize global memo dictionary
int len=0; 
    
bool dp(int i,int j){
    if (i>j) return 0; //base case
         
    if (i==j || j-i==1) { //base case
        if (memo[i][j]==1 and j-i+1>len){
            len = j-i+1;
            str=s.substr(i,j-i+1);
        }
        return memo[i][j];
    }
        
    if (memo[i][j]!=-1) //check if already calculated
        return memo[i][j];
        
    memo[i][j] = (dp(i+1,j-1) && (s[i]==s[j])); //memoizing the result
    
  if (memo[i][j]==1 and j-i+1>len){ // if a s[i][j] is palindrome then check if it's length is greater than existing max length
      len = j-i+1;
      str = s.substr(i,len);
  }
  
  return memo[i][j];  
}
    
string longestPalindrome(string ss) { 
  int n = ss.length();
  memset(memo,-1,sizeof memo); // initialize memo dict
  s = ss;
        
  for (int i=0;i<n;++i){ // as all substring of length 1 are palindrome
     memo[i][i]=1;
     if (i+1<n) memo[i][i+1]= (s[i]==s[i+1]);  // substring of length 2 are palindrome if both characters equal
  }
        
  len=1;str=s.substr(0,1);
  for (int i=0;i<=n-2;++i){
      for (int j=i;j<=n-1;++j) dp(i,j); // finding length of longest palindrome for substring s[i..j]
  }
  return str;
}


int main(){
  string s;
  cin>>s;
  cout<<longestPalindrome(s)<<'\n';
  
  return 0;
}
