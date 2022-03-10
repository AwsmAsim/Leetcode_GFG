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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, summ;
        ListNode* newHead = new ListNode(-1);
        ListNode *ptr = newHead;
        while(l1!=NULL and l2!=NULL){
            summ = l1->val + l2->val + carry;
            if(summ > 9){
                carry = summ / 10;
            }else{
                carry = 0;
            }
            ListNode* n1 = new ListNode(summ%10);
            ptr->next = n1;
            ptr = ptr -> next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1!=NULL){
            summ = l1->val + carry; 
            if(summ > 9){
                carry = summ / 10;
            }else{
                carry = 0;
            }
            ListNode* n1 = new ListNode(summ%10);
            ptr->next = n1;
            ptr = ptr -> next;
            l1=l1->next;
        }
        
        while(l2!=NULL){
            summ = l2->val + carry;  
            if(summ > 9){
                carry = summ / 10;
            }else{
                carry = 0;
            }
            ListNode* n1 = new ListNode(summ%10);
            ptr->next = n1;
            ptr = ptr -> next;
            l2 = l2->next;
        }
        if(carry != 0){
            ListNode* n1 = new ListNode(carry);
            ptr -> next = n1;
            ptr = ptr -> next;
        }
        
        return newHead->next;
    }
};