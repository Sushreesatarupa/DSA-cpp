/*Given an array of integers A .

A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.

Find the area of the largest rectangle formed by the histogram.

Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 1000000000


*/
int Solution::largestRectangleArea(vector<int> &A) {
    
    stack<int> st;
    int res = 0;
    int n = A.size();
    
    for(int i = 0; i < n; i++){
        
        while(!st.empty() && A[st.top()] >= A[i]){
            
            int tp = st.top();
            st.pop();
            int curr = A[tp] * (st.empty() ? i : (i - st.top() - 1));
            res = max(res, curr);
        }
        
        st.push(i);
    }
    
    while(!st.empty()){
        
        int tp = st.top();
        st.pop();
        
        int curr = A[tp] * (st.empty() ? n : (n - st.top() - 1));
        res = max(res, curr);
    }
    
    return res;
}