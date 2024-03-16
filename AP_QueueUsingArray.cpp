#include<iostream>
using namespace std;

class Queue {
private:
    int *array;
    int capacity;
    int index;
    int frontIndex;
    int lastIndex;
public:
    Queue(int cap) : capacity(cap), index(-1), frontIndex(0) {
        array = new int[capacity];
    }
    ~Queue() {
        cout << "Destructor call" << endl;
        delete[] array;
    }
    int enqueue(int value) {
        if (isfull()) {
            cout << "Queue is full cannot enqueue.\n";
            return -1;
        }
        index++;
        array[index] = value;
        return 0; // Successful enqueue
    }
    bool isempty() {
        return (index == -1);
    }
    bool isfull() {
        return (index == capacity - 1);
    }
    int dequeue() {
        if (isempty()) {
            cout << "Queue is empty cannot dequeue.\n";
            return -1;
        }
        for (int i = 0; i < index; i++) {
            array[i] = array[i + 1];
        }
        index--;
        return 0; // Successful dequeue
    }
    int getFront() {
        return array[frontIndex];
    }
    int getLast() {
        return array[index];
    }

};

int main() {
    Queue q(3);
    cout << "Enqueue \n";
    q.enqueue(3);
    cout << "Enqueue \n";
    q.enqueue(4);
    cout << "Enqueue \n";
    q.enqueue(5);
    cout << "Enqueue \n";
    q.enqueue(7);
    cout << "dequeue\n";
    q.dequeue();
    cout << "Front element is " << q.getFront() << endl;
    cout << "Last element is " << q.getLast() << endl;
    cout << "dequeue\n";
    q.dequeue();  
    cout << "dequeue\n";
    q.dequeue();
    cout << "dequeue\n";
    q.dequeue();
    return 0;
}

