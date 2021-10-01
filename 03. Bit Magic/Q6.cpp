#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
    public: 
    
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        
        vector<int> res;
        int i=0,k=0,l=0;
        int m= r;
        int n= c;
        
        while(k< m && l<n){
            for(i=l;i<n;i++){
                res.push_back(matrix[k][i]);
            }
            k++;
            
            for(i=k;i<m;i++){
                res.push_back(matrix[i][n-1]);
            }
            n--;
            
            if(k<m){
                for(i = n-1;i >=l;i--){
                    res.push_back(matrix[m-1][i]);
                }
                m--;
            }
            
            if(l <n ){
                for(i=m-1 ;i>=k;i--){
                    res.push_back(matrix[i][l]);
                }
                l++;
            }
            
        }
        
        return res;
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
