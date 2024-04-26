#include<iostream>
using namespace std;
// include homework in this file
//Insert and delete in middle in Linked List
//2. Find in linked list
//3. Sort linked list
class Recursive_SinlgeLL{
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
	public:
		Recursive_SinlgeLL(int data){
			head = new Node(data);
		}
		void insertAThead(int data);
		void inserAtTail_Recursively(int data,Node *current);
		void insertAtTail(int data);
		void displaySLL_Recursively(Node *node);
		void display();
		void deleteATHead();
        int count();
		void deleteAtTail_Recursively(Node *temp,Node *current);
		void removeatTail();
		void delete_atMiddle_Rec(Node *node,Node *fast,Node *slow);
		void delete_atMiddle_Wrapper();
		void insert_atMiddle_Rec(int user_data,Node *prev,Node *fast,Node* slow);
		void insert_atMiddle_Wrapper(int data);
		void deleteat_SpecificLoc_Rec(int loc,Node *&current,int currentcount = 1){
			if (loc > count()) {
             removeatTail();
            return;
        }
        if (loc <= 0) {
            deleteATHead();
            return;
        }
        /* if (loc == 1) {
            Node* temp = current;
            current = current->next;
            delete temp;
            return;
        }*/
        if (currentcount  == loc) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            return;
        }
        deleteat_SpecificLoc_Rec(loc, current->next, currentcount + 1);
		}
		void deleteAt_specificloc(int loc){
			deleteat_SpecificLoc_Rec(loc,head);
		}
		void insertAtSpecificLoc_Rec(int data, int loc, Node* current, int currentcount = 1) {
        if (loc > count()) {
            insertAtTail(data);
            return;
        }
        if (loc <= 0) {
            insertAThead(data);
            return;
        }
        if (loc == currentcount) {
            Node* newnode = new Node(data);
            newnode->next = current->next;
            current->next = newnode;
            return;
        }
        insertAtSpecificLoc_Rec(data, loc, current->next, currentcount + 1);
    }

    void inserAtSpecificloc(int data, int loc) {
        insertAtSpecificLoc_Rec(data, loc, head);
    }
    
};
void Recursive_SinlgeLL::deleteATHead(){
	Node *temp = head;
	head = head->next;
	delete temp;
	temp == NULL;
}
void Recursive_SinlgeLL::insertAThead(int data){
	Node *newnode = new Node(data);
	newnode->next = head;
	head = newnode;
}
void Recursive_SinlgeLL::displaySLL_Recursively(Node* node) {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        displaySLL_Recursively(node->next);
}
void Recursive_SinlgeLL::display() {
        displaySLL_Recursively(head);
        cout << endl;
}
void Recursive_SinlgeLL::deleteAtTail_Recursively(Node *temp, Node *current) {
	// if Linkedlist is empty
    if (current == nullptr) {
        return;
        
    }
	//reached at last node
	else if (current->next == nullptr) {
		// one node case 
        if (temp == nullptr) {
            delete current;
            head = nullptr;
        } 
		else {
            delete current;
            temp->next = nullptr;
        }
        return;
    }
    deleteAtTail_Recursively(current, current->next);    //current ko next me bhej kay phly waly ko current kr dya ha
}

void Recursive_SinlgeLL::removeatTail() {
    deleteAtTail_Recursively(nullptr, head);
}
int Recursive_SinlgeLL::count(){
	int count = 0;
	Node *temp = head;
	while(temp!= NULL){
		temp = temp->next;
		count++;
	}
	return count;
}

void Recursive_SinlgeLL::inserAtTail_Recursively(int data,Node *current){
	if(current->next== NULL){
		Node *newnode = new Node(data);
	    current->next = newnode;
     	newnode->next = NULL;
		return;
	}
	Recursive_SinlgeLL::inserAtTail_Recursively(data,current->next);
}
void Recursive_SinlgeLL::insertAtTail(int data){
	Recursive_SinlgeLL::inserAtTail_Recursively(data,head);
}


void Recursive_SinlgeLL::delete_atMiddle_Rec(Node *prev, Node *fast, Node *slow) {
    int nodeCount = Recursive_SinlgeLL::count();
    if (nodeCount <= 2) {
        cout << "Deletion at middle is impossible. Number of nodes: " << nodeCount << endl;
        return;
    }

    if (fast == nullptr || fast->next == nullptr) {
        prev->next = slow->next;
        delete slow;
        return;
    }

    Recursive_SinlgeLL::delete_atMiddle_Rec(slow, fast->next->next, slow->next);
}

void Recursive_SinlgeLL::delete_atMiddle_Wrapper() {
    Recursive_SinlgeLL::delete_atMiddle_Rec(nullptr, head, head);
}
// ye code middle se ak step agaya ja kr insert krny ga so ak previous pointer ki b zrorat ha
void Recursive_SinlgeLL::insert_atMiddle_Rec(int user_data,Node *prev, Node *fast, Node *slow) {
    if (fast == nullptr || fast->next == nullptr) {
        Node *newnode = new Node(user_data);
        newnode->next = slow;
        prev->next = newnode;
        return;
    }

    Recursive_SinlgeLL::insert_atMiddle_Rec(user_data,slow, fast->next->next, slow->next);
}

void Recursive_SinlgeLL::insert_atMiddle_Wrapper(int data) {
    Recursive_SinlgeLL::insert_atMiddle_Rec(data,nullptr, head, head);
}
		
int main(){
	Recursive_SinlgeLL RSLL(1);
	RSLL.insertAThead(2);
	RSLL.insertAThead(3);
	RSLL.insertAThead(4);
	RSLL.insertAThead(5);
	RSLL.display();
	RSLL.removeatTail();
	RSLL.display();
	RSLL.inserAtSpecificloc(6,3);
	RSLL.display();
	RSLL.inserAtSpecificloc(7,5);
	RSLL.display();
	RSLL.inserAtSpecificloc(8,0);
	RSLL.display();
	RSLL.inserAtSpecificloc(9,8);
	RSLL.display();
	RSLL.insert_atMiddle_Wrapper(12);
    cout << "LinkedList after insertion at middle is\n";
    RSLL.display();
	RSLL.insertAtTail(10);
	RSLL.display();
	
	RSLL.deleteAt_specificloc(11);
	cout << "Delete (location is greater than the no of nodes in the linked list)\n";
	RSLL.display();
	cout << "Delete at 3rd index\n";
	RSLL.deleteAt_specificloc(3);
	RSLL.display();
	cout << "Delete at 4th index\n";
	RSLL.deleteAt_specificloc(4);
	RSLL.display();
	cout << "Delete at 1st index\n";
	RSLL.deleteAt_specificloc(1);
	RSLL.display();
	cout << "Delete at 0th index\n";
	RSLL.deleteAt_specificloc(0);
	RSLL.display();
	cout << "Delete at middle\n";
	RSLL.delete_atMiddle_Wrapper();
    RSLL.display();
    cout << "Delete at middle\n";
	RSLL.delete_atMiddle_Wrapper();
    RSLL.display();
    RSLL.insert_atMiddle_Wrapper(3);
    cout << "LinkedList after insertion at middle is\n";
    RSLL.display();
    
	
	
	return 0;
}
