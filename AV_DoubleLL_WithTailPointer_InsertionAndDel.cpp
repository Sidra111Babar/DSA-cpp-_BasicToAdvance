
#include <iostream>
using namespace std;
class DoublyLinkedList
{
private:
    class Node 
    {
    public:
        int data;
        Node * next;
        Node * prev;
        Node (int data)
        {
            this->data = data;
            next = prev = NULL;
        }
    };
    
    Node * head;
    Node * tail;
public:
    DoublyLinkedList(int data)
    {
        head = new Node (data);
        tail = head;
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
    //Insert at tail
    void InserAtTail(int data)
    {
        //implement yourself
        if (isEmpty())
        {return;}
        
        Node * temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = tail->next;
    }
    void InsertAtHead(int data)
    {
        //implement yourself
        if (isEmpty())
        {return;}
        Node * temp = new Node (data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    void Insert_atSpecificLoc(int data, int loc)
    {
        if (isEmpty())
        {return;}
        if (loc <= 0)
        {
            InsertAtHead(data);
            return;
        }
        Node * temp = head;
        int index = 0;
        while(temp->next != tail && index < loc-1)   // agr  list end tk nhi pohanchi and index jo user ne loc di ha loc -1 se less ha phr ye loop chaly gi
        {
            temp = temp->next;
            index ++;
        }
        if (loc-1 > index)
        {
            InserAtTail(data);
            return;
        }
        Node * newnode = new Node(data);
        newnode->next = temp->next;
        //temp->next->prev = newnode (wrong logic ku ka ab temp kay next waly node ka temp kay sath connection break ho chuka ha)
        newnode->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
    }
    void Display()
    {
         if (isEmpty())
        {return;}
        Node * temp = head;
        while (temp!=NULL)
        {
            cout <<"<-" << temp->data << "->" ;
            temp = temp->next;
            
        }
        cout << endl;
    }
    void ReverseDisplay()
    {
         if (isEmpty())
        {return;}
        Node * temp = tail;
        while (temp!=NULL)
        {
            cout <<"<-" << temp->data << "->" ;
            temp = temp->prev;
            
        }
        cout << endl;
    }
    void DeleteAtHead()
    {
        //deal with single node
        if (isEmpty())
        {return;}
        Node * temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    void DeleteAtTail()
    {
        //deal with single node
        if (isEmpty())
        {return;}
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
    }
    void Delete_atSpecificLoc(int loc)
    {
        if (isEmpty())
        {return;}
        if (loc == 0)
        {
            DeleteAtHead();
            return;
        }
        Node * temp = head;
        int index = 0;
        while(temp->next != tail && index < loc-1)
        {
            temp = temp->next;
            index ++;
        }
        if (temp->next==tail)
        {
            DeleteAtTail();
            return;
        }
        Node * temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        delete temp2;
    }
 void deleteMiddleNode() {
        if (head == nullptr || head->next == nullptr || head->next == tail) {
            cout << "List is too short to have a middle node!" << endl;
            return;
        }
        
        Node* start = head;
        Node* end = tail;
        
        while (start != end && start->next != end){
            start = start->next;
            end = end->prev;
        }
        
        // Deleting the middle node
        Node* middle = start->next;
        start->next = middle->next;
        if (middle->next != nullptr)
            middle->next->prev = start;
        delete middle;
    }
void insert_atMiddle(int data){
    if (head == nullptr || head->next == nullptr || head->next == tail) {
        cout << "List is too short to have a middle node!" << endl;
        return;
    }

    Node* start = head;
    Node* end = tail;

    while (start != end && start->next != end){    //this loop will run until start is not equal to end(start = end) start = end at the middle of the linked list
        start = start->next;
        end = end->prev;
    }

    // Inserting the new node at the middle
    Node* middle = start->next;
    Node* newnode = new Node(data);
    newnode->next = middle;
    middle->prev = newnode;
    newnode->prev = start;
    start->next = newnode;
}


  
};
int main()
{
    DoublyLinkedList dl (4);
    
    dl.InserAtTail(5);
    dl.InsertAtHead(9);
    dl.Display();
    dl.Insert_atSpecificLoc(3, 0);
    dl.Insert_atSpecificLoc(1, 5);
    dl.Insert_atSpecificLoc(2, 4);
    dl.Display();   
    //dl.ReverseDisplay();
    cout << "Delete.\n\n";
    dl.Delete_atSpecificLoc(4);
    dl.Display(); 
    dl.DeleteAtHead();
    dl.Display(); 
    dl.DeleteAtTail();
    dl.Display(); 
    dl.InsertAtHead(13);
    dl.InsertAtHead(10);
    dl.InsertAtHead(11);
    
    dl.Display();
    dl.deleteMiddleNode();
    dl.Display();
    dl.insert_atMiddle(12);
    dl.Display();
    dl.insert_atMiddle(14);
    dl.Display();
    return 0;
}
