#include <iostream>

using namespace std;

class Stack {
private:
    int top;
    int* array;
    int capacity;

public:
    // Constructor
    Stack(int size) : top(-1), capacity(size) {
        array = new int[capacity];         // dynamic memeory allocation to array
    }

    // Destructor to free dynamically allocated memory (when used new keyword, it is necessary to use delete keyword to free memory)
    ~Stack() {
        delete[] array;
    }

    
    bool isEmpty() {
        return top == -1;     // index start from 0 so -1 is empty(use to make logic)
    }

    
    void push(int value) {
        if (top == capacity - 1) {      // if stack is full element cannot add 
            cout << "Stack overflow! Cannot push more elements." << endl;
            return;
        }
        array[++top] = value;
        cout << value << " pushed onto the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {     // or top == -1 (thhis logic can also be used
            cout << "Stack underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        cout << array[top--] << " popped from the stack." << endl;
    }

    
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1; 
        }
        return array[top];
    }
    void display(int size){
    	   for(int i = 0; i < size; i++){
    	   	cout << "Element " << i+1 << " is " << array[i] << endl; 
		   }
	}
};

int main() {
	int size = 5;
    // Create a stack with a specified size
    Stack myStack(size);

    
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    cout << "All the Elements of stack" << endl;
    myStack.display(size);
    
    cout << "Top element: " << myStack.peek() << endl;

    
    myStack.pop();
    myStack.pop();
    myStack.pop();
    // Now stack is empty

    myStack.pop();
    

    return 0;
}

