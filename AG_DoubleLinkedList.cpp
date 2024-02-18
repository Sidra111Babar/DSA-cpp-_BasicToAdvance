#include<iostream>
using namespace std;

class Node{
private: 
    int data;
    Node* next;
    Node* prev;
public: 
    Node(int value) : data(value), next(NULL), prev(NULL){}
    int getdata()
    {
    	return data;
	}
    Node* getNext(){
        return next;
    }
    
    Node* getPrev(){
        return prev;
    }
    
    void setNext(Node* nextNode){
        next = nextNode;
    }
    
    void setPrev(Node* prevNode){
        prev = prevNode;
    }
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList() : head(NULL){}
    
    // Method to insert an element at the beginning
    void insert_Elementathead(int value){
        Node* newnode = new Node(value); // here constructor will automatically call value = data, next = null and prev = null here       
        if (head == nullptr) {
            head = newnode;
        } else {
            newnode->setNext(head); // Set the next pointer of the new node to the current head  (newnode -> next = head) 
            head->setPrev(newnode); // Set the previous pointer of the current head to the new node (head->prev = newnode)
            head = newnode; // Update head to point to the new node 
        }
    }
    void display_LinkedList(){
    	if(head == NULL)
    	{
    		cout << "LinkedList is empty" << endl;
		}
		else 
		{
			Node *current = head;
			cout << "LinkedList : ";
			while(current != NULL)
			
			{
				cout << current->getdata() << " ";
				current = current->getNext();
			}
		}
		cout << endl;
	}


};

int main() {
    LinkedList list;
    list.insert_Elementathead(5);
    list.display_LinkedList();
    list.insert_Elementathead(4);
    list.insert_Elementathead(3);
    list.insert_Elementathead(2);
    list.display_LinkedList();
    
    
    return 0;
}

