#include <iostream>
#include <cstring>  
using namespace std;  

class Stack {
public:
    int top;
    unsigned capacity;   // unsigned used to keep it always positive and to increase the range of int
    char* array;
};

Stack* createStack(unsigned capacity) {    
    Stack* stack = new Stack();            
    stack->capacity = capacity;            
    stack->top = -1;
    stack->array = new char[stack->capacity];     // Dynamic memory allocation to stack array
    return stack;
}

bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;   // True condition logic: stack is full if the size of the stack is equal to the capacity 
}                                               

bool isEmpty(Stack* stack) {
    return stack->top == -1;   // True condition logic: stack is empty if the value of top is -1
}

void push(Stack* stack, char item){     
    if (isFull(stack))     
        return;
    stack->array[++stack->top] = item; 
}

char pop(Stack* stack) {
    if (isEmpty(stack))
        return '\0'; // Return null character for an empty stack
    return stack->array[stack->top--];
}
/*-----------------------isEmpty,isFull,push and pop all these four functions(give up) will remian same in all
                        codes of stack, reamining functions and logics will depend on the requirements of questions*/
                        
void reverse(char str[]) {
    int n = strlen(str);    // strlen is the built-in function of the cstring library, used to determine the size of the string
    Stack* stack = createStack(n);   // A stack with size n has been created

    for (int i = 0; i < n; i++)  // On this size(given by cstring) loop will run
        push(stack, str[i]);     

    for (int i = 0; i < n; i++)
        str[i] = pop(stack);

    delete[] stack->array; // Free the dynamically allocated memory
    delete stack; // Free the stack itself
}

int main(){
    char str[] = "Sidra Babar";

    reverse(str);
    cout << "Reversed string is " << str << endl;  // Using cout without std:: namespace

    return 0;
}
/*Summary creat stack function will call in isEmpty,isFull,push and pop funciton
isEmpty and isFull Function will call in push and pop fucntion (until here code will remain same for all stack problems)
push and pop and create stack function will call in reverse function */
