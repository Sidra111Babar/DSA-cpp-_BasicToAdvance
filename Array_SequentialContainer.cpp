#include <iostream>
#include <array>                 // include array library to use this sequetial  container

using namespace std;

int main() {
    array<int, 5> myArray = {1, 2, 3, 4, 5}; // array is keyword myArray(name of array) 

    cout << "Array Elements: ";
    for (int i : myArray) {      //forEach Loop (Print all elements in myArray conatiner)
        cout << i << " ";
    }

    return 0;
}

