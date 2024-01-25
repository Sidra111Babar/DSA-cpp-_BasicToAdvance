#include <iostream>
#include <deque>
//A deque (double-ended queue) is similar to a vector but allows fast insertion and deletion at both ends.
using namespace std;

int main() {
    deque<int> myDeque = {1, 2, 3, 4, 5};  // deque is keyword, use it only when deque library is included

    cout << "Deque Elements: ";
    for (int i : myDeque) {       //forEach loop( for all elements in myDeque)
        cout << i << " ";
    }

    return 0;
} 

