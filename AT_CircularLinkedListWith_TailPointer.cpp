#include<iostream>
using namespace std;
class CLinkedList{
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
	Node *head = NULL;
	Node *tail;
	public:
		CLinkedList(int data){
			head = new Node(data);
			tail = head;
			tail->next = head;
		}
		void insertATHead(int data);
		void insertAtTail(int data);
		void insertAnywhere(int data,int loc);
		void deleteAtHead();
		void deleteAtTail();
		void deleteAnywhere(int loc);
		void display();
		bool isEmpty();
};
bool CLinkedList::isEmpty(){
	return head == NULL;
}
void CLinkedList::insertATHead(int data){
    if(isEmpty()){
    	return;
	}
	Node *newnode = new Node(data);
	newnode->next = head;
	head = newnode;
	tail->next = head;
}
void CLinkedList::insertAtTail(int data){
	Node *newnode = new Node(data);
	tail->next = newnode;
	tail = tail->next;    // newnode = tail (wrong logic)
	tail->next = head;
	
}
void CLinkedList::insertAnywhere(int data, int loc) {
    Node *newnode = new Node(data);
    Node *current = head;
    
    // Check if the list is empty or if loc is 0
    if (CLinkedList::isEmpty() || loc == 1 || loc < 0) {
        CLinkedList::insertATHead(data);
        return;
    }
    
    int count = 1; // Start count from 1 since we've already checked the head
    while (current->next != NULL) {
        if (count == loc) {
            newnode->next = current->next;
            current->next = newnode;
            if (current == tail) {
                tail = newnode; // Update tail if inserting at the end
            }
            return;
        }
        current = current->next;
        count++;
    }
    
    // If loc is greater than the number of elements in the list,
    // insert at the end
   // current->next = newnode;    (To make it a generic code use functions in function)
    //tail = newnode;
    CLinkedList::insertAtTail(data);
}

void CLinkedList::deleteAtHead(){
	Node *temp = head;
	head = head->next;
	tail->next = head;
	delete temp; // te,p is know a dangling pointer(pointed to deallocated memory)
	temp = NULL; // when it is null now it is not a dangling pointer
}
void CLinkedList::deleteAtTail(){
	Node *temp = head;
	while(temp->next != tail){
		temp = temp->next;
	}
	delete tail;
	tail = temp;                  // errored logic temp->next = tail;
	tail->next = head;
	
}
void CLinkedList::deleteAnywhere(int loc) {
    // Check if the list is empty
    if (CLinkedList::isEmpty()) {
        return; // Nothing to delete
    }
    
    // If loc is 0, delete the head
    if (loc <= 0 || loc == 1) {
        CLinkedList::deleteAtHead();
        return;
    }
    
    Node *current = head;
    Node *prev = NULL;
    int count = 1;
    
    do {
        if (count == loc) {
            // Found the node to delete
            prev->next = current->next;
            if (current == tail) {
                tail = prev; // Update tail if deleting the last node
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
        count++;
    } while (current != head); // Loop until we come back to the head
    
    // If loc is greater than the number of elements in the list,
    // delete at the tail
    if (loc >= count) {
        CLinkedList::deleteAtTail();
    }
}

void CLinkedList::display(){
	if(isEmpty()){
		return;
	}
		Node *temp = head;
	 do
        {
        
            cout << temp->data << endl;
            temp= temp->next;
        }
        while(temp != head);
        
}

int main(){
	CLinkedList ll(4);
	ll.insertATHead(3);
	ll.insertATHead(1);
	ll.insertAtTail(2);
	ll.display();
	cout << "Delete at Head\n";
	ll.deleteAtHead();
	ll.display();
	cout << "Delete at Tail\n";
	ll.deleteAtTail();
	ll.display();
	ll.insertATHead(9);
	ll.insertAtTail(5);
	cout << "LL\n";
	ll.display();
	cout << "Insert 6 in Linked List after position 4\n";
	ll.insertAnywhere(6,4);
	cout <<"LL\n";
	ll.display();
		cout << "Insert 7 in Linked List after position 4\n";
	ll.insertAnywhere(7,4);
	cout <<"LL\n";
	ll.display();
		cout << "Insert 8 in Linked List at position 1\n";
	ll.insertAnywhere(8,1);
	cout <<"LL\n";
	ll.display();
		cout << "Insert 10 in Linked List after position 7\n";
	ll.insertAnywhere(10,7);
	cout <<"LL\n";
	ll.display();
	cout << "Delete at position 1\n";
	ll.deleteAnywhere(1);
	ll.display();
	cout << "Delete at position 2\n";
	ll.deleteAnywhere(2);
	ll.display();
	cout << "Delete at position 4\n";
	ll.deleteAnywhere(4);
	ll.display();
	cout << "Delete at position 9\n";
	ll.deleteAnywhere(9);
	ll.display();
	return 0;
}
