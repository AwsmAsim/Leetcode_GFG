/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == NULL) return NULL;
        if(head->next -> next == NULL){
            head->next = NULL;
            return head;
        };
        ListNode *slow = head, *fast = head, *prev = head;
        
        while(fast and fast->next and fast->next->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next) slow->next = slow->next->next;
        else prev->next = slow->next;
        
        
        
        return head;
    }
};