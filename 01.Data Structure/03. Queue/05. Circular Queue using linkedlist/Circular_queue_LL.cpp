#include <iostream>
using namespace std;

class CircularQueue_LL
{
public:
    class Node
    {
    public:
        int data;
        Node *next;

        Node(int d)
        {
            data = d;
            next = NULL;
        }
    };

    Node *front;
    Node *rear;
    int size;

     CircularQueue_LL()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    //isEmpty() – Check if queue empty or not.
    bool empty()
    {
        if (front == NULL)
            return true;
        return false;
    }

    //isFull() – Check if queue is full or not.
    bool isFull()
    {
        if (front == rear)
            cout << "Queue is full" << endl;
        else
            cout << "Queue is not full" << endl;
    }

    //Enqueue() – Add item to the queue from the REAR.
    int enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (empty())
        {
            rear = newNode;
            front = newNode;
           
        }
        else{
        rear->next = newNode;
        rear = newNode;
        newNode->next=front;  //for circular queue
        }
        size++;
    }

    //Dequeue() – Remove item from the queue from the FRONT.
    int dequeue()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        else if (front == rear)
        {
            Node *del = front;
            front = rear = NULL;

            size--;
            return del->data;
        }
        else
        {
            Node *del = front;
            front = front->next;
            rear->next=front;    //for circular queue
            del->next = NULL;

            size--;
            return del->data;
        }
    }

    //count() – Get number of items in the queue.
    int count()
    {
        return size;
    }

    //peek()-return front elemenet in the queue(line).
    int peek()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    //Display() - Display the queue
    void display()
    {
        Node *temp = front;
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        do
        {
            cout << temp->data << "-----> ";
            temp = temp->next;
        }while (temp != front);
        cout<<temp->data;
    }
};

int main()
{
    CircularQueue_LL Q1;
    int data;
    int ch;

    do
    {
        cout << "\n *********MENU*********\n"
             << endl;
        cout << "1___enqueue" << endl;
        cout << "2___dequeue" << endl;
        cout << "3___isEmpty" << endl;
        cout << "4___isFull" << endl;
        cout << "5___peek" << endl;
        cout << "6___count" << endl;
        cout << "7___display" << endl;
        cout << "8___clear screen" << endl;
        cout << "0....EXIT." << endl;
        cout << "\nEnter your choice : ";

        cin >> ch;

        switch (ch)
        {
        case 0:
            cout << "\nEnd of program" << endl;
            break;

        case 1:
            cout << "\nEnter an item" << endl;
            cin >> data;
            Q1.enqueue(data);
            break;

        case 2:
            cout << "\nDequeued Value : " << Q1.dequeue() << endl;
            break;

        case 3:
            if (Q1.empty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty" << endl;
            break;

        case 4:
            Q1.isFull();
            break;

        case 5:
            cout << "peek operation(return front elemenet in the queue(line).) \nPeek value is: " << Q1.peek() << endl;
            break;

        case 6:
            cout << "Count of items in Queue : " << Q1.count() << endl;
            break;

        case 7:
            cout << "Display Function Called - " << endl;
            Q1.display();
            break;

        case 8:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }
    } while (ch != 0);

    return 0;
}