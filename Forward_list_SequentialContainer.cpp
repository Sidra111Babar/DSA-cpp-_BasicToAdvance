#include <iostream>
#include <forward_list>
//A forward list is a singly-linked list, allowing efficient insertion and deletion at the front and middle
using namespace std;

int main() {
    forward_list<int> myForwardList = {1, 2, 3, 4, 5}; // forward_list is keyword use it only when forward_list library is included

    cout << "Forward List Elements: ";  
    for (int i : myForwardList) {            //for each loop for all elements in myForwardList
        cout << i << " ";
    }

    return 0;
}

