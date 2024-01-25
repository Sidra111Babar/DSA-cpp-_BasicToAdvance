#include <iostream>
#include <unordered_set>
//A std::unordered_set is an unordered collection of unique elements.
using namespace std;

int main() {
    unordered_set<int> myUnorderedSet = {3, 1, 4, 1, 5, 9, 2, 6, 5}; //unordered_set is used only when unordered_set library is included

    cout << "Unordered Set Elements: ";
    for (int i : myUnorderedSet) {           //foreach loop fo all elements
        cout << i << " ";                    // print elements in unordered way without repeating the same element
    } 

    return 0;
}

