#include <iostream>
#include <map>

using namespace std;

int main() {
    multimap<string, int> myMultimap;
    myMultimap.insert({"One", 1});         //use of multimap because of map library
    myMultimap.insert({"Two", 2});         // different from map in such a way that two or more keys has same values
    myMultimap.insert({"One", 10});       
	 
	      

    cout << "Multimap Elements: ";
    for (const auto& pair : myMultimap) {
        cout << pair.first << ":" << pair.second << " ";   //insert is a memeber function of C++ provided by STL
    }                                                     //.fisrt accesses the keys(onne, two) and .second accesses values(1,10,2)

    return 0;
}

