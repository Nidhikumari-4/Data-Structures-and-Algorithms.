#include <iostream>
#include <string.h>
using namespace std;

class Stack
{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (top == 4) // arr[n] .......n-1= 5-1=4
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // places an item on the stack
    void push(int val)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
        }
        else
        {
            top++; // as top was -1 that means it was empty so we need to increment it
            arr[top] = val;
        }
    }

    // returns the item at the top of  stack and then removes it
    int pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return 0;
        }
        else
        {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }

    //returns the current size of stack
    int count()
    {
        return (top + 1); // top is 1 less than actual val inside stack  so we need to do top+1
    }

    //this peek(show) the stack value at the entered position
    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }

    void updateValue(int pos, int val)
    {
        if (pos > count())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[pos] = val;
            cout << "value updated at location " << pos << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            cout << "All values in the Stack are " << endl;
            for (int i = 4; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};

int main()
{
    Stack s1;
    int option, pos, val;

    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. isEmpty()" << endl;
        cout << "2. isFull()" << endl;
        cout << "3. Push()" << endl;
        cout << "4. Pop()" << endl;
        cout << "5. count()" << endl;
        cout << "6. peek()" << endl;
        cout << "7. updateValue()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl
             << endl;

        cin >> option;
        switch (option)
        {
        case 0:
            cout << "End of program" << endl;
            break;

        case 1:
            if (s1.isEmpty())
                cout << "Stack is Empty" << endl;
            else
                cout << "Stack is not Empty" << endl;
            break;

        case 2:
            if (s1.isFull())
                cout << "Stack is Full" << endl;
            else
                cout << "Stack is not Full" << endl;
            break;

        case 3:
            cout << "Enter value: " << endl;
            cin >> val;
            s1.push(val);
            break;

        case 4:
            cout << "Popped value: " << s1.pop() << endl;
            break;

        case 5:
            cout << "No. of items in stack:" << s1.count() << endl;
            break;

        case 6:
            cout << "Enter pos: " << endl;
            cin >> pos;
            cout << "peek(show) the Value at  " << pos << s1.peek(pos) << endl;
            break;

        case 7:
            cout << "Enter pos" << endl;
            cin >> pos;
            cout << "Enter val" << endl;
            cin >> val;
            s1.updateValue(pos, val);
            break;

        case 8:
            cout << "View stack: " << endl;
            s1.display();
            break;

        case 9:
            system("cls");
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}