#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {} 
};

class LinkedList{
    public:
        Node* head;

        LinkedList() : head(nullptr) {}
        void display();
        void insertAtTail(int value);
        void insertInMiddle(int value);
        void deleteAtMiddle();
        void deleteAtTail();
        void insertInSortedOrder(int value);
        
};
void LinkedList::display(){
	if(head == nullptr)     
	{	                   
		cout << "Linked list is empty" << endl;
	}
	else
	{
		cout << "Elements in the Linked list are : ";
		Node *current = head; 
		while(current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;  
		}
		cout << endl;
	}
}
void LinkedList::insertAtTail(int value){
	    Node* newnode = new Node(value);  // Creation of a node
        if (head == NULL) {     // if Linked List is empty then make head as first node
            head = newnode;
            return;
        }
        Node* temp = head;  //In case linked list is not empty
        while (temp->next != NULL) {  //This loop will run until pointer will reach to the last node(last node's next is always equal to null)
            temp = temp->next;        // iteration start from head and in each iteration pointer will point to the next node
        }
        temp->next = newnode;   // When pointer will reach to the end of the linkedlist(last node) then while loop will terminate
                                // Now outside this while loop insert newnode at the next of last node
                                // This newnode has data and its next is equal to null(automatically because of constructor)
}
void LinkedList::insertInMiddle(int value){

        Node* fast = head;    
        Node* slow = head;
        Node* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;  // skip one node so fast will reach to the end of the linkedlist when slow is at the middle of the linkedlist
            prev = slow;
            slow = slow->next;
        }

        Node* newnode = new Node(value);

        // Adjust pointers to insert the new node in the middle(now slow is at the middle of the linked list)
        newnode->next = slow;
        if (prev != NULL) {
            prev->next = newnode;
        } else {
            head = newnode;  // This will run if linked list is empty(In this case make first node head)
        }
}
void LinkedList::deleteAtTail(){
	     if (head == NULL) {             
            cout << "No Node is present.\n";
            return;
        }

        // Special case: If there's only one node
        if (head->next == NULL) {
            delete head;
            head = NULL; // Set head to NULL as the list becomes empty
            return;
        }
        
        // Traverse the list until there is no node at the temp->next->next
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        // Now temp points to the second-to-last node
        delete temp->next; // Delete the last node
        temp->next = NULL; // Update the next pointer of the second-to-last node to NULL
}
void LinkedList::deleteAtMiddle(){
	if (head == NULL || head->next == NULL) {
            cout << "No middle node to delete.\n";
            return;
        }

        Node* fast = head;
        Node* slow = head;
        Node* prev = NULL; // This pointer will store the node that is just before the slow node

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        // Now slow points to the middle node
        if (prev != NULL) {
            prev->next = slow->next; // Update the next pointer of the node before the middle node
        } else {
            head = slow->next; // Update the head if the middle node is the first node
        }

        delete slow;
}
// Apply on new linked list no on already made linked list
void LinkedList::insertInSortedOrder(int value){
    Node* newnode = new Node(value);
    if(head == nullptr){
        head = newnode;
        return; // if the list is empty, the new node becomes the head and we're done
    }
    if(value < head->data){
        newnode->next = head;
        head = newnode;
        return; // if the value is less than head then swap head with newnode
    }

    Node* current = head;
    while(current->next != nullptr && current->next->data < value){   
    /*cout << "Enter in while loop " << endl;*/
        current = current->next;
        /*cout << current->data << endl;*/
    }

    newnode->next = current->next;
    current->next = newnode;
}

int main(){
    LinkedList list;
    LinkedList list2;
   cout << "Insert at the middle.\n";
    list.insertInMiddle(1);
    list.display();
    cout << "Insert at tail.\n";
    list.insertAtTail(7);
    list.insertAtTail(6);
    list.insertAtTail(8);
    list.insertAtTail(3);
    list.display();
    cout << "Insert at the middle.\n";
    list.insertInMiddle(2);
    list.display();
     cout << "Insert at the middle.\n";
    list.insertInMiddle(9);
    list.display();
    cout << "Delete at Tail.\n";
    list.deleteAtTail();
    list.display();   
    cout << "Insertion of elements in sorted order.\n";
    list2.insertInSortedOrder(1);
    list2.insertInSortedOrder(2);
    list2.insertInSortedOrder(0);
    list2.insertInSortedOrder(4);
    list2.insertInSortedOrder(3);
    list2.display();
    
    
  
    
    return 0;
}

