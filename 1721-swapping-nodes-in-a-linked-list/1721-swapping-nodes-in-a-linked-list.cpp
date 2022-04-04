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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head->next == NULL) return head;
        
        ListNode *first, *last=head, *temp = head;
        --k;
        while(k){
            temp = temp -> next;
            --k;
        }
        first = temp;
        while(temp->next!=NULL){
            temp = temp->next;
            last = last->next;
        }
        int t = first->val;
        first->val = last->val;
        last->val = t;
        return head;
    }
};