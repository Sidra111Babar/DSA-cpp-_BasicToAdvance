#include<iostream>
using namespace std;
class DoublyCircularLL{
private:
    class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data){
            this->data = data;
            next = NULL;
            prev = NULL;
        }
    };

    Node *head;
    Node *tail;

public:
    DoublyCircularLL(){
         head = NULL;
         tail = NULL;
    }
    void insertAtTail(int value);
    void insertAtHead(int value);
    void deleteATHead();
    void deleteATTail();
    bool isEmpty();
    void DisplayDCLL(Node *node);
    void Display_Wrapper();
    int count();
    void reverse_display_Wrapper();
    void reverse_DCLL(Node *current);
    void median_element(Node *start,Node *end);
    void median_Wrapper();
    void removeDuplicates();
    //code same as single Linked List(one difference is the usage of prev pointer)  AX_SingleLinkedList_RecursiveOperations.cpp
    //2nd method is double Linked List method AZ_DoubleLL_RecursiveOperations.cpp
    
    void insertAT_SpecificLoc(Node *current,int loc,int value,int currentCount = 1)
    {
    	if(loc <= 0){
		insertAtHead(value);
		return;
	}
	if(loc > count()){
			insertAtTail(value);
			return;
	}
    if (currentCount == loc) { 
        Node *newnode = new Node(value);
        newnode->next = current->next;
        newnode->prev = current;
        current->next->prev = newnode; 
        current->next = newnode; 
        return;
    }
		insertAT_SpecificLoc(current->next,loc,value,currentCount + 1);
	
	}
	void insertAT_SpecificLoc_Wrapper(int loc,int value){
		insertAT_SpecificLoc(head,loc,value);
	}
    void deleteAt_SpecificLoc(Node* current,int loc,int currentCount = 1){
    	if(isEmpty()){
    		cout << "Doubly Circular Linked list is empty\n";
    		return;
		}
    	if(loc <= 0){
		deleteATHead();
		return;
	}
    	if(loc > count()){
		deleteATTail();
		return;
	}
	 if (loc == currentCount) {
        Node *temp = current->next;
        current->next = temp->next;
        temp->next->prev = current;
        delete temp;
        return;
    }
	deleteAt_SpecificLoc(current->next,loc,currentCount + 1);
	     
	}
	void delete_atSpecific_loc_Wrapper(int loc){
		deleteAt_SpecificLoc(head,loc);
	}
    
};
void DoublyCircularLL::removeDuplicates() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node *current = head;
    do {
        Node *temp = current->next;
        while (temp != head) {
            if (temp->data == current->data) {
                Node *duplicate = temp;
                temp = temp->next;
                duplicate->prev->next = duplicate->next;
                duplicate->next->prev = duplicate->prev;
                delete duplicate;
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    } while (current != head);
}

void DoublyCircularLL::median_element(Node *start,Node* end){
	
 	if (start == end || start->next == end) {
        cout << "Middle element is: " << start->data << endl;
    } else {
        DoublyCircularLL::median_element(start->next, end->prev);
    }

}
void DoublyCircularLL::median_Wrapper(){
	if(DoublyCircularLL::isEmpty()){
		cout << "Doubly Circular Linked List is empty\n";
		return;
	}
    	DoublyCircularLL::median_element(head,tail);
}
void DoublyCircularLL::reverse_DCLL(Node *current){
	cout << current->data << " ";
	if(current == head){
		return;
	}
	DoublyCircularLL::reverse_DCLL(current->prev);
}
void DoublyCircularLL::reverse_display_Wrapper(){
	DoublyCircularLL::reverse_DCLL(tail);
	cout << endl;
}
int DoublyCircularLL::count(){
	if (isEmpty()) {
        return 0;
    }

    Node* temp = head;
    int count = 1;
    while (temp != tail){
    	temp = temp->next;
    	count++;
	}

    return count;
}

void DoublyCircularLL::deleteATTail(){
	 if (isEmpty()) {
        cout << "Doubly Circular Linked List is Empty\n";
        return;
    }
   // Case 1: Only one node
       if (head->next == head) {
            delete head;
            head = nullptr;
            return;
      }
	Node *temp= tail;
	tail = tail->prev;
	delete temp;
	head->prev = tail;
	tail->next = head;
}
void DoublyCircularLL::deleteATHead() {
    if (isEmpty()) {
        cout << "Doubly Circular Linked List is Empty\n";
        return;
    }
   // Case 1: Only one node
       if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            // More than one node
            Node* temp = head;
            
            head = head->next;
            
            delete temp;
            head->prev = tail;
            tail->next = head;
        }
}

bool DoublyCircularLL::isEmpty(){
	return (head == NULL);
}
void DoublyCircularLL::insertAtTail(int value){
	if (DoublyCircularLL::isEmpty()) {
        Node *newnode = new Node(value);
        head = newnode;
        head->next = head;
        head->prev = head;
        tail = head;
        return;
    }
    Node *newnode = new Node(value);
    newnode->prev = tail;
    tail->next = newnode;
    newnode->next = head;
    head->prev = newnode;
    tail = newnode;
}
void DoublyCircularLL::insertAtHead(int value) {
    if (DoublyCircularLL::isEmpty()) {
        Node *newnode = new Node(value);
        head = newnode;
        head->next = head;
        head->prev = head;
        tail = head;
    } else {
    	Node *newnode = new Node(value);
        Node* lastNode = head->prev;         
            newnode->next = head;            
            newnode->prev = lastNode;        
            lastNode->next = newnode;         
            head->prev = newnode;             
            head = newnode;
    }
}

void DoublyCircularLL::DisplayDCLL(Node *node) {
    if (isEmpty()) {
        cout << "Empty Doubly Circular Linked List\n";
        return;
    }
    cout << node->data << " ";
    if (node->next != head) {
        DisplayDCLL(node->next);
    }
    
}

void DoublyCircularLL::Display_Wrapper() {
    DisplayDCLL(head);
    cout << endl;
}


int main(){
	
   DoublyCircularLL dcll;
   dcll.Display_Wrapper();
   dcll.insertAtHead(1);
   dcll.insertAtTail(5);
    dcll.insertAtTail(4);
     dcll.insertAtTail(3);
     dcll.insertAtHead(2);
     dcll.insertAtHead(6);
   
   dcll.Display_Wrapper();
   dcll.deleteATHead();
   dcll.Display_Wrapper();
   dcll.median_Wrapper();  
   dcll.deleteATTail();
   dcll.Display_Wrapper();
   cout << dcll.count() << endl;
   cout << "Insert if loc < = 0\n";
   dcll.insertAT_SpecificLoc_Wrapper(0,7);
   dcll.Display_Wrapper();
   cout << "Insert if loc > count\n";
   dcll.insertAT_SpecificLoc_Wrapper(7,8);
   dcll.Display_Wrapper();
   cout << "Insert at third index\n";
   dcll.insertAT_SpecificLoc_Wrapper(3,9);
   dcll.Display_Wrapper();
   cout << "Delete at 3rd index\n";
   dcll.delete_atSpecific_loc_Wrapper(3);
   dcll.Display_Wrapper();
   cout << "Reverse Display\n";
   dcll.reverse_display_Wrapper();
   dcll.median_Wrapper();
   cout << "Insert at head\n";
   dcll.insertAtHead(5);
   dcll.Display_Wrapper();
   dcll.removeDuplicates();
   dcll.Display_Wrapper();
   
    return 0;
}

