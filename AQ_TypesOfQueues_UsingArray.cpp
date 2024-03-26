#include<iostream>
#include<algorithm>
using namespace std;
class Queue{
private:
    int *array;
    int capacity;
    int index;
    int frontIndex;
    
public:
    Queue(int cap) : capacity(cap), index(-1), frontIndex(0) { // index = -1 when  queue is empty
        array = new int[capacity];  // dynamic array 
    }
    ~Queue() {
        cout << "Destructor call" << endl; 
        delete[] array;
    }
    int enqueue(int value) {
        if (isfull()) {
            cout << "Queue is full cannot enqueue.\n";
            return -1;
        }
        index++;
        array[index] = value;
        return 0; // Successful enqueue
    }
    bool isempty() {
        return (index == -1);
    }
    bool isfull() {
        return (index == capacity - 1);
    }
    int dequeue() {
        if (isempty()) {
            cout << "Queue is empty cannot dequeue.\n";
            return -1;
        }
        for (int i = 0; i < index; i++) {
            array[i] = array[i + 1];
        }
        index--;
        return 0; // Successful dequeue
    }
      // for input restricted queue
     int dequeueFromLast() {
        if (isempty()) {
            cout << "Queue is empty cannot dequeue from last.\n";
            return -1;
        }
        int dequeuedItem = array[index];
        index--;
        return dequeuedItem;
    }
    //for output restricted queue
    int enqueue_fromFront(int value){
    	  if (isfull()) {
            cout << "Queue is full cannot enqueue from front.\n";
            return -1;
        }
        for (int i = index + 1; i > 0; i--) {
            array[i] = array[i - 1];
        }
        array[0] = value;
        index++;
        return 0;
	}
    int getFront() {
        return array[frontIndex];
    }
    int getLast() {
        return array[index];
    }
    //This is for priority queue. There are two types of priority queues Ascending priority Queue and Descending Priority Queue 
    // in Ascending priority queue when elements dequeue smallest element will dequeue first 
    /**********************This function will successfully dequeue smallest element from the queue but it will sort the queue*/ 
    
    int dequeue_inAscendingOrder(){
        if (isempty()) {
            cout << "Queue is empty cannot dequeue from last.\n";
            return -1;
        }
        //Sort the array in the ascending order
        sort(array,array + capacity);
        cout << array[frontIndex] << " is dequeue successfully.\n";
        //remove 0th index value
        array[frontIndex]--;
        //---------------------Important Concpet--------------------------------
        // To delete elements in the array is not possible because of the contiguous memory locations are assigned by computer whenever array is created
        // so elements in the partially filled array cannot be deleted instead these elements  can be managed by using algorithums
        // Here first element of the array is skip successfully to hide it in the array 
		//(if array is of 4 size then 0 will be printed at the end of array)
		
        for(int i = 0; i < capacity; i++){
        	array[i] = array[i + 1];
		}
        
	}
	 int dequeue_inDescendingOrder(){
        if (isempty()) {
            cout << "Queue is empty cannot dequeue from last.\n";
            return -1;
        }
        // Sort in the ascending order
        sort(array,array + capacity);
        //Remove last element from the array because biggest element is at last(This will reduce size of array by 1)
        capacity--; 
       
	
        
	}
	void display_Queue(){
		cout << "Elements in the Queue are\n";
		for(int i = 0; i < capacity; i++){
			cout << array[i] << " ";
		}
		cout << endl;
	}
};
class CircularQueue {
private:
    int front, rear, capacity;    //As there is a need to initialize all of these so these variables are declared in the class
    int *array;                   // this is for the sake of dynamic memory allocation for array

public:
    CircularQueue(int size) {
        capacity = size;         
        front = rear = -1;  // -1 means array is empty
        array = new int[capacity];  //dynamic array
    }

    ~CircularQueue() {
        delete[] array;
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (rear == front - 1);  //if front = 0th index and rear = capacity less than 1 or front or rear = -1
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full, cannot enqueue" << endl;
            return;
        }

        if (front == -1)     
            front = 0;      // front remain 0

        if (rear == capacity - 1)   // In this case update rear 
            rear = 0;
        else
            rear = rear + 1;

        array[rear] = item;

