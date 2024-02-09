#include<iostream>
using namespace std;

// Node class is a node and it contains a data and address of next node's data
class Node{
	public:
		int data;
		Node *nextNode_dataAddress;
	Node(int value) : data(value),nextNode_dataAddress(nullptr){}   // Initializer list to initialize node
};

// LinkedList class will use to make linkedlist and all of its operations
class LinkedList{
	private:
		Node* head;    // First node always points to head
	public:
		LinkedList() : head(nullptr){}; // Default constructor(because it has not parameter) to initialize LinkedList class, head initializes to null at start
	    void insertValue_atBegining(int value);
	    void display_Linkedlist();
	    double Count_Nodes();
	    double Sum_LinkedList();
	    double AverageOf_Linkedlist();	
	    void specificNode_element(int nodeno);
	    void evenNo_inLinkedlist();
	    void oddNo_inLinkedlist();
	    void averageOf_evenElements();
	    void reverse_linkedlist();
	    void delete_Linkedlsit();
	    void deletionof_specificNode(int user_node);
	   
};

void LinkedList::insertValue_atBegining(int value)
{
	Node *newnode = new Node(value);  // Calling of node class constructor
	newnode->nextNode_dataAddress = head; //address of nextnode will come in head
	head = newnode;
}

void LinkedList::display_Linkedlist()
{
	if(head == nullptr)     // if head is equal to null then it means that list is empty and constructor 
	{	                   // will automatically initialize it to null after the creation of object in main
		cout << "Linked list is empty" << endl;
	}
	else
	{
		cout << "Elements in the Linked list are : ";
		Node *current = head; // current initialized with the head (current points to the first node in the linkedlist)
		while(current != nullptr)// means that until last node because last node has address null
		{
			cout << current->data << " ";
			current = current->nextNode_dataAddress;  // Update current after each iteration
		}
		cout << endl;
	}
}

double LinkedList::Count_Nodes()
{
	if(head == nullptr)
	{
		cout << "Linked List is empty so count is 0" << endl;
		return 0; // Return 0 when the list is empty
	}
	else
	{
		int count = 0;
		Node *current = head; 	// Start with the first node in LinkedList
		while(current != nullptr) // Means that this loop will run until the last Node of LinkedList because the last node has a null address
		{
			count++;
			current = current->nextNode_dataAddress; // Update current to go forward in LinkedList by passing nodes
		}
		return count;
	}	
}

double LinkedList::Sum_LinkedList()
{
	if(head == nullptr)
	{
		cout << "Linked list is empty so sum is impossible" << endl;
		return 0; // Return 0 when the list is empty
	}
	else
	{
		Node *current = head;
		int sum = 0;
		while(current != nullptr)
		{
			sum += current->data;
			current = current->nextNode_dataAddress;
		}
		return sum;
	}
}

double LinkedList::AverageOf_Linkedlist()
{
	if (Count_Nodes() == 0)
	{
		cerr << "Division by 0 is Not allowed, Linked list has 0 nodes" << endl;
		return 0; // Return 0 if there are no nodes in the list to avoid division by zero
	}
		
	return Sum_LinkedList() / Count_Nodes();
}
void LinkedList::specificNode_element(int nodeno)
{
	if(head == nullptr)
	{
		cout << "Node is empty so that specific node element could not found" << endl;
	}
	else
	{ 
	    int element = 0;
	    Node *current = head;
	    while(current != nullptr)
	    {
	    	element++;
	    	if(element == nodeno)
	    	{
	    		cout << "Linkedlist element value at node " << element << " is " << current->data << endl;
	    		break;
			}
			current = current->nextNode_dataAddress;
		}
		
		
	}
}
 void LinkedList::averageOf_evenElements()
 {
 	if(head == nullptr)
 	{
 		cout << "Linked List is Empty so even numbers average is impossible" << endl;
	}
	else
	{
		double sum = 0;
		double average = 0;
		Node *current = head;
		while(current != nullptr)
		{
			if(current->data % 2 == 0)
			{
				sum += current->data;
				average++;
			}
			current = current->nextNode_dataAddress;
		}
		cout << "Average of even number is : " << sum / average << endl;
		
	}
	
 }
void LinkedList::evenNo_inLinkedlist()
{
	if(head == nullptr)
	{
		cout << "Linkedlist is empty" << endl;
	}
	else
	{
		Node *current = head;
		bool found = false; 
		while(current != nullptr)
		{
			if(current->data % 2 == 0)
			{
				cout << current->data << " ";
				found = true; 
			}
			current = current->nextNode_dataAddress; 
		}
		cout << endl;
		if (!found)
		{
			cout << "No even elements are present" << endl;
		}
	}
}
void LinkedList::oddNo_inLinkedlist()
{
	if(head == nullptr)
	{
		cout << "Linkedlist is empty" << endl;
	}
	else
	{
		Node *current = head;
		bool found = false; 
		while(current != nullptr)
		{
			if(current->data % 2 != 0)
			{
				cout << current->data << " ";
				found = true; 
			}
			current = current->nextNode_dataAddress; 
		}
		cout << endl;
		if (!found)
		{
			cout << "No odd elements are present" << endl;
		}
	}
}
void LinkedList::reverse_linkedlist()
{
    if(head == nullptr)
    {
        cout << "Linked List is empty, could not reverse" << endl;
    }
    else
    {
        Node* prev = nullptr;      // initiallly points to null 
        Node* current = head;      // Points to next
        Node* next = nullptr;    // initially points to null

        while(current != nullptr)    // Loop will run until the end of the Linked list
        { 
            next = current->nextNode_dataAddress; // Store the next node 
            current->nextNode_dataAddress = prev; // Reverse the pointer
            
            // Move pointers one position ahead
            prev = current;    
            current = next;
        }
        
        // Now, the list is reversed, so set the head to the last node (prev)
        head = prev;
        
        // Print the reversed linked list
        display_Linkedlist();
    }
}
void LinkedList::delete_Linkedlsit()
{
    if(head == nullptr)
    {
        cout << "List is already empty" << endl;
    }
    else
    {
        Node* current = head;
        Node* next = nullptr;      //Initialize next to null ptr
        
        while(current != nullptr)
        {
            next = current->nextNode_dataAddress; // Store the next node and loop will go forward
            delete current; // Delete the current node, means when 
            current = next; // Now current is equal to next node's address
        }
        
        head = nullptr; // Update the head pointer to nullptr, because an empty linkd list has null head
        cout << "List is deleted successfully" << endl;
    }
}
void LinkedList::deletionof_specificNode(int user_position)
{
    if(head == nullptr)
    {
        cout << "Linked List is empty" << endl;
    }
    else
    {
        Node* current = head;
        Node* prev = nullptr;
        int position = 1;

        // Special case: if the node to be deleted is the head node
        if (user_position == 1)
        {
            head = current->nextNode_dataAddress;
            delete current;
            cout << "Node at position " << user_position << " deleted successfully" << endl;
            return;
        }

        while(current != nullptr)
        {
            // If the position matches the desired position
            if (position == user_position)
            {
                // Adjust pointers to skip the current node
                prev->nextNode_dataAddress = current->nextNode_dataAddress;
                delete current;
                cout << "Node at position " << user_position << " deleted successfully" << endl;
                return;
            }

                  // Move to the next node
            prev = current;
            current = current->nextNode_dataAddress;
            position++;
        }

        // If the position is not found
        cout << "Node at position " << user_position << " not found" << endl;
    }
}

int main(){
	LinkedList list;  // Here constructor will automatically call and head initializes to null
	int choice;
	int n;
	cout << "Press 1 to insert element at the begining of LinkedList " << endl;
	cout << "Press 2 to display Linkedlist  " << endl;
	cout << "Press 3 to to Count Nodes in the Linked List " << endl;
	cout << "Press 4 to Sum the Linked List " << endl;
	cout << "Press 5 to get Average of Linked List " << endl;
	cout << "Press 6 to get Specific node Element in the Linked List " << endl;
	cout << "Press 7 to get Even numbers in the Linkedlist " << endl;
	cout << "Press 8 get Odd numbers in the Linkedlist " << endl;
	cout << "Press 9 to get average of even elements in the Linkedlist " << endl;
	cout << "Press 10 to reverse the Linkedlist " << endl;
	cout << "Press 11 to delete the Linkedlist " << endl;
	cout << "Press 12 to delete specific node in the Linkedlist" << endl;
	cout << "Press 13 to exit the program " << endl;
	 
	
while(true)
{
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            cout << "Enter Element to insert in the Linked list : ";
            cin >> n;
            list.insertValue_atBegining(n);
            break;
        case 2:
            list.display_Linkedlist();
            break;
        case 3:
        	cout << "Number of nodes in the Linkedlist are ";
        	cout << list.Count_Nodes();
        	cout << endl;
        	break;
        case 4:
        	cout << "Sum of linkedlist elements are ";
        	cout << list.Sum_LinkedList();
        	cout << endl;
        	break;
        case 5:
        	cout << "Average of Linkedlist elements are ";
        	cout << list.AverageOf_Linkedlist();
        	cout << endl;
        	break;
        case 6:
        	cout << "Enter node number : ";
        	cin >> n;
        	list.specificNode_element(n);
        	break;
        case 7:
        	cout << "Even Numbers in the Linked list are ";
        	list.evenNo_inLinkedlist();
        	break;
        case 8:
        	cout << "Odd Elements in the Linked list are ";
        	list.oddNo_inLinkedlist();
        	break;
        case 9:
        	list.averageOf_evenElements();
            break;
        case 10:
        	cout << "Now Linked List has reversed " << endl;
        	list.reverse_linkedlist();
        	break;
        case 11:
        	list.delete_Linkedlsit();
        	break;
        case 12:
        	cout << "Enter node no : ";
        	cin >> n;
        	list.deletionof_specificNode(n);
        	break;
        case 13:
        	cout << "Program has terminated " << endl;
        	exit(0);   // exit 0 is used for normal termination and exit(1) is used for abnormal termination of program
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

	return 0;
}

