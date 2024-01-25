
#include <iostream>
#include <vector>
//A vector is a dynamic array that can resize itself automatically.
using namespace std;

int main() {
    vector<int> myVector = {1, 2, 3, 4, 5};  // vector keyword from vector library and myVector is name of vector

    cout << "Vector Elements: ";
    for (int i : myVector) {               // usage of for each loop here(for all elements in myVector)
    
    
    
        cout << i << " ";
    }

    return 0;
}

