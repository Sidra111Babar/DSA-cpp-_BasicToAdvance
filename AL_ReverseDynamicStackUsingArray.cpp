#include<iostream>
using namespace std;
class StackArr{
	private:
		int top;
		int *array;
		int capacity;
	public: 
	     StackArr(int size) : top(-1), capacity(size)
		 {
		 	 array = new int[capacity];
		 } 
        ~StackArr() {
                   delete[] array;
        }
        void push(int value) {
        if (top == capacity - 1) {      // if stack is full element cannot add 
            cout << "Stack overflow! Cannot push more elements." << endl;
            return;
        }
        array[++top] = value;
        cout << value << " pushed onto the stack." << endl;
    }
     void displayStackArray(int size){
     	for(int i = size - 1; i >= 0; i--)
     	{
     	   cout << 	"| " << array[i] << " |" << endl;
		}
	 }
	 void reverseStackArray(int size){
     	for(int i = 0; i < size; i++)
     	{
     	   cout << 	"| " << array[i] << " |" << endl;
		}
	 }
};

int main()
{   
    int size = 4;
    StackArr stackarr(size);
    stackarr.push(2);
    stackarr.push(3);
    stackarr.push(1);
    stackarr.push(4);
    cout << "Elements in the Stack array are" << endl;
    stackarr.displayStackArray(size);
    cout << "Elements after reversing the stack array are" << endl;
    stackarr.reverseStackArray(size);
	return 0;
}
