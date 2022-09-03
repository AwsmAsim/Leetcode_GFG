# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        if head.next is None:
            return head
        
        dummy, nxt = None, None # Intialising dummy and nxt
        curNode = head # head node ko current Node --> curNode bol diya
        
        # Given linked list say --> 1 -> 2 -> None
        while curNode is not None:
            nxt = curNode.next #pehle asli next node store karli
            # 1     ->   2     ->    None
            # ^curNode   ^ nxt
            curNode.next = dummy 
            # None   <-  1      2    ->    None
            # ^ dummy    ^ curNode
            dummy = curNode
            # None   <-  1      2    ->    None
            #            ^ dummy ab ye hai jo pehle curNode tha
            curNode = nxt
            # None   <-  1      2    ->    None
            #            ^dummy ^ curNode ab ye hai, jo pehle nxt tha
            
        return dummy