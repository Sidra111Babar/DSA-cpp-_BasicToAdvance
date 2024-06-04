#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack <int> intstack;
	intstack.push(10);
	cout << "Element " << intstack.top() << " is Pushed successfully" << endl;
	intstack.push(5);
	cout << "Element " << intstack.top() << " is Pushed successfully" << endl;
	intstack.push(2);
	cout << "Element " << intstack.top() << " is Pushed successfully" << endl;
	intstack.push(1);
	cout << "Element " << intstack.top() << " is Pushed successfully" << endl;
	intstack.push(11);
	cout << "Element " << intstack.top() << " is Pushed successfully" << endl;
	cout << "Size of Stack is " << intstack.size() << endl;
	intstack.pop();
	cout << "As pop function is called so now top element is " << intstack.top() << endl;
	cout << endl;
	cout << "Usage of builtin empty function of stack" << endl;
	    if (intstack.empty()) {
         cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }
    cout << "Usage of while loop to print all elements in stack" << endl;
     while(!intstack.empty()) {
        cout << intstack.top() << ", ";
        intstack.pop();
    }
    	stack<int> s1; 
    stack<int> s2; 
     
    // pushing elements into first stack 
    s1.push(1); 
    s1.push(2); 
    s1.push(3); 
    s1.push(4); 
    s1.push(5);
     
    // pushing elements into 2nd stack 
    s2.push(6); 
    s2.push(7); 
    s2.push(8); 
    s2.push(9); 
    s1.swap(s2);   // Size of two stacks may be same or differ
 
        // printing the first stack 
    cout<<"stack1 = "; 
    while (!s1.empty()) { 
        cout<<s1.top()<<" "; 
        s1.pop(); 
    } 
 
        // printing the second stack 
    cout<<endl<<"stack2 = "; 
    while (!s2.empty()) { 
        cout<<s2.top()<<" "; 
        s2.pop(); 
    } 
    if (s1.empty()) {
         cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }
    
     // ----------------------------------------------emplace function
    //While push() function inserts a copy of the value or the parameter passed to the function into the container at the top, the emplace() function construc
    stack<int> s3;
    s3.emplace(10);
    s3.emplace(9);
    cout<<"stack3 = "; 
    while (!s3.empty()) { 
        cout<<s3.top()<<" "; 
        s3.pop(); 
    } 
	
	return 0;
}
