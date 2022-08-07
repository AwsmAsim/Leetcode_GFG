/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head, *fast = head;
        
        while(fast != NULL and fast -> next != NULL){
            slow = slow->next;
            fast = fast-> next -> next;
            if(fast == slow){
                ListNode* newHead = head;
                while(newHead != slow){
                    slow = slow -> next; 
                    newHead = newHead -> next;
                }
                return newHead;
            }
        }
        
        return NULL;
        
    }
};