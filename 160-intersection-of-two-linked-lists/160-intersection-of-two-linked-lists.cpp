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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_set<ListNode*> listASet;
        
        ListNode* temp1 = headA;
        
        while(temp1){
            listASet.insert(temp1);
            temp1 = temp1->next;
        }
        
        temp1 = headB;
        
        while(temp1){
            
            if(listASet.find(temp1)!=listASet.end()){
                return temp1;
            }
            
            temp1 = temp1->next;
        }
        
        return NULL;
        
    }
};