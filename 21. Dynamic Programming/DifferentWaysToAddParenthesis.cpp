/*
Problem can be found here : https://leetcode.com/problems/different-ways-to-add-parentheses/

Problem Statement :
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

Example 1:
  Input: expression = "2-1-1"
  Output: [0,2]
  Explanation:
  ((2-1)-1) = 0 
  (2-(1-1)) = 2

Example 2:
  Input: expression = "2*3-4*5"
  Output: [-34,-14,-10,-10,10]
  Explanation:
  (2*(3-(4*5))) = -34 
  ((2*3)-(4*5)) = -14 
  ((2*(3-4))*5) = -10 
  (2*((3-4)*5)) = -10 
  (((2*3)-4)*5) = 10
  
  
  
Approach :
  The problem uses simple recursive approach
  Placing brackets can be seen as evaluating expression for each operation
  1+2-3+4 => (1+2)-(3+4)  => placing bracket == evaluating left and right half and operating it with operator
  1) loop over expression 
  2) if an operator is found : recur for left and right half to find all possible values that can be obtained from both side expressions standalone
  3) for all values on left:
        for all values on right:
            operate with current operator and add result to ret vector
            
            
     finally return the ret vector
   4) to improve complexity : we memoize intermediate results in a map of string vs vector : stores the diff ways that can be there to put brackets in this expression
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> dp(string str,map<string,vector<int>>&dpMap){
   if (dpMap.count(str)>0)
       return dpMap[str];
        
   vector<int>ret;
        
   //consider if ith char is operator then call for left and right half and evaluate all possible combinations
   for (int i=0;i<str.length();++i){
        if (str[i]=='+' or str[i]=='-' or str[i]=='*'){
             vector<int>lef = dp(str.substr(0,i),dpMap),
                        right = dp(str.substr(i+1),dpMap);
             // diff ways to solve left and right half
          
             // now operate with possible operators
             for (int& x1:lef) for (int& x2:right){
                 if (str[i]=='+') ret.emplace_back(x1+x2);
                 else if (str[i]=='-') ret.emplace_back(x1-x2);
                 else ret.emplace_back(x1*x2);
             }
        }
    }
        
    if (ret.empty()) // base case => totally numeric string
        return {stoi(str)};
        
    return ret;
}


vector<int> diffWaysToCompute(string expression) {        
    map<string,vector<int>>dpMap;
    return dp(expression,dpMap);
}


int main(){
  string s;
  cin>>s;
  vector<int> ans = diffWaysToCompute(s);
  for (auto x:ans)
    cout<<x<<" ";
  
  return 0;
}
    
