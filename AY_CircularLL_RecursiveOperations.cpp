#include<iostream>
using namespace std;
//selete at tail (include delete at head)
class Recursive_CircularLL{
	private:
		class Node{
			public:
				int data;
				Node *next;
				Node(int data){
					this->data = data;
					next = NULL;
				}
		};
	Node *head;
	Node *tail;
	public:
		Recursive_CircularLL(int data){
			head = new Node(data);
			tail = head;
			tail->next = head;			
		}
		 void insertAtTailRecursively(Node* current,int data) {

        if (current->next == tail) { // If we reach the last node
            tail->next = new Node (data);
        tail = tail->next;
        tail->next = head;
        return;
        }
        insertAtTailRecursively(current->next,data);
        
    }
    void insertAtTail(int data){
        	insertAtTailRecursively(head,data);
		}
     void insertAtHead(int data) {
         Node * temp = new Node (data);
        temp->next = head;
        head = temp;
        tail->next = head;
    }
    int count(){
    	Node *temp = head;
    	int count = 1;
    	while(temp != tail){
    		count++;
    		temp = temp->next;
		}
	return count;	
	}
    void insertAtSpecificNode_recursively(Node* current,int data,int loc,int currentCount = 1){
    	if(loc > count()){
    		insertAtTail(data);
    		return;
		}
		if(loc <= 0){
			insertAtHead(data);
			return;
		}
		if(loc == currentCount){
			Node *newnode = new Node(data);
            newnode->next = current->next;
            current->next = newnode;
            return;
		}
		insertAtSpecificNode_recursively(current->next,data,loc,currentCount + 1);
	}
	void inserAt_SpecificNode(int data,int loc){
		insertAtSpecificNode_recursively(head,data,loc);
	}
	void displayRecursively(Node* current) {
        cout << current->data << " ";

        if (current->next != head)  // Stop when we reach the head again
            displayRecursively(current->next);
    }
    void deleteAtTail_Recursively(Node *current, Node *prev) {
    if (current->next == head) { // If the next node is the head node (only one node in the list)
        delete tail;
        head = nullptr;
        tail = nullptr;
        return;
    }
    if (current->next == tail) { // If the next node is the tail node
        delete tail;
        tail = current;
        tail->next = head; // Update tail to point to the head
        return;
    }
    deleteAtTail_Recursively(current->next, current);
}

void deleteAtTail() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete tail." << endl;
        return;
    }
    deleteAtTail_Recursively(head, nullptr);
}

   void deleteATSpecificLoc_Recursively(int loc, Node *current, Node *prev, int currentCount = 1) {
    if (loc <= 0) {
        cout << "Node is out of range\n";
        return;
    }
    if (loc > count()) {
        deleteAtTail();
        return;
    }
    if (loc == 1) { 
        Node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
        return;
    }
    if (currentCount == loc) { 
        prev->next = current->next;
        if (current == tail) {
            tail = prev;
        }
        delete current;
        return;
    }
    deleteATSpecificLoc_Recursively(loc, current->next, current, currentCount + 1);
}

void deleteATSpecific_loc(int loc) {
    deleteATSpecificLoc_Recursively(loc, head, NULL);
}

    void display() {
        cout << "Circular Linked List: ";
        displayRecursively(head);
        cout << endl;
    }
    // same as singly Linked list while loop condition will change(head ! = tail)
    // https://github.com/Sidra111Babar/DSA-cpp-_BasicToAdvance/blob/main/AE_LinkedListInserton_Deletion.cpp
    //Insert at middle, delete at middle or find middle element (use slow and fast pointers same as )
    // stop at the middle
    //delete at middle (reach at the middle node) skip one node and delete that node and make connection of prev node to the nex of skipeed node
    
};


int main(){
	Recursive_CircularLL CRLL(1);
	CRLL.insertAtHead(2);
	CRLL.insertAtHead(3);
	CRLL.insertAtHead(4);
	CRLL.display();
	CRLL.insertAtTail(5);
	CRLL.insertAtTail(6);
	CRLL.display();
	cout << "Node Count is : " << CRLL.count() << endl;
	CRLL.inserAt_SpecificNode(7,0);
	CRLL.display();
	CRLL.inserAt_SpecificNode(8,10);
	CRLL.display();
	CRLL.inserAt_SpecificNode(9,5);
	CRLL.display();
	CRLL.inserAt_SpecificNode(10,8);
	CRLL.display();
	CRLL.inserAt_SpecificNode(11,10);
	CRLL.display();
	cout << "Delete\n";
	CRLL.deleteATSpecific_loc(5);
	CRLL.display();
	CRLL.deleteATSpecific_loc(6);
	CRLL.display();
	cout << "Delete at head\n";
	CRLL.deleteAtHead();
	CRLL.display();
	return 0;
}
