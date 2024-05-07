#include <bits/stdc++.h>
using namespace std;
 // -------------------------------------Queue Using Stack-------------------------------
 //Step1: s1(elements) push to s2 ,Step2: x push into s2, s2(elements) push to s1
class Queue {
	private:
    stack<int> s1, s2;
    public:
    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
 
        // Push item into s1
        s1.push(x);
 
        // Push everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
 
    
    int deQueue()
    {
        // if first stack is empty
        if (s1.empty()) {
            return -1;
        }
 
        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
   int top() {
        if (s1.empty()) {
            return -1; 
        }
        return s1.top();
    }
};
 
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    cout << q.deQueue() << '\n';   // 1 will dequeue
    cout << q.deQueue() << '\n';   // 2 will dequeue
    cout << q.deQueue() << '\n';   // 3 will dequeue
    
    
 
    return 0;
}
