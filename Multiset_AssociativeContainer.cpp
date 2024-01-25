#include <iostream>
#include <set>
//A std::map is an associative container that stores key-value pairs. Each key must be unique.
using namespace std;

int main() {
    multiset<int> myMultiset = {3, 1, 4, 1, 5, 9, 2, 6, 5};   //use it only when set library is included

    cout << "Multiset Elements: ";
    for (int i : myMultiset) {
        cout << i << " ";
    }

    return 0;
}

