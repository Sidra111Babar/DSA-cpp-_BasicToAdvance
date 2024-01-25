#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> myUnorderedMap;       // unordered_map it only when unordered_map library is included, myOrdered_Map is name

    myUnorderedMap["One"] = 1;                       
    myUnorderedMap["Three"] = 3;
    myUnorderedMap["Two"] = 2;

    cout << "Unordered Map Elements: ";            
    for (const auto& pair : myUnorderedMap) {             // foreach loop (itereate all pairs)
        cout << pair.first << ":" << pair.second << " ";  // first used to access keys(first,second,third) and second(use to access values(1,2,3)
    }                                                     // values and keys print in say way as they are decare, no follow sorting sequence

    return 0;
}

