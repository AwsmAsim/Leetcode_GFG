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
    
    ListNode* solve(ListNode* l1, ListNode* l2){
        ListNode* temp = NULL;
        
        if(l1->val < l2->val){
            temp = l1;
            l1 = l1 -> next;
        } 
        else{
            temp = l2;
            l2 = l2 -> next;
        }
        
        ListNode* sortedListNode = temp;
        
        while(l1 and l2){
            if(l1->val < l2->val){
                temp -> next = l1;
                l1 = l1->next;
            }else{
                temp -> next = l2;
                l2 = l2 -> next;
            }
            temp = temp->next;
        }
        
        // cout << " Out of Loop 1:" << endl;
        
        while(l1){
            temp-> next = l1;
            l1 = l1->next;
            temp = temp -> next;
        }
        
        while(l2){
            temp -> next = l2;
            l2 = l2-> next;
            temp = temp->next;
        }
        
        
        return sortedListNode;
    }
    
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL and list2 == NULL) return NULL;
        if(list1 == NULL ) return list2;
        if(list2 == NULL) return list1;
        return solve(list1, list2);
    }
};