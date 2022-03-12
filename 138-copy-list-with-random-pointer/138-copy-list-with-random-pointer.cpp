/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    // void printList(Node *head){
    //     cout << "List: ";
    //     while(head!=NULL){
    //         cout << head->val << ", ";
    //         head = head -> next;
    //     }
    //     cout << "\n";
    // }
public:
    Node* copyRandomList(Node* head) {
        Node *newHead = NULL, *tail = NULL;
        Node *tmp = head;
        unordered_map<Node*, Node*> nodes;
        unordered_map<Node *, bool> possibleHead;
        
        nodes[NULL] = NULL;
        while(tmp!=NULL){
            Node *n1 = new Node(tmp->val);
            if(newHead == NULL){
                newHead = n1;
                newHead->next = tmp -> next;
                tail = newHead;
            }
            else{
                tail = n1;
                tail->next = tmp->next;
                tail = tail->next;
            }
            nodes[tmp] = n1;
            possibleHead[n1] = true;
            tmp = tmp->next;
        }
        
        Node* tmp1 = newHead;

        while(head!=NULL){
            nodes[head]->random = nodes[head->random]; 
            nodes[head]->next = nodes[head->next];
            head = head -> next;
        }
        
        // for(auto itr: possibleHead){
        //     if(itr.second){
        //         newHead = itr.first;
        //         break;
        //     }
        // }
        
        // printList(newHead);
        
        
        return newHead;
        // return head;
    }
};