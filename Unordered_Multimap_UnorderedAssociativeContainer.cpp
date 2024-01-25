#include <iostream>
#include <unordered_map>
//unordered_multimap is an unordered associative container similar to 
using namespace std;

int main() {
    unordered_multimap<string, int> myUnorderedMultimap;
    myUnorderedMultimap.insert({"Three", 7});
    myUnorderedMultimap.insert({"One", 1});
    myUnorderedMultimap.insert({"Two", 2});
    myUnorderedMultimap.insert({"One", 10});
    myUnorderedMultimap.insert({"Three", 3});
    myUnorderedMultimap.insert({"Five", 5});
    myUnorderedMultimap.insert({"Three", 6});                 //keys start print from last but in case a key is repeating then it will print with last key
    cout << "Unordered Multimap Elements: ";
    for (const auto& pair : myUnorderedMultimap) {
        cout << pair.first << ":" << pair.second << " ";
    }

    return 0;
}


