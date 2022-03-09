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
    ListNode* deleteDuplicates(ListNode* head) {
        
       ListNode* newHead = new ListNode(-1);
        int duplicate = 0;
        newHead->next = head;
        ListNode *t1 = newHead;
        
        while(t1!=NULL and t1->next!=NULL){
            
            ListNode* t2 = t1->next;
            duplicate = 0;
            
            while(t2->next!= NULL and t2->val == t2 -> next -> val){
                t2 = t2->next;
                duplicate = 1;
            }
            
            if(duplicate == 1) t1->next = t2->next;
            else t1 = t1->next;
        }
        
        return newHead->next;
        
    }
};