Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

        Input:
                1
                /   \
            2       3
            /   \   /   \
        4      5 6      7
                    \      \
                    8      9      

        Output: 
        4 2 1 5 6 3 8 7 9 
Explanation:

Example 2:

        Input:
            1
            /    \
        2       3
        /    \      \
        4      5      6

        Output: 4 2 1 5 3 6
        
        
# TIME COMPLEXITY

O(N)

# SPACE COMPLEXITY

O(N)
