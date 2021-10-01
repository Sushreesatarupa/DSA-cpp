//Given a matrix of size r*c. Traverse the matrix in spiral form.
//Input:
//    r = 4, c = 4
//    matrix[][] = {{1, 2, 3, 4},
//           {5, 6, 7, 8},
//           {9, 10, 11, 12},
//           {13, 14, 15,16}}
//Output: 
//    1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

#include <bits/stdc++.h> 
using namespace std; 
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> vec;
        int k=0,m=r,l=0,n=c;
//        while loop for rows and column traversal
        while(k<m && l<n){
            for(int i=l;i<n;i++){
                vec.push_back(matrix[k][i]);
            }
            k++;
            for(int i=k;i<m;i++){
                vec.push_back(matrix[i][n-1]);  
            }
            n--;
            if(k<m){
                for(int i=n-1;i>=l;i--){
                    vec.push_back(matrix[m-1][i]);  
                }
                m--;
            }
            if(l<n){
                for(int i=m-1;i>=k;i--){
                    vec.push_back(matrix[i][l]);  
                }
                l++;                
            }
        }
        
        return vec;
    }
};
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  
