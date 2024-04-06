#include <iostream>

using namespace std;

// Define the node structure
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

// Define the circular linked list class
class CircularLinkedList {
private:
    Node* head;
    
public:
    CircularLinkedList() : head(nullptr) {}
    // Function to display the circular linked list
    void display() {
        if (!head) {
            cout << "List is empty" << endl;
            return; 
        }
        
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    void insertAtStart(int value) {
    Node *newnode = new Node(value);
    if (head == NULL) {
        newnode->next = newnode; // Point to itself
        head = newnode;
    } else {
        Node* current = head;
        while (current->next != head){  
            current = current->next;
        } 
        // current is equal to second last node in this case
        current->next = newnode;
        newnode->next = head;
        head = newnode;
      }
   }
     //To insert a node at the end of a circular linked list, 
	 //you need to traverse the list until you find the last node, 
	 //then make the next pointer of the last node point to the new node, 
	 //and finally make the next pointer of the new node point back to the head of the list
	void insertat_End(int value){
		//creation of node
		Node *newnode = new Node(value);
		//if head is null linked list is mepty ake head first node and that's set
		if(head == NULL){
		   head = newnode;
		   newnode->next = newnode;
		   return;// if this condition is true then no need to run the code below to improve time complexity
		} 
		Node* current = head;
		while(current->next != head){
			current = current->next;
		}
		// loop will terminate in this case current is equal to second last node
		current->next = newnode;
		newnode->next = head;
	}
void insertInBetween(int value) {
    Node *newnode = new Node(value);
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        Node *fast = head;
        Node *slow = head;
        Node *prev = NULL;
        while (fast->next != head && fast->next->next != head) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = newnode;
        newnode->next = slow;
    }
}
void deleteAt_Head() {
    if (head == NULL) {
        cout << "Linked List is Empty.\n";
        return; // Added return to exit the function if the list is empty
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    // Update the next pointer of the new head to maintain the circular nature of the list
    if (head != NULL) {
        Node* current = head;
        while (current->next != temp) {
            current = current->next;
        }
        current->next = head;
    }
}

void deleteAt_Tail() {
    if (head == NULL) {
        cout << "Linked List is Empty.\n";
        return;
    }

    Node* current = head;
    Node* prev = NULL;

    // Traverse until the second last node
    while (current->next != head) {
        prev = current;
        current = current->next;
    }

    // Now 'current' points to the last node and 'prev' points to the second last node

    // If there's only one node in the list
    if (current == head) {
        delete current;
        head = NULL;
    } else {
        prev->next = current->next; // Skip the last node
        delete current; // Delete the last node
    }
}

void deleteAT_Middle() {
    if (head == NULL) {
        cout << "Linked List is empty.\n";
        return;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    while (fast != NULL && fast->next != head) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
        if (fast == head || fast->next == head) {
            // If fast pointer reaches back to head or the next node after fast is head
            break;
        }
    }

    // Now 'slow' points to the middle node
    if (prev != nullptr) {
        prev->next = slow->next; // Skip the middle node
    } else {
        // If prev is still NULL, it means the list contains only one node
        head = slow->next; // Update head if deleting the only node in the list
    }
    delete slow; // Delete the middle node
}

};

int main() {
    CircularLinkedList list;
    
    // Inserting elements into the circular linked list
    list.insertAtStart(1);
    list.insertAtStart(2);
    list.insertAtStart(3);
    cout << "Circular Linked List: ";
    list.display();
    cout << "Insert 0 and 5 at end.\n";
    list.insertat_End(0);
    list.insertat_End(5);
    
    // Displaying the circular linked list
    cout << "Circular Linked List: ";
    list.display();
    cout << "Insert 4 in between.\n";
    list.insertInBetween(4);
    list.display();
    cout << "Delete at Head.\n";
    list.deleteAt_Head();
    list.display();
    cout << "Delete at Head.\n";
    list.deleteAt_Head();
    list.display();
    cout << "Delete at Middle.\n";
    list.deleteAT_Middle();
    list.display();
    cout << "Delete at Middle.\n";
    list.deleteAT_Middle();
    list.display();
    cout << "Delete at Tail.\n";
    list.deleteAt_Tail();
    list.display();
    
    
    return 0;
}

