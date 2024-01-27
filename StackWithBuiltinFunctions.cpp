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
    
	
	return 0;
}
