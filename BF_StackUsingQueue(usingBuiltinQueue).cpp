using namespace std;
#include <bits/stdc++.h>
// -------------------------------------------------Stack using Queue-------------------------------------
// Steps 1. push(x)  push x into queue2 2.Pop all elements of queue1 and push into queue2 (pop and push one by one)
// swap q1 and q2  
class Stack {
    // Two inbuilt queues
    queue<int> q1, q2;
 
public:
    void push(int x)
    {
       
        q2.push(x);                        // stack me jo value push krni ha wo dal deni ha
       
        while (!q1.empty()) {             // jb tk queue 1 empty ni ho jati q2 me queue 1 ki values push krty jana ha
            q2.push(q1.front());         
            q1.pop();                     // queue front values nikal kr q2 me push krty jana ha
        }
 
        
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
 
    void pop()
    {
        // if no elements are there in q1
        if (q1.empty())
        return;
        q1.pop();
    }
 
    int top()
    {
        if (q1.empty())
        return -1;
        return q1.front();
    }
 
    int size() { return q1.size(); }
};
 

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
   // Now it is following Last in first out (LIFO)
    cout << "current size: " << s.size() << endl;
    cout << s.top() << endl;
    cout << s.top() << " Poped out\n";
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
 
    cout << "current size: " << s.size() << endl;
    return 0;
}
