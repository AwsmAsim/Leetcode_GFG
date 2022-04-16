/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    
    Node* solve(Node* head){
        Node *temp = head, *newNext, *prevNext;
        while(temp!=NULL){
            if(temp->child != NULL){
                prevNext = temp->next;
                temp -> child -> prev = temp;
                temp -> next = temp -> child;
                newNext = solve(temp->child);
                newNext -> next = prevNext;
                if(prevNext!=NULL)
                prevNext -> prev = newNext;
                temp -> child = NULL;
                temp = newNext;
            }
            if(temp->next == NULL) break;
            temp = temp -> next;
        }
        
        return temp;
    }
    
public:
    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};