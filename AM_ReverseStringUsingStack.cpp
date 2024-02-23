#include<iostream>
#include<string>
#include<stack>
using namespace std;

//--------------------------------Reverse stack without using biltin functions(except push())--------------------------
void reverseString(string input){
	stack<string> s;
	s.push(input);
	
	for(int i = input.length();i >=0 ; i-- ){
	     cout << input[i];
	}
	cout << endl;
}
//---------------------------------------Reverse a string using stack builtin functions------------------------
string reverseByBuiltinFunc(string input){
	stack<char> s;    //character type stack
	for(char c : input){    
		s.push(c);
	} 
	string reverse;
	while(!s.empty())
	{
		reverse += s.top();   // Every time top element is stored in reverse (//concatenation of each charcter of stack into a reversed )
		s.pop();             // remove top element to update top character so that the next character will treat as top character
	}
	cout << endl;
	return reverse;
	
}
//--------------------Stack using Linkedlist---------------------
class Node{
	public:
		char character;
		Node *next;
		Node(char data) : character(data), next(nullptr){}
		
};
class Stack{
	Node *top;
	public:
		Stack() : top(nullptr){}
	    void push(char value){
	    	Node* newnode = new Node(value);
	    	newnode->next = top;
	    	top = newnode;
		}
		bool isEmpty(){
			return top == nullptr;
		}
		char pop(){
			if(isEmpty()){
				cout << "Stack Underflow";
				exit(1);
			}
			Node* temp = top;
            char poppedValue = top->character;
            top = top->next;
            delete temp;
            return poppedValue;

		}
	    char peek() {
        if (isEmpty()) {
            cerr << "Stack is empty\n";
            exit(1);
        }
        return top->character;
    }
    
};
//---------------------------Reverse Stack using linkedlist-----------------------
string reverseStringUsingLinkedlist(string input) {
        Stack stack;
        // Push each character of the input string onto the stack
        for (char c : input) {
        stack.push(c);
    }

    string reverse;
    // Pop each character from the stack and append it to the reversed string
    while (!stack.isEmpty()) {
        reverse += stack.pop();
    }
    cout << endl;
    return reverse;
}

int main(){
   
    string userString;
    cout << "Enter your string : "; 
    getline(cin,userString);
    cout << "Reversed String is ";
	reverseString(userString); 
    cout << "Enter your string to reverse it by using stack builtin functions : ";
    getline(cin, userString);
    cout << "Reversed string using stack is " << reverseByBuiltinFunc(userString);
    cout << "Enter your string to reverse it using Linkedlist : ";
    getline(cin, userString);
    cout << "Reverse string using stack linkedlist is " << reverseStringUsingLinkedlist(userString);
    
	return 0;
}
