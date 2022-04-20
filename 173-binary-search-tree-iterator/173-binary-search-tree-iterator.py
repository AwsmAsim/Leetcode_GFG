# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def inorder(self, root):
        if(root == None): return None
        self.inorder(root.left)
        self.inorder_list.append(root.val)
        self.inorder(root.right)
    
    
    def __init__(self, root: Optional[TreeNode]):
        self.inorder_list = []
        self.P1 = -1
        self.inorder(root)

    def next(self) -> int:
        self.P1 += 1
        return self.inorder_list[self.P1]

    def hasNext(self) -> bool:
        if self.P1>=len(self.inorder_list)-1:
            return False
        return True


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()