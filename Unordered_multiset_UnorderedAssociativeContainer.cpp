#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_multiset<int> myUnorderedMultiset = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    cout << "Unordered Multiset Elements: ";
    for (int i : myUnorderedMultiset) {            //values print in sameway as they are declared but start print from last and same elements will repeat
        cout << i << " ";
    }

    return 0;
} 

