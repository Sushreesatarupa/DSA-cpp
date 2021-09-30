//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++



class Solution{   
public:
    #define INT_SIZE 32 
  
// A Trie Node 
struct TrieNode 
{ 
    int value;  // Only used in leaf nodes 
    TrieNode *arr[2]; 
}; 
  
// Utility function to create a Trie node 
TrieNode *newNode() 
{ 
    TrieNode *temp = new TrieNode; 
    temp->value = 0; 
    temp->arr[0] = temp->arr[1] = NULL; 
    return temp; 
} 
  
// Inserts pre_xor to trie with given root 
void insert(TrieNode *root, int pre_xor) 
{ 
    TrieNode *temp = root; 
  
    // Start from the msb, insert all bits of 
    // pre_xor into Trie 
    for (int i=INT_SIZE-1; i>=0; i--) 
    { 
        // Find current bit in given prefix 
        bool val = pre_xor & (1<<i); 
  
        // Create a new node if needed 
        if (temp->arr[val] == NULL) 
            temp->arr[val] = newNode(); 
  
        temp = temp->arr[val]; 
    } 
  
    // Store value at leaf node 
    temp->value = pre_xor; 
} 
  
// Finds the maximum XOR ending with last number in 
// prefix XOR 'pre_xor' and returns the XOR of this maximum 
// with pre_xor which is maximum XOR ending with last element 
// of pre_xor. 
int query(TrieNode *root, int pre_xor) 
{ 
    TrieNode *temp = root; 
    for (int i=INT_SIZE-1; i>=0; i--) 
    { 
        // Find current bit in given prefix 
        bool val = pre_xor & (1<<i); 
  
        // Traverse Trie, first look for a 
        // prefix that has opposite bit 
        if (temp->arr[1-val]!=NULL) 
            temp = temp->arr[1-val]; 
  
        // If there is no prefix with opposite 
        // bit, then look for same bit. 
        else if (temp->arr[val] != NULL) 
            temp = temp->arr[val]; 
    } 
    return pre_xor^(temp->value); 
} 
  
// Returns maximum XOR value of a subarray in arr[0..n-1] 
int maxSubarrayXOR(int N, int arr[]) 
{ 
    // Create a Trie and insert 0 into it 
    TrieNode *root = newNode(); 
    insert(root, 0); 
  
    // Initialize answer and xor of current prefix 
    int result = INT_MIN, pre_xor =0; 
  
    // Traverse all input array element 
    for (int i=0; i<N; i++) 
    { 
        // update current prefix xor and insert it into Trie 
        pre_xor = pre_xor^arr[i]; 
        insert(root, pre_xor); 
  
        // Query for current prefix xor in Trie and update 
        // result if required 
        result = max(result, query(root, pre_xor)); 
    } 
    return result; 
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
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends