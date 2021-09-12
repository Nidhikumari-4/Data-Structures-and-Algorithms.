#include <iostream>
using namespace std;

#define SIZE n

class CircularDeQueue
{
    int n;
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularDeQueue()
    {
        arr = new int[n]; //Create the array
        front = -1;
        rear = -1;
        size = 0;
    }
    
    // empty or not
    bool isEmpty()
    {
        return (rear == -1 && front == -1);
    }

   // full or not
    bool isFull()
    {
        return ((rear + 1) % n == front);
    }

   // count()-count no of elemnets
    int Count()
    {
        return size;
    }

    // get first-returns first element
    int getFirst()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            return 0;
        }
        return arr[front];
    }

    // get last-returns last element
    int getLast()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            return 0;
        }
        return arr[rear];
    }
    
    //add first()-inserts element at front
    void addFirst(int val)
    {
        if (isFull())
        {
            cout << "Queue is full";
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = n - 1; //size-1
        }
        else
        {
            front--;
            cout << front;
        }
        arr[front] = val;
        size++;
    }
    
    //add last()-inserts element at back
    void addLast(int val)
    {
        if (isFull())
        {
            cout << "Queue  is full";
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % n;
        }
        arr[rear] = val;
        size++;
    }

    // remove first()- removes first element
    int removeFirst()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Queue is empty";
            return 0;
        }
        else if (rear == front)
        {
            x = arr[front];
            front = rear = -1;
            size--;
            return x;
        }
        else
        {
            x = arr[front];
            front = (front + 1) % n;
            size--;
            return x;
        }
    }

    //remove last()-removes last element
    int removeLast()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Queue is empty";
            return 0;
        }
        else if (rear == front)
        {
            x = arr[front];
            front = rear = -1;
            size--;
            return x;
        }
        else if (rear == 0)
        {
            x = arr[rear];
            rear = n - 1;
            size--;
            return x;
        }
        else
        {
            x = arr[rear];
            rear--;
            size--;
            return x;
        }
    }

    //display elements 
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            return;
        }
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % n;
        }
        cout << arr[i] << " ";
    }
};

int main()
{
    CircularDeQueue d1;
    int val;
    int ch;

    do
    {
        cout << "\n *********MENU*********\n"
             << endl;
        cout << "1___addFirst()" << endl;
        cout << "2___addLast()" << endl;
        cout << "3___isEmpty" << endl;
        cout << "4___isFull" << endl;
        cout << "5___removeFirst()" << endl;
        cout << "6___removeLast()" << endl;
        cout << "7___getFirst()" << endl;
        cout << "8___getLast()" << endl;
        cout << "9___count(Current size of Dequeue)" << endl;
        cout << "10___display" << endl;
        cout << "11___clear screen" << endl;
        cout << "0....EXIT." << endl;
        cout << "\nEnter your choice : ";

        cin >> ch;

        switch (ch)
        {
        case 0:
            cout << "\nEnd of program" << endl;
            break;

        case 1:
            cout << "\nEnter value: " << endl;
            cin >> val;
            d1.addFirst(val);
            break;

        case 2:
            cout << "\nEnter value: " << endl;
            cin >> val;
            d1.addLast(val);
            break;

        case 3:
            if (d1.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty" << endl;
            break;

        case 4:
            if (d1.isFull())
                cout << "Queue is FULL" << endl;
            else
                cout << "Queue is not FULL" << endl;
            break;

        case 5:
            cout << d1.removeFirst();
            break;

        case 6:
            cout << d1.removeLast();
            break;

        case 7:
            cout << d1.getFirst();
            break;

        case 8:
            cout << d1.getLast();
            break;

        case 9:
            cout << "Count the elements in Queue : " << d1.Count() << endl;
            break;

        case 10:
            d1.display();
            break;

        case 11:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }
    } while (ch != 0);

    return 0;
}