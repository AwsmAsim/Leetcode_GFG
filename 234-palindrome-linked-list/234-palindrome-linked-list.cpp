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
    
    ListNode* reverseList(ListNode* n1){
        
        ListNode* d = NULL;
        
        while(n1){
            ListNode* next = n1->next;
            n1->next = d;
            d = n1;
            n1 = next;
        }
        
        return d;
    }
    
    bool solve(ListNode* head){
        ListNode *slow = head, *fast = head;
        
        while(fast!= NULL and fast->next != NULL and fast->next->next != NULL){
            slow = slow -> next;
            fast = fast->next->next;
        }
        
        // cout << "slow fast loop" << endl;
        
        // slow Node is the centre node.
        slow -> next = reverseList(slow->next);
        
        // int n = slow -> next -> val;
        // cout << "valie at slow: " << n << endl;
        
        // PRINT NODE
        // ListNode* t = head;
        // while(t != nullptr){
        //     int n = t -> val;
        //     cout << (n) << endl;
        //     t = t->next;
        //     cout << t << endl;
        // }
        
        if(fast != NULL) slow = slow -> next;
        
        fast = head;
        
        while(slow!=NULL){
            if((fast->val) != (slow->val)) return false;
            slow = slow->next;
            fast = fast -> next;
        }
        
        return true;
        
    }
    
public:
    bool isPalindrome(ListNode* head) {
        
        return solve(head);
    }
};