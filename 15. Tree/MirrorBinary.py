
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
def createNode(val):
    newNode = Node(0)
    newNode.val = val
    newNode.left = None
    newNode.right = None
    return newNode
 
# Helper function to print Inorder traversal
def inorder(root):
    if (root == None):
        return
    inorder(root.left)
    print( root.val, end = " ")
    inorder(root.right)
 
# mirrorify function takes two trees,
# original tree and a mirror tree
# It recurses on both the trees,
# but when original tree recurses on left,
# mirror tree recurses on right and
# vice-versa
def mirrorify(root, mirror):
 
    if (root == None) :
        mirror = None
        return mirror
     
    # Create new mirror node
    # from original tree node
    mirror = createNode(root.val)
    mirror.right = mirrorify(root.left,
                           ((mirror).right))
    mirror.left = mirrorify(root.right,
                          ((mirror).left))
    return mirror
 
# Driver Code
if __name__=='__main__':
 
    tree = createNode(5)
    tree.left = createNode(3)
    tree.right = createNode(6)
    tree.left.left = createNode(2)
    tree.left.right = createNode(4)
 
    # Print inorder traversal of the input tree
    print("Inorder of original tree: ")
    inorder(tree)
    mirror = None
    mirror = mirrorify(tree, mirror)
 
    # Print inorder traversal of the mirror tree
    print("\nInorder of mirror tree: ")
    inorder(mirror)
 
