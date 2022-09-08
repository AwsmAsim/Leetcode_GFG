# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        return self.inOrder(root, [])
    def inOrder(self, root, inOrd):
        if root is not None:
            self.inOrder(root.left, inOrd)
            inOrd.append(root.val)
            print(root.val)
            self.inOrder(root.right, inOrd)
        return inOrd
        
        