#include<iostream>
using namespace std;
class Recursive_DoubleLL{
	private:
		class Node{
			public:
				int data;
				Node *next;
				Node *prev;
				Node(int data){
					this->data  = data;
					next = NULL;
					prev = NULL;
				}
		};
		Node *head;
		Node *tail;
	public:
		Recursive_DoubleLL(){
		    head = NULL;
			tail = NULL;	
		}
		void insertATHead(int data){
			 Node* newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
		}
		bool isEmpty(){
			return(head == NULL && tail == NULL);
		}
		void insertAtTail_Rec(Node* node,int data){
			if(isEmpty()){
				insertATHead(data);
				return;
			}
			if(node == NULL){
				Node *newnode = new Node(data);
				tail->next = newnode;
				newnode->prev = tail;
				tail = newnode;
				return;
			}
			insertAtTail_Rec(node->next,data);
		}
		void insertAatTail_Wrapper(int data){
			insertAtTail_Rec(head,data);
		}
		void display_DLL_Rec(Node *node){
			if(node == NULL){
				cout << "NULL";
				cout << endl;
				return;
			}
			if(node == head){
				cout << "NULL";
			}
			cout << "<-" << node->data << "->"; 
			
			display_DLL_Rec(node->next);
		}
		void displayWrapper(){
			display_DLL_Rec(head);
		}
		void deleteAtHead(){
			if(isEmpty()){
				cout << "Linked List is empty\n";
				return;
			}
			if(head->next == NULL && head->prev == NULL){
				delete head;
				head == NULL;
			}
			head = head->next;
			delete head->prev;
			head->prev = NULL;
		}
		void deleteAtTail_Rec(Node *node){
			if(isEmpty()){
				cout << "Linked List is already empty\n";
			}
			if(head->next == NULL && head->prev == NULL){
				delete head;
				head == NULL;
			}
			if(node == NULL){
				Node *temp = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
				
				return;
			}
			deleteAtTail_Rec(node->next);
		}
		void deleteAtTail_Wrapper(){
			deleteAtTail_Rec(head);
		}
		void insertAtMiddle(Node *start,Node *end,int data){
			if(countWrapper()% 2 == 0){
					cout << "Nodes are even.Insertion for even no of nodes will handle later\n";
					return;
				}
			if(start == end){
			  start = start->prev;
			  Node* middle = start->next;
              Node* newnode = new Node(data);
              newnode->next = middle;
              middle->prev = newnode;
              newnode->prev = start;
              start->next = newnode;
   
			 return;   
				
			}
			insertAtMiddle(start->next,end->prev,data);
		}
		void insertAtMiddle_Wrapper(int data){
			insertAtMiddle(head,tail,data);
		}
		void deleteAtMiddle(Node* start,Node *end){
				if(countWrapper()% 2 == 0){
					cout << "Two Middles are present so first make count of nodes odd\n";
					return;
				}
			if(start == end && start->next != end){
			
				start = start->prev;
				Node* middle = start->next;
                start->next = middle->next;
               if (middle->next != nullptr)
               middle->next->prev = start;
               delete middle;
               return;
			}
			deleteAtMiddle(start->next,end->prev);
		}
		void deleteAtMiddle_Wrapper(){
			deleteAtMiddle(head,tail);
		}
		int countNodes(Node *node,int count = 1){
			if(isEmpty()){
				cout << "Count is 0\n";
			}
			if(node->next == NULL){
				return count;
			}
			
	       	countNodes(node->next,count + 1);	
		}
		int countWrapper(){
		
			countNodes(head);
		}
	void deleteAllRecursive(Node* current) {
    if (current == nullptr)
        return;
    deleteAllRecursive(current->next);
    delete current;
}

void deleteWrapper() {
    deleteAllRecursive(head);
    head = nullptr; // Reset the head pointer after deleting all nodes
    tail = nullptr;
}

};
int main(){
	Recursive_DoubleLL rdll;
	rdll.insertATHead(1);
	rdll.insertATHead(2);
	rdll.insertATHead(3);
	rdll.insertATHead(4);
	rdll.displayWrapper();
	rdll.insertAatTail_Wrapper(5);
	rdll.insertAatTail_Wrapper(6);
	rdll.insertAatTail_Wrapper(7);
	rdll.insertAatTail_Wrapper(8);
	rdll.displayWrapper();
	rdll.deleteAtHead();
	rdll.displayWrapper();
	rdll.deleteAtTail_Wrapper();
	rdll.displayWrapper();
	rdll.insertAatTail_Wrapper(9);
	rdll.displayWrapper();
	//rdll.insertAtMiddle_Wrapper(10);
	//rdll.displayWrapper();
	cout << "Delete AT Middle\n";
	rdll.deleteAtMiddle_Wrapper();
	rdll.displayWrapper();
	cout << "Insert 10 and 11 at tail\n";
	rdll.insertAatTail_Wrapper(10);
	rdll.insertAatTail_Wrapper(11);
	rdll.displayWrapper();
    cout <<	"No of nodes in the linked list are\n" << rdll.countWrapper();
    cout << endl;
    cout << "Now check delete at middle for the even nodes\n";
    rdll.deleteAtMiddle_Wrapper();
    rdll.insertAatTail_Wrapper(13);
    rdll.displayWrapper();
    rdll.insertAatTail_Wrapper(14);
    rdll.displayWrapper();
    rdll.insertAtMiddle_Wrapper(12);
    rdll.displayWrapper();
    cout << "Delete Double Linked list\n";
    rdll.deleteWrapper();
    rdll.displayWrapper();
    if(rdll.isEmpty()){
    	cout << "Linked list is empty\n";
	}
	else {
		cout << "No Empty\n";
	}
    
	
	return 0;
}
