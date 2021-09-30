#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

struct Trie{
     Trie *left, *right;
     Trie() {
         left = right = NULL;
     }
};

class Solution{   
public:

    void insert(Trie *root, int key) {
        Trie *temp = root;
        
        for (int i=31;i>=0;i--) {
            int b = key & (1 << i);
            if (b == 0) {
                if (!temp->left) {
                    temp->left = new Trie();    
                }
                temp = temp->left;
            } else {
                if (!temp->right) {
                    temp->right = new Trie();
                }
                temp = temp->right;
            }
        }
        
    }

    int helper(Trie *root, int key) {
        Trie *temp = root;
        
        int ans = 0;
        
        for (int i=31;i>=0;i--) {
            int b = key & ( 1 << i );
            if (b == 0) {
                if (temp->left) {
                    temp = temp->left;
                    ans += 0;
                } else {
                    temp = temp->right;
                    ans += pow(2, i);
                }
            } else {
                if (temp->right) {
                    temp = temp->right;
                    ans += 0;
                } else {
                    temp = temp->left;
                    ans += pow(2, i);
                }
            }
        }
        return ans;
    }

    int minxorpair(int N, int arr[]){    
        
        Trie *root = new Trie();
        
        insert(root, arr[0]);
        
        int ans = INT_MAX;
        
        for (int i=1;i<N;i++) {
            ans = min(ans, helper(root, arr[i]));
            insert(root, arr[i]);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.minxorpair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends