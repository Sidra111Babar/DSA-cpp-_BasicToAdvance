//Follow LIFO rule(Last in First out) 
// Use Linked list insert at head(push()) and delete from head(pop())
#include<iostream>
using namespace std;
class Stack{
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
	Node *topNode;   // head
	
	public:
		Stack(int data){
			topNode = new Node(data);
			
		}
		bool isEmpty();
		void push(int data);
		void pop();
		int top();
		void display();
};
bool Stack::isEmpty(){
	return topNode == NULL;
}
void Stack::push(int data){	
	Node *newnode = new Node(data);
	newnode->next = topNode;
	topNode = newnode;         // topNode always update when push function call while lastnode remain as it is(It is very first node which is at the end of the stack)
}
void Stack::pop(){
	if(isEmpty()){
		cout << "Stack is empty\n";
		return;
	}
	Node *temp = topNode;
	topNode = topNode->next;
	delete temp;
	
}
int Stack::top(){
	return topNode->data;
}
void Stack::display(){
	if(isEmpty()){
		cout << "Stack is empty\n";
		return;
	}
	Node *temp = topNode;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main(){
	Stack s(1);
	s.push(2);
	s.push(3);
	s.display();
	cout << "Top most element in the stack is : " << s.top() << endl;
	cout << "POP two times\n";
	s.pop();
	s.pop();
	s.display();
	cout << "Top most element in the stack is : " << s.top() << endl;
	return 0;
}
