//Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
//If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

//Example 1:

//        Input:
 //               1
 //               /   \
//            2       3
//            /   \   /   \
//        4      5 6      7
//                    \      \
//                    8      9      

//        Output: 
//        4 2 1 5 6 3 8 7 9 
//Explanation:

//Example 2:

 //       Input:
 //           1
 ///           /    \
 //       2       3
 //       /    \      \
 //       4      5      6

 //       Output: 4 2 1 5 3 6

//TIME COMPLEXITY- O(N)
//SPACE COMPLEXITY- O(N)

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    
        vector<int> verticalOrder(Node *root) {
        map<int, vector<int>> m;
        queue<pair<Node*, int>> q;   //QUEUE TO STORE THE ROOT NODE AND ITS POSITION
        vector<int> res;   // VECTOR TO STORE THE RESULT
        
        q.push({root, 0});
        
        while (!q.empty()) {
            
            Node* t = q.front().first;  //STORING THE CURRENT ROOT NODE 
            int h= q.front().second;    //STORING THE POSITION OF THE ROOT NODE
              
            q.pop();
            
            if (t == nullptr)
                continue;
                
            m[h].push_back(t->data);       //PUSHING THE NODES DATA INTO THE MAP
             
            q.push({t->left, h - 1});     //TAKING THE POSITION OF THE LEFT NODE DECREASED BY 1
            q.push({t->right, h + 1});   //TAKING THE POSITION OF THE LEFT NODE INCREASED BY 1
        }
        
        for (auto x : m) {
            for (auto v : x.second)res.push_back(v);
        }
        
        return res;
    }
};
