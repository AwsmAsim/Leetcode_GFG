/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    
    class Node{
        public:
        int data;
        Node* next;
        Node(int data){ 
            this->data = data;
            next = NULL;
        }
    };
    
    Node* head;
    
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    head = new Node(-1);
        Node* temp = head;
        for(auto a: nums){
            Node *n1 = new Node(a);
            temp -> next = n1;
            temp = temp -> next;
        }
        head = head->next;
        // temp = head;
        // while(temp!= NULL){
        //     cout << temp->data <<", ";
        //     temp = temp -> next;
        // }
        // cout << endl;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return head->data;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int data = head -> data;
        head = head->next;
        // cout << "next data: " << head->data << endl;
	    return data;
	}
	
	bool hasNext() const {
        if(head == NULL) return false;
	    return true;
	}
};