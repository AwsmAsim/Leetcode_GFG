# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def addNode(self, val, leftChild, rightChild):
        newNode = TreeNode(val, leftChild, rightChild);
        return newNode
        
    def solve(self, root, val, depth):
        if root == None: return None
        if depth == 1:
            root.left = self.addNode(val, root.left, None)
            root.right = self.addNode(val, None, root.right)
        
        self.solve(root.right, val, depth-1)
        self.solve(root.left, val, depth-1)
    
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1: return self.addNode(val, root, None)
        self.solve(root, val, depth-1)
        return root