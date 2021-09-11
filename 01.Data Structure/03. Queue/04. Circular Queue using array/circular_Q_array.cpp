#include<iostream>
using namespace std;

class CircularQueue {
  private:
    int front;
    int rear;
    int size;
    int arr[5];

  public:
    CircularQueue() {
      size=0;
      front = -1;
      rear = -1;
      for (int i = 0; i < 5; i++) {
        arr[i] = 0;
      }
    }

//isEmpty() – Check if queue empty or not.
  bool isEmpty() {
    if (front == -1 && rear == -1)
      return true;
    else
      return false;
  }

//isFull() – Check if queue is full or not.
  bool isFull() {
    if ((rear+1)%5 == front)    //(rear+1)%n here n=5
      return true;
    else
      return false;
  }

//Enqueue() – Add item to the queue from the REAR.
  void enqueue(int val) {
    if (isFull()) {
      cout << "Queue full" << endl;
      return;
    } else if (isEmpty()) {
      rear = 0;
      front = 0;
      arr[rear] = val;
      
    } else {
      rear=(rear+1)%5;  //(rear+1)%n here n=5
      arr[rear] = val;
      
    }
     size++;
  }

//Dequeue() – Remove item from the queue from the FRONT.
  int dequeue() {
    int x;
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return 0;
    } else if (rear == front) {
      x = arr[rear]; //or  x = arr[front];
      arr[rear]=0;  //  or arr[front]=0;
      rear = -1;
      front = -1;
      size--;
      return x;
      
    } else {
      cout << "front value: " << front << endl;
      x = arr[front];
      arr[front] = 0;
      front=(front+1)%5;  //(front+1)%n here n=5
      size--;
      return x;
     
    }
    
  }

//peek()-return front elemenet in the queue(line).
  int peek(){
      if(isEmpty()){
          cout<<"No elements in queue"<<endl;
          return -1;
      }
      return arr[front];
  }

//count() – Get number of items in the queue.
  int count() {
    return size;
  }

//Display() - Display the queue
  void display() {
    cout << "All values in the Queue are - " << endl;
    for (int i = 0; i < 5; i++) {
      cout << arr[i] << "  ";
    }
  }

};

int main() {
  CircularQueue q1;
  int value, option;

  do {
    cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. count()" << endl;
    cout << "6. peek()" << endl;
    cout << "7. display()" << endl;
    cout << "8. Clear Screen" << endl << endl;

    cin >> option;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Enqueue Operation \nEnter an item to Enqueue(Add item) in the Queue" << endl;
      cin >> value;
      q1.enqueue(value);
      break;
    case 2:
      cout << "Dequeue(Remove item ) Operation \nDequeued Value : " << q1.dequeue() << endl;
      break;
    case 3:
      if (q1.isEmpty())
        cout << "Queue is Empty" << endl;
      else
        cout << "Queue is not Empty" << endl;
      break;
    case 4:
      if (q1.isFull())
        cout << "Queue is Full" << endl;
      else
        cout << "Queue is not Full" << endl;
      break;
    case 5:
      cout << "Count Operation \nCount of items in Queue : " << q1.count() << endl;
      break;
    case 6:
      cout<< "peek operation(return front elemenet in the queue(line).) \nPeek value is: "<<q1.peek()<<endl;
      break;
    case 7:
      cout << "Display Function Called - " << endl;
      q1.display();
      break;
    case 8:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}