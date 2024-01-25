#include <iostream>
#include <set>
//set is an ordered collection of unique elements

using namespace std;

int main() {
    set<int> mySet = {3, 1, 4, 1, 5, 9, 2, 6, 5};  //set is a keyword, use it only when setLibrary is included and mySet is name

    cout << "Set Elements: ";
    for (int i : mySet) {            // foreach loop(for alll elments in mySet)
        cout << i << " ";
    }

    return 0;
}

