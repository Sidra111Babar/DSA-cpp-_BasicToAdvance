#include <iostream>
#include <list>
//A list is a doubly-linked list, allowing efficient insertion and deletion at any position.
using namespace std;

int main() {
    list<int> myList = {1, 2, 3, 4, 5}; //list is keywrod use it only when list library is included and mylist is the name of list

    cout << "List Elements: ";
    for (int i : myList) {            //for each loop for all elements in myList
        cout << i << " ";
    }

    return 0;
}

