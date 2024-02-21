#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node(data);   //  newnode data = current data 
        newNode->next = topNode;         //   newnode next is equal to NULL beacuse newnode is shifted to latest node every time and latest node-> next is always equal to NULL
        topNode = newNode;               // topNode = newNode (Latest node) every time
    }

   void pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = topNode; // Create a temporary pointer to the top node
    topNode = topNode->next; // Move the top pointer to the next node
    delete temp; // Delete the top node
    }
    
    void displayStack() {
    Node* current = topNode; // Use a temporary pointer to traverse the stack
    if (current == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
      cout << endl;
    }



    bool isEmpty() {
        return topNode == nullptr;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Assuming -1 represents an empty stack
        }
        return topNode->data;
    }
};

int main() {
    Stack stack;

    cout << "Is stack empty: " << (stack.isEmpty() ? "true" : "false") << endl;  // Usage of ternary operator (to avoid if else) ---> more professional way

    stack.push(1);
    cout << stack.top() << " is pushed successfully " << endl;
    stack.push(2);
    cout << stack.top() << " is pushed successfully " << endl;
    stack.push(3);
    cout << stack.top() << " is pushed successfully " << endl;
    stack.push(4);
    cout << stack.top() << " is pushed successfully " << endl;
    stack.displayStack();
    cout << "Top element of the stack: " << stack.top() << endl;
    cout << stack.top() << " is popped successfully " << endl;
	stack.pop();
	cout << stack.top() << " is popped successfully " << endl;
	cout << endl;
   
	stack.pop();
	cout << endl;

    cout << "Top element of the stack: " << stack.top() << endl;

    cout << "Is stack empty: " << (stack.isEmpty() ? "true" : "false") << endl;
    stack.displayStack();

    return 0;
}

