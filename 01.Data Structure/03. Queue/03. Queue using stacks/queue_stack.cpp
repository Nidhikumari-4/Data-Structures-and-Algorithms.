#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class queue_Stack
{
    stack<int> st1;
    stack<int> st2;
    int size;
    int peek;

public:
    queue_Stack()
    {
        size = 0;
        int peek = 0;
    }

public:
    int count()
    {
        return size;
    }

    bool empty()
    {
        if (st1.empty() && st2.empty())
            cout << "Queue is Empty" << endl;
        else
            cout << "Queue is not Empty" << endl;
    }

    int enQueue(int data)
    {
        st1.push(data);
        size++;
    }

    int deQueue()
    {
        if (st1.empty() && st2.empty())
        {
            cout << "queue is Empty";
            return 0;
        }
        // if st2 is empty, move
        // elements from st1
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            
        }
        // return the top item from st2
        size--;
        int x = st2.top();
        st2.pop();
        return x;
        
    }

    /** Get the front element. */
    int top()
    {
        // shift st1 to st2
        if (st2.empty()){
            while (!st1.empty())
            {
                st2.push(st1.top()),
                    st1.pop();
            }
        
    }
    return st2.top();
    }

    void display()
    {
        while (!st1.size())
        {
            cout << st1.top() << endl;
            st1.pop();
        }
        cout << st2.top()<<endl;
        
    }
};

int main()
{
    queue_Stack q1;
    int option, data;

    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. enqueue()" << endl;
        cout << "2. dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. peek()" << endl;
        cout << "5. count()[current size of queue]" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl;
        cout << "0. Exit" << endl
             << endl;

        cin >> option;
        switch (option)
        {
        case 0:
            cout << "End of program" << endl;
            break;

        case 1:
            cout << "Enter value: " << endl;
            cin >> data;
            q1.enQueue(data);
            break;

        case 2:
            cout << "\nDequeued Value : " << q1.deQueue() << endl;
            break;

        case 3:
            q1.empty();
            break;

        case 4:
            cout << "show the top Value  " << q1.top() << endl;
            break;

        case 5:
            cout << "No. of items in queue:" << q1.count() << endl;
            break;

        case 6:
            cout << "View queue: " <<" ";
            q1.display();

            break;

        case 7:
            system("cls");
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}