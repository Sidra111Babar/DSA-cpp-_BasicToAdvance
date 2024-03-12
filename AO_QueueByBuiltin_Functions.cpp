#include <iostream>
#include <deque>

using namespace std;

class Queue {
private:
    deque<int> arr;

public:
    void enqueue(int val) {
        arr.push_back(val); // Enqueue at the back of the deque
    }

    void dequeue() {
        if (!arr.empty()) {
            arr.pop_front(); // Remove from the front of the deque
        } else {
            cout << "Queue is empty, cannot dequeue.\n";
        }
    }

    bool isEmpty() {
        return arr.empty(); // Check if the deque is empty
    }

    int top() {
        if (!arr.empty()) {
            return arr.front(); // Access the front element
        } else {
            cout << "Queue is empty.\n";
            return -1; // Indicate an error condition
        }
    }

    int last() {
        if (!arr.empty()) {
            return arr.back(); // Access the back element
        } else {
            cout << "Queue is empty.\n";
            return -1; // Indicate an error condition
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Top element: " << q.top() << endl; // Should print 10
    cout << "Last element: " << q.last() << endl; // Should print 30

    q.dequeue();
    cout << "After dequeue, top element: " << q.top() << endl; // Should print 20

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Attempt to dequeue an empty queue

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Should print Yes (Usage of ternary operator in place of if else)

    return 0;
}

