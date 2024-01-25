#include <iostream>
#include <map>
//map is an associative container that stores key-value pairs. Each key must be unique.

using namespace std;

int main() {
    map<string, int> myMap;   //word map is included because of map library and myMap is name
    myMap["One"] = 1;         // inside square brackets are keys and 1,2,3 are the values of keys
    myMap["Two"] = 2;         //insdie square values are string(Changeable and depend upon requirements)
    myMap["Three"] = 3;

    cout << "Map Elements: ";           //(:)it is used to iterate elments in a range
    for (const auto& pair : myMap) {      // auto is keyword and used to generalize the code, datatype is determined by compiler itself
        cout << pair.first << ":" << pair.second << " ";  //.first is used to access keys(one,two and three)
                                                          //.second is used to access the values of keys(1,2,3)
    }

    return 0;
} 