        cout << item << " enqueued to the queue." << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue" << endl;
            return INT_MIN;
        }

        int item = array[front];   //front means 0th index 
        if (front == rear)    //front or rear ak dosry kay equal us time pe hoty hn jab dono -1 kay equal hon lakin is case me empty wala function call ho jay ga phr front or rear jab dono 0 k equal hon gay us time pe ye condition true hogi
            front = rear = -1;  
        else {
            if (front == capacity - 1)   //basic Circular queue()----->front increment hota hota ab queue ka last tk a gya ha islya isko again oth index(queue first index) ka equal kr dya ha ---->for the sake of circular queue
                front = 0; 
            else
                front = front + 1;  // Basic condition(when deque front is incremented to 1)
        }

        return item;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }
        return array[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }
        return array[rear];
    }
};

int main(){
	CircularQueue cicular_q(5);
	if(cicular_q.isEmpty()){
		cout << "Queue is empty" << endl;
		
	}
	else {
		cout << "Not empty Queue" << endl;
	}

    cicular_q.enqueue(10);
    cicular_q.enqueue(20);
    cicular_q.enqueue(30);
    cicular_q.enqueue(40);

    cout << "Front element: " << cicular_q.getFront() << endl;
    cout << "Rear element: " << cicular_q.getRear() << endl;

    cout << cicular_q.dequeue() << " dequeued from the queue" << endl;

    cicular_q.enqueue(50);

    cout << "Front element: " << cicular_q.getFront() << endl;
    cout << "Rear element: " << cicular_q.getRear() << endl;
    cicular_q.enqueue(60);
	cicular_q.enqueue(70);
	
	// input restricted queue
	cout << "Input restricted queue\n";
	Queue inRQ(5);
	inRQ.enqueue(4);
	inRQ.enqueue(2);
	inRQ.enqueue(1);
	inRQ.enqueue(6);
	inRQ.enqueue(9);
	cout << "Dequeue : " << inRQ.dequeue() << endl; 
    cout << "Front : " << inRQ.getFront() << endl;
	cout << "Last : " << inRQ.getLast() << endl;
	cout << "Dequeue from last: " << inRQ.dequeueFromLast() << endl;  
	cout << "Front : " << inRQ.getFront() << endl;
	cout << "Last : " << inRQ.getLast() << endl;
	cout << "Enqueue from tha front is\n ";
	inRQ.enqueue_fromFront(7);
	cout << "Front : " << inRQ.getFront() << endl;
	cout << "Last : " << inRQ.getLast() << endl;
	int num;
    cout << "Press 1 for Circular Queue\n";
    cout << "Press 2 for input Restricted Queue\n";
    cout << "Press 3 for output Restricted Queue\n";
    cout << "Press 4 for double Ended Queue\n";
    cout << "Press 5 for Priority Order Queue(Ascending Priority Queue)\n";
    cout << "Press 6 for Priority Order Queue(Descending Priority Queue)\n";
    cin >> num;
    int size;
    int value;
    switch (num) {
    case 1: {
        cout << "Enter size of circular queue\n";
        cin >> size;
        CircularQueue cq(size);
        do {
            cout << "Press 1 to enqueue element in circular queue\n";
            cout << "Press 2 to check if queue is empty\n";
            cout << "Press 3 to check if queue is full\n";
            cout << "Press 4 to dequeue from the Queue\n";
            cout << "Press 5 to get front element from the queue\n";
            cout << "Press 6 to get rear element from the queue\n";
            cout << "Press 7 to exit\n";
            cin >> num;
            if (num == 1) {
                cout << "Enter value you want to enqueue: ";
                cin >> value;
                cq.enqueue(value);
            } else if (num == 2) {
                if (cq.isEmpty()) {
                    cout << "Queue is empty" << endl;
                } else {
                    cout << "Not empty Queue" << endl;
                }
            } else if (num == 3) {
                if (cq.isFull()) {
                    cout << "Queue is Full" << endl;
                } else {
                    cout << "Not Full Queue" << endl;
                }
            } else if (num == 4) {
                cout << cq.dequeue() << " dequeued from the queue" << endl;
            } else if (num == 5) {
                cout << "Front element: " << cq.getFront() << endl;
            } else if (num == 6) {
                cout << "Rear element: " << cq.getRear() << endl;
            } 
        } while (num != 7);
        break; 
    }
    case 2:{
    	cout << "Enter size of queue\n";
    	cin >> size;
    	Queue inputRestricted_Q(size);
    	do{
    	cout << "Press 1 to enqueue element in Input Restricted Queue\n";
    	cout << "Press 2 to check either Input Restricted queue is empty\n";
    	cout << "Press 3 to check either Input Restricted queue is full\n";
    	cout << "Press 4 to dequeue element from the front of the Input Restricted Queue\n";
    	cout << "Press 5 to dequeue element from the last of Iutput Restricted Queue\n";
    	cout << "press 6 to get front element of Input Restricted queue\n";
    	cout << "Press 7 to get last element of Input Restricted queue\n";
    	cout << "Press 8 to exit\n";
    	cin >> num;
    	if(num == 1){
    		cout << "Enter element to enqueue : ";
    		cin >> value;
    		inputRestricted_Q.enqueue(value);
		}
		else if(num == 2){
			 if (inputRestricted_Q.isempty()) {
                    cout << "Queue is empty" << endl;
                } else {
                    cout << "Not empty Queue" << endl;
                }
		}
		else if(num == 3){
			if(inputRestricted_Q.isfull()){
				cout << "Queue is Full\n";
			}
			else {
				cout << "Not Full Queue\n";
			}
		}
		else if(num == 4){
			cout << "Dequeue from front " << inputRestricted_Q.dequeue() << endl;
		}
		else if(num == 5){
			cout << "Dequeue from last " << inputRestricted_Q.dequeueFromLast() << endl;
		}
		else if(num == 6){
			cout << "Front element : " << inputRestricted_Q.getFront() << endl;
		}
		else if(num == 7){
			cout << "Last element : " << inputRestricted_Q.getLast() << endl;
		}
		else
		{
			cout << "invalid Entry\n";
		}
    	}while(num!=8);
    	break;
    }
    	case 3:{
    	cout << "Enter size of queue\n";
    	cin >> size;
    	Queue outputRestricted_Q(size);
    	do{
    	cout << "Press 1 to enqueue element in Output Restricted Queue\n";
    	cout << "Press 2 to check either Output Restricted queue is empty\n";
    	cout << "Press 3 to check either Output Restricted queue is full\n";
    	cout << "Press 4 to dequeue element from the front of the Output Restricted Queue\n";
    	cout << "Press 5 to enqueue element from front in Output Restricted Queue\n";
    	cout << "press 6 to get front element of Output Restricted queue\n";
    	cout << "Press 7 to get last element of Output Restricted queue\n";
    	cout << "Press 8 to exit\n";
    	cin >> num;
    	if(num == 1){
    		cout << "Enter element to enqueue : ";
    		cin >> value;
    		outputRestricted_Q.enqueue(value);
		}
		else if(num == 2){
			 if (outputRestricted_Q.isempty()) {
                    cout << "Queue is empty" << endl;
                } else {
                    cout << "Not empty Queue" << endl;
                }
		}
		else if(num == 3){
			if(outputRestricted_Q.isfull()){
				cout << "Queue is Full\n";
			}
			else {
				cout << "Not Full Queue\n";
			}
		}
		else if(num == 4){
			cout << "Dequeue from front " << outputRestricted_Q.dequeue() << endl;
		}
		else if(num == 5){
			cout << "Enter value to enqueue in the queue : ";
			cin >> value;
			cout << "Enqueue from front " << outputRestricted_Q.enqueue_fromFront(value) << endl;
		}
		else if(num == 6){
			cout << "Front element : " << outputRestricted_Q.getFront() << endl;
		}
		else if(num == 7){
			cout << "Last element : " << outputRestricted_Q.getLast() << endl;
		}
		else
		{
			cout << "invalid Entry\n";
		}
    	}while(num!=8);
    	break;
    	}
    	case 4:{
    			cout << "Enter size of queue\n";
    	cin >> size;
    	Queue doubleEnded_Q(size);
    	do{
    	cout << "Press 1 to enqueue element in Double Ended Queue\n";
    	cout << "Press 2 to check either  Double Ended Queue is empty\n";
    	cout << "Press 3 to check either Double Ended Queue is full\n";
    	cout << "Press 4 to dequeue element from the front of the Double Ended Queue\n";
    	cout << "Press 5 to enqueue element from front in Double Ended Queue\n";
    	cout << "press 6 to get front element of Double Ended Queue\n";
    	cout << "Press 7 to get last element of Double Ended Queue\n";
    	cout << "Press 8 to dequeue element from last in the Queue\n";
    	cout << "Press 9 to exit\n";
    	cin >> num;
    	if(num == 1){
    		cout << "Enter element to enqueue : ";
    		cin >> value;
    		doubleEnded_Q.enqueue(value);
		}
		else if(num == 2){
			 if (doubleEnded_Q.isempty()) {
                    cout << "Queue is empty" << endl;
                } else {
                    cout << "Not empty Queue" << endl;
                }
		}
		else if(num == 3){
			if(doubleEnded_Q.isfull()){
				cout << "Queue is Full\n";
			}
			else {
				cout << "Not Full Queue\n";
			}
		}
		else if(num == 4){
			cout << "Dequeue from front " << doubleEnded_Q.dequeue() << endl;
		}
		else if(num == 5){
			cout << "Enter value to enqueue in the queue : ";
			cin >> value;
			cout << "Enqueue from front " << doubleEnded_Q.enqueue_fromFront(value) << endl;
		}
		else if(num == 6){
			cout << "Front element : " << doubleEnded_Q.getFront() << endl;
		}
		else if(num == 7){
			cout << "Last element : " << doubleEnded_Q.getLast() << endl;
		}
		else if(num == 8){
			cout << "Dequeue from last " << doubleEnded_Q.dequeueFromLast() << endl;
		}
		else
		{
			cout << "invalid Entry\n";
		}
    	}while(num!=9);
    	break;
    	}
    	case 5:
    	{   
    	    cout << "Enter the size of the Queue\n";
    	    cin >> size;
    		Queue Ascending_priorityQ(size);
    		
    			do{
    	           cout << "Press 1 to enqueue element in the Queue\n";
                   cout << "Press 2 to check either  Queue is empty\n";
    	           cout << "Press 3 to check either Queue is full\n";
    	           
    	           cout << "Press 6 to dequeue element from the queue in Ascending Order(Ascending Priority Queue)\n";
    	           cout << "Press 7 to display Queue\n";
    	           cout << "Press 8 to exit\n";
    	           cin >> num;
                      	if(num == 1){
    	            	cout << "Enter element to enqueue : ";
    	             	cin >> value;
    	            	Ascending_priorityQ.enqueue(value);
	               	}
	            	else if(num == 2){
		        	    if (Ascending_priorityQ.isempty()) {
                        cout << "Queue is empty" << endl;
                       } 
					   else {
                        cout << "Not empty Queue" << endl;
                       }
	            	}
	            	else if(num == 3){
		         	if(Ascending_priorityQ.isfull()){
				    cout << "Queue is Full\n";
		     	}
		    	else {
				cout << "Not Full Queue\n";
		    	}
	       	}
	        
			   else if(num == 6){
			   	   Ascending_priorityQ.dequeue_inAscendingOrder();
			   }
			   else if(num == 7){
			   	 Ascending_priorityQ.display_Queue();
			   }
			   
	
		else
		{
			cout << "invalid Entry\n";
		}
    	}while(num!=8);
    	break;
		}
		case 6:{
			
			{   
    	    cout << "Enter the size of the Queue\n";
    	    cin >> size;
    		Queue Descending_priorityQ(size);
    		
    			do{
    	           cout << "Press 1 to enqueue element in the Queue\n";
                   cout << "Press 2 to check either  Queue is empty\n";
    	           cout << "Press 3 to check either Queue is full\n";
    	           cout << "Press 6 to dequeue element from the queue in Descending Order(Descending Priority Queue)\n";
    	           cout << "Press 7 to display Queue\n";
    	           cout << "Press 8 to exit\n";
    	           cin >> num;
                      	if(num == 1){
    	            	cout << "Enter element to enqueue : ";
    	             	cin >> value;
    	            	Descending_priorityQ.enqueue(value);
	               	}
	            	else if(num == 2){
		        	    if (Descending_priorityQ.isempty()) {
                        cout << "Queue is empty" << endl;
                       } 
					   else {
                        cout << "Not empty Queue" << endl;
                       }
	            	}
	            	else if(num == 3){
		         	if(Descending_priorityQ.isfull()){
				    cout << "Queue is Full\n";
		     	}
		    	else {
				cout << "Not Full Queue\n";
		    	}
	       	}
			   else if(num == 6){
			   	   Descending_priorityQ.dequeue_inDescendingOrder();
			   }
			   else if(num == 7){
			   	 Descending_priorityQ.display_Queue();
			   }
			   
	
		else
		{
			cout << "invalid Entry\n";
		}
    	}while(num!=8);
    	break;
		}
		}
    default:
        cout << "Invalid Entry\n";
        break;
}
	
	return 0;
}
