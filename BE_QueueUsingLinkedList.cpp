// Use FIFO Rule(First in First Out). Two ends are required just like pipe(one end is for insertion/pushing and other end is for remvoing)
// Linekd list code (Insert at tail(enqueue(insert element into queue)) and delete from head(dequeue(means remove)))
#include <iostream>
using namespace std;
class Queue
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
    Node * front;  // head node
    Node * rear; // tail node
public:
    Queue()
    {
        rear == NULL;
        front == NULL;
    }
    
    bool IsEmpty()
    {
        return front == NULL;
    }
    //insert at tail  in Linked List
    void Enqueue(int data)
    {
        if (IsEmpty())
        {
            rear = new Node (data);
            front = rear;
            return;
        }
        Node *temp = front;
        while(temp != NULL){
        	temp = temp->next;
		}
		Node *newnode = new Node(data);
		rear->next = newnode;
		rear = newnode;
		rear->next = NULL;
    }
    // Delete At head in Linked List
    void Dequeue()
    {
        if (IsEmpty())
        {
        	cout << "Queue is Empty\n";
            return;
        }
        if(front->next == NULL){
        	delete front;
        	front = NULL;
		}
       Node *temp = front;
       front = front->next;
       delete temp;
       temp = NULL;
   }
       
    void Display()
    {
    	 if (IsEmpty())
        {
        	cout << "Queue is Empty\n";
            return;
        }
        Node * temp = front;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main(){
    Queue q;
    q.Display();
    q.Dequeue();
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Display();
	cout << endl;
	cout << "Dequeue Two Times\n";
	q.Dequeue();
	q.Dequeue();

	q.Display();
	
	return 0;
}
