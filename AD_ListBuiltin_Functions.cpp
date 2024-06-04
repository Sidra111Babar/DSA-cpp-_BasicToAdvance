#include <iostream>
#include <list>
using namespace std;

//------------------------------------push_front(), push_back(),back(),front(),pop_front(),pop_back(),size(),begin()--> used to start iterator and iterator will go froward by using advance function,end()--->use with iterator to print the list,assign()----->used to insert same element multiple times() it will take two parameters(NoOfElement, element),insert()----> it will use to insert element at the desired position like but it will use with iterator
//     --------------------------------------- implementation see from website 
int main() {
    // push front is insert at head
    // push back is insert at tail
    // .front() is left most element or topmost   (give data on head)
    // .back() right most element                 (give data on tail)
    list<int> myList;
    cout << "Ist Linked list by using push_front() Function" << endl;
    myList.push_front(5);    // push_front() is builtin functionof list and it is used to insert elements at front side
    cout << "Element " << myList.front() << " is pushed" << endl;  // front()(builtin list function) is used to access front most element 
    myList.push_front(2);
    cout << "Element " << myList.front() << " is pushed" << endl;
    myList.push_front(3);
    cout << "Element " << myList.front() << " is pushed" << endl;
    cout << "Front most elment until here is " << myList.front() << endl;  
    cout << "Last most element until here is " << myList.back() << endl;//back()(builtin function to access lastmost element)
    cout << "Linked List after insertion at the beginning: ";  
    for (const auto& element : myList) {    // range based loop, auto key word automatically identify datatype
           cout << element;          // top most element always print first when use loop
    }
    cout << endl;
    cout << "2nd Linked list by using push_back() Function" << endl;
    list<int> myList2;
    myList2.push_back(5);    // push_front() is builtin functionof list and it is used to insert elements at front side
    cout << "Element " << myList2.back() << " is pushed" << endl;  // front()(builtin list function) is used to access front most element 
    myList2.push_back(2);
    cout << "Element " << myList2.back() << " is pushed" << endl;
    myList2.push_back(3);
    cout << "Element " << myList2.back() << " is pushed" << endl;
    cout << "Front most elment until here is " << myList2.front() << endl;  
    cout << "Last most element until here is " << myList2.back() << endl;//back()(builtin function to access lastmost element)
    cout << "Linked List after insertion at the end ";  
    for (const auto& element : myList2) {    // range based loop, auto key word automatically identify datatype
           cout << element << " ";          // top most element always print first when use loop
    }
    cout << endl;

    cout << "Now push two more elements in Ist Linked list by using push_back() function" << endl;
    myList.push_back(4);     //push_back() is builtin function used to add elements at tail of linked list
    myList.push_back(5);

    
    cout << "Linked List after insertion at the end: ";
    for (const auto& element : myList) {
           cout << element << " ";
    }
     cout << endl;
     cout << "Now Front most element in Ist Linked list is " << myList.front() << endl;
     cout << "Now Last most element in Ist Linked list is " << myList.back() << endl;
     cout << "After Using push_back() function front most element is first elment in the list" << endl;
     cout << "After Using push_back() function last most is  last element in the list " << endl;
     cout << endl;
     cout << "Usage of begin() builtin function of list" << endl;
    list<int> myList3 = {1, 2, 3, 4, 5};

    // Accessing elements using iterators
    list<int>::iterator it = myList3.begin(); // begin() is built in funciton of list, 
	                                        // iteration will start form begin Iterator is used to iterate elements in list(STL has iterator)
    advance(it, 2); // Move iterator forward by 2 positions, advance() is a function use to access desired element at desired position

    // Now 'it' points to the third element in the list
    cout << "Element at position 3: " << *it << endl;

   

    return 0;
}
