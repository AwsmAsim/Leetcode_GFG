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
    
    ListNode* reverse(ListNode* head){
        ListNode *dummy = NULL, *next = NULL;
        
        while(head){
            next = head-> next;
            head -> next = dummy;
            dummy = head;
            head = next;
        }
        
        // cout << "Reversed List: " << endl;
        // cout << dummy-> val << " ";
        // if(dummy->next)cout << dummy -> next -> val << endl;
        
        return dummy;
    }
    
    bool solveDailyChallenge(ListNode* head){
        ListNode *slow = head, *fast = head;
        
        if(fast->next == NULL) return true;
        
        while(fast->next != NULL and fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        // cout << "Center at: " << slow->val << endl;
        
        slow ->next = reverse(slow->next);
        cout << "Print Linked List\n";
        // ListNode* t = head;
        // while(t){
        //     cout << t->val << ", ";
        //     t = t->next;
        // }
        // cout << endl;
        
        slow = slow->next;
        ListNode* cmp = head;
        
        while(slow!=NULL){
            if(slow->val != cmp->val) return false;
            slow = slow->next;
            cmp = cmp->next;
        }
        
        return true;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        return solveDailyChallenge(head);
    }
};