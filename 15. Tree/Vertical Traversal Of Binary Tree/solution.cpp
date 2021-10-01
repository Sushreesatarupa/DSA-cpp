class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    
        vector<int> verticalOrder(Node *root) {
        map<int, vector<int>> m;
        queue<pair<Node*, int>> q;
        vector<int> res;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            
            Node* t = q.front().first; 
            int h= q.front().second;
            
            q.pop();
            
            if (t == nullptr)
                continue;
                
            m[h].push_back(t->data);
            
            q.push({t->left, h - 1});
            q.push({t->right, h + 1});
        }
        
        for (auto x : m) {
            for (auto v : x.second)res.push_back(v);
        }
        
        return res;
    }
};