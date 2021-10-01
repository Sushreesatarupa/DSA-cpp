class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    
        vector<int> verticalOrder(Node *root) {
        map<int, vector<int>> m;    
        queue<pair<Node*, int>> q;   //queue to store the node and its position starting with 0 assigned to root
        vector<int> res;     //vector to store the result
        
        q.push({root, 0});  
        
        while (!q.empty()) {
            
            Node* t = q.front().first;    //storing the root node in a node
            int h= q.front().second;       //storing the position of the particular root node
            
            q.pop();
            
            if (t == nullptr)
                continue;
                
            m[h].push_back(t->data);    //pushing the root nodes data in the data, at that particular positiom
            
            q.push({t->left, h - 1});     //decreasing the position by 1 for the left nodes
            q.push({t->right, h + 1});       //increasing the position by 1 for the right nodes
        }
        
        for (auto x : m) {
            for (auto v : x.second)res.push_back(v);
        }
        
        return res;
    }
};
