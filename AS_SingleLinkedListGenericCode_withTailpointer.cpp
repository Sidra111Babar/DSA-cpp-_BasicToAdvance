// Code by DSA sir
#include <iostream>
using namespace std;
class LinkedList
{
private:
    class Node
    {
    public:
        int data;
        Node* next;
        Node(int data)
        {
            this->data = data;
            next = NULL;
        }
    };
    Node * head;
    Node * tail;
public:
    LinkedList(int data)
    {
        head = new Node(data);
        tail = head;
    }
    //IsEmpty
    bool IsEmpty()
    {
        return head == NULL;
    }
    //insert at head
    void InsertAtHead(int data)
    {
        if (IsEmpty())
        {
            head = new Node (data);
            tail = head;
            return;
        }
        Node * temp = new Node (data);
        temp->next = head;
        head = temp;
    }
    void InsertAtTail(int data)
    {
        if (IsEmpty())
        {
            head = new Node (data);
            tail = head;
            return;
        }
        tail->next = new Node (data);
        tail = tail->next;
       
    }
    void Insert(int data, int loc)
    {
        if(loc == -99)
    {
        InsertAtHead(data);
        return;
    }

    Node * temp = head;
    while(temp->next!=NULL && temp->data!=loc)
    {
        temp = temp->next;
    }
    if (temp->next == NULL && temp->data == loc)
    {
        InsertAtTail(data);
        return;
    }
    Node * temp1 = new Node (data);
    temp1->next = temp->next;
    temp->next = temp1;
   
   
}
    void DeleteAtHead()
    {
        if (IsEmpty())
        {
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = tail = NULL;
        }
        Node * temp = head;
        head = head->next;
        delete temp;
    }
    void DeleteAtTail()
    {
        if (IsEmpty())
        {
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = tail = NULL;
        }
        Node * temp = head;
        while (temp->next->next != NULL )
        {
            temp = temp->next;
        }
        delete temp->next;
        tail = temp;
        tail->next = NULL;
    }
    void Display()
    {
        Node * temp = head;
        while(temp != NULL)
        {
            cout << temp->data <<endl;
            temp = temp->next;
        }
    }
    void Delete(int data)
{
    if (head->data == data)
    {
        DeleteAtHead();
        return;
    }
    Node * temp = head;
    while (temp->next!= NULL)
    {
        if (temp->next->data==data)
        {
            if (temp->next == tail)
            {
                DeleteAtTail();
                return;
            }
            Node* temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
            return;
        }
        temp = temp->next;
    }
    if (temp->data == data)
    {
        DeleteAtTail();
        return;
    }
    cout << "The data is not in Linked List.\n";
}
    void DeleteALL()
    {
        Node * temp = head;
        while (head !=NULL)
        {
            Delete(head->data);
           
        }
    }
    void Sort ()
    {
        Node *temp = head;
        while(temp !=NULL)
        {
            Node *temp1 = head;
            while(temp1!= NULL)
            {
                if (temp->data < temp1->data)
                {
                    int itemp = temp->data;
                    temp->data = temp1->data;
                    temp1->data = itemp;
                   
                }
                temp1 = temp1->next;
            }
            temp= temp->next;
        }
    }
   
    int Count()
    {
        Node * temp = head;
        int count = 0;
        while(temp != NULL)
        {
            count ++;
            temp = temp->next;
        }
        return count;
    }
};
//
int main() {
    LinkedList l1 (3);
    LinkedList l2 (6);
    l1.InsertAtHead(6);
    l1.InsertAtHead(5);
    l1.InsertAtHead(8);
    l1.InsertAtTail(2);
    l1.Display();
    cout << endl;
    //l1.DeleteAtHead();
    l1.Delete(8);
    l1.Display();
    cout << endl;
    //l1.DeleteAtTail();
    l1.Delete(2);
    l1.Display();
    cout << endl;
    l1.Delete(6);
    l1.Display();
    cout << endl;
    l1.Insert(9, -99);
    l1.Display();
    cout << endl;
    l1.Insert(7,3);
    l1.Display();
    cout << endl;
   
    //l1.DeleteALL();
    l1.Sort();
    l1.Display();
    cout << endl;
   
    cout << "The count of elements in linked list are: " << l1.Count () << endl;
    return 0;
}
