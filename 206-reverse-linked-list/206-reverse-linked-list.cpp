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
    
    ListNode* solve(ListNode* head){
        ListNode* d = NULL;
        
        while(head != NULL){
            ListNode* next = head->next;
            head->next = d;
            d = head;
            head = next;
        }
        
        return d;
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        return solve(head);
    }
};