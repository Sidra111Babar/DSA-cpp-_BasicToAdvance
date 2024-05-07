#include <iostream>
using namespace std;
class WraparoundQueue {
private:
    int capacity;
    int* queue;
    int size;
    int front;
    int rear;

public:
    WraparoundQueue(int capacity) : capacity(capacity), size(0), front(0), rear(-1) {
        queue = new int[capacity];
    }

    ~WraparoundQueue() {
        delete[] queue;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = item;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int item = queue[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        } else {
            for (int i = front; i < capacity; i++) {
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    WraparoundQueue q(5);
    
    q.enqueue(1);    // rear = 0
    q.enqueue(2);    // rear = 1
    q.enqueue(3);   // rear = 2
    q.enqueue(4);   // rear = 3
    q.enqueue(5);    // rear = 4
    
    q.display(); // Output: 1 2 3 4 5
    q.dequeue();
    q.enqueue(6);
    q.display(); // Output: 2 3 4 5 6
    return 0;
}

