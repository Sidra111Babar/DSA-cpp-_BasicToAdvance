#include<iostream>
using namespace std;

class Node {
    public:
    int value;
    Node* next; 
    Node(int n) : value(n), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    void insertValue_atBegining(int value);
    bool isLinkedLists_identical(LinkedList& other);
    void middle_LinkedlistElement();   // Time complexity is greater than the array
    void moveLastElment_toFront();
    void display_Linkedlist();
    void make_middlenode_head();
};
void LinkedList::display_Linkedlist()
{
	if(head == nullptr)     // if head is equal to null then it means that list is empty and constructor 
	{	                   // will automatically initialize it to null after the creation of object in main
		cout << "Linked list is empty" << endl;
	}
	else
	{
		cout << "Elements in the Linked list are : ";
		Node *current = head; // current initialized with the head (current points to the first node in the linkedlist)
		while(current != nullptr)// means that until last node because last node has address null
		{
			cout << current->value << " ";
			current = current->next;  // Update current after each iteration
		}
		cout << endl;
	}
}

void LinkedList::insertValue_atBegining(int value) {
    Node* newnode = new Node(value);
    newnode->next = head; 
    head = newnode;
}

bool LinkedList::isLinkedLists_identical(LinkedList& other) {
    Node* current1 = head;
    Node* current2 = other.head;

    // Traverse both lists and compare elements
    while (current1 != nullptr && current2 != nullptr) {
        if (current1->value != current2->value)
            return false;
        current1 = current1->next;
        current2 = current2->next;
    }

    // If both current pointers are nullptr, lists are identical
    return (current1 == nullptr && current2 == nullptr);
}
void LinkedList::middle_LinkedlistElement() {
    if(head == nullptr) {
        cout << "LinkedList is empty "<< endl;
        return;
    }
      // Usage of two pointers to make the logic
    Node* slow = head;   
    Node* fast = head;   
    
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;             // simple code to move the node forward by one time
        fast = fast->next->next;      // move the node forward by two times
    }
// As fast node will end soon and slow node is at the middle of the linkedlist and while loop wil terminate 
// when fast node will reach to the end of the linked list, at this point value at slow node wil print
    cout << "Element in the middle of linked list is " << slow->value << endl;
}
void LinkedList::moveLastElment_toFront()
{
	if (head == nullptr || head->next == nullptr) {
            cout << "Linked List is empty or has only one element" << endl;
            return;
        }

        Node* secondlast = nullptr;     //second last is set to null
        Node* last = head;              // initially last is set to head

        // Traverse to find the last and second-to-last node
        while (last->next != nullptr) {
            secondlast = last;   // Is is updated to second last in each teration
            last = last->next;  // last is one step forward to the second last
        }

        // Update pointers to move the last element to the front
        secondlast->next = nullptr; // Disconnect the last node from the list as last node has data address null
        last->next = head; // Connect the last node to the original head 
        head = last; // Update the head to the last node (because in this case head has reached to the last node

}

void LinkedList::make_middlenode_head() {
    if (head == nullptr || head->next == nullptr) {
        cout << "Linked list is empty or has only one node" << endl;
        return;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    // Find the middle node using slow and fast pointers
    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Disconnect the middle node from the list
    prev->next = slow->next;

    // Connect the middle node to the original head
    slow->next = head;

    // Update the head pointer to point to the middle node
    head = slow;
}

int main() {
    int no_elements;
    cout << "How many no of elements you want to add in the linked list ";
    cin >> no_elements;

    LinkedList list1, list2;

    cout << "Insert elements in the first linked list: ";
    for (int i = 0; i < no_elements; i++) {
        int user_input;
        cin >> user_input;
        list1.insertValue_atBegining(user_input);
    }
    cout << "Insert " << no_elements << " elements in the second linked list: ";
    for (int i = 0; i < no_elements; i++) {
        int user_input;
        cin >> user_input;
        list2.insertValue_atBegining(user_input);
    }

    if (list1.isLinkedLists_identical(list2))
        cout << "Both linked lists are identical." << endl;
    else
	{
        cout << "Linked lists are not identical." << endl;
    }
    list1.display_Linkedlist();
     cout << "All operations will be apply on the first linked list " << endl;
    list1.middle_LinkedlistElement();
    list1.moveLastElment_toFront();
    cout << "Linked list after moving last element in the front of the linked list" << endl;
    list1.display_Linkedlist(); 
    cout << "Middle Node at the front of the Linked list " << endl;
    list1.make_middlenode_head();
    list1.display_Linkedlist();
     
    
    return 0;
}

