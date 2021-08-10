#include <iostream>
using namespace std;

class SinglyLinkedList
{
public:
    class Node
    {
    public:
        int data; //Whenever a node is created it has data 
        Node *next; // and other is a pointer pointing next

        Node(int d)
        {
            data = d; // whenever a node is created it has no data ,we need to enter data
            next = NULL;//and next always points to NULL
        } 
    };

    int size;      //whenever a LL is created LL has size     
    Node *head;   // and a pointer type node  pointing Head

    SinglyLinkedList()
    {
        size = 0;     //whenever a LL is created its size is always 0
        head = NULL;    // and head is NULL
    }

    //1.Insert node first-->Insert node at beginning of LL
public:
    void InsertNodeFirst(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL) //is my LL empty?
        {
            head = newNode;
        }
        else
        {
            newNode->next = head; // point NN  next there where head is pointing.
            head = newNode;       //HEAD IS GIVING ORDER go and point newNode.
        }
        size++;
    }

    //2.Insert node last-->Insert node at Last of LL
    void InsertNodeLast(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next; //PTR go and point there where PTR's next is pointing
                }
                // we can give order only to pointer or node's next
            ptr->next = newNode; // PTR's next go and point newNode
            size++;
        }
    }

    //3. Insert node at pos--->Insert node at a given position in a LL
    void InsertAtPos(int pos, int val)
    {
        if (head == NULL)
        {
            cout << "LL is already empty";
            return;
        }
        else if (pos == 1)
        {
            InsertNodeFirst(val);
        }
        else if (pos == size + 1)
        {
            InsertNodeLast(val);
        }
        else
        {
            Node *newNode = new Node(val);
            Node *ptr = head;
            for (int i = 0; i < pos - 2; i++)
            {
                ptr = ptr->next;
            }
            newNode->next = ptr->next; // newNode's next go and point there where PTR's next is pointing
            ptr->next = newNode;
            size++;
        }
    }
    // we make extra ptr when we have to do something related to pos operation ,last operation

    //4. Delete node first---->Delete node at First of LL
    void DeleteNodeFirst()
    {
        if (head == NULL)
        {
            cout << "LL is empty";
            return;
        }
        else
        {
            Node *ptr = head;
            head = head->next; // or head=ptr ->next;
            ptr->next = NULL;
            size--;
        }
    }

    //5. Delete node last--->Delete node at Last of LL
    void DeleteNodeLast()
    {
        if (head == NULL)
        {
            cout << "LL is empty";
            return;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = NULL;
            size--;
        }
    }

    //6. Delete node at pos---->Delete node at a given position in a LL
    void DeleteNodeAtPosition(int pos)
    {
        if (head == NULL || pos > size || pos < 1)
        {
            cout << "Delete not possible";
            return;
        }
        else if (pos == 1)
        {
            DeleteNodeFirst();
        }
        else if (pos == size)
        {
            DeleteNodeLast();
        }
        else
        {
            Node *ptr = head;
            for (int i = 0; i < pos - 2; i++)
            {
                ptr = ptr->next;
            }

            Node *temp = ptr->next;
            ptr->next = ptr->next->next;
            temp->next = NULL;
            size--;
        }
    }

    //7. Reverse  list
    void ReverseList()
    {
        if (head == NULL)
        {
            cout << "LL is empty";
            return;
        }
        else
        {
            Node *pre = NULL;
            Node *curr = head;
            Node *next = NULL;

            while (curr != NULL)
            {
                next = curr->next;
                curr->next = pre;
                pre = curr;
                curr = next;
            }
            head = pre;
        }
    }

    //8. Update list
    void UpdateList(int pos, int val)
    {
        if (head == NULL || pos > size || pos < 1)
        {
            cout << "Update not possible";
            return;
        }
        else
        {
            Node *ptr = head;
            for (int i = 0; i < pos - 1; i++)
            {
                ptr = ptr->next;
            }
            ptr->data = val;
        }
    }
    
    //9. Count/Find list size
    int CountList()
    {
        return size;
    }

    //10. Display list
    void DisplayList()
    {
        if (head == NULL)
        {
            cout << "No list to Display";
        }
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ---->";
            ptr = ptr->next;
        }
        cout << "NULL";
    }
};

int main()
{
    SinglyLinkedList Sl;
    int ch;
    int pos, val;
    do
    {
        cout << "\n *******MENU*******\n"
             << endl;
        cout << "1______ Insert Node at First." << endl;
        cout << "2______Insert Node at the Last." << endl;
        cout << "3______Insert Node at any given position." << endl;
        cout << "4______Delete Node at first." << endl;
        cout << "5______Delete Node at last." << endl;
        cout << "6______Delete Node at any given position." << endl;
        cout << "7______Reverse the List." << endl;
        cout << "8______Update a Node." << endl;
        cout << "9______Count the List." << endl;
        cout << "10______Display the List." << endl;
        cout << "0.....EXIT." << endl;
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 0:
            cout << "\nEnd of Program" << endl;
            break;
        case 1:
            cout << "Enter value: ";
            cin >> val;
            Sl.InsertNodeFirst(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            Sl.InsertNodeLast(val);
            break;
        case 3:
            cout << "Enter pos: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            Sl.InsertAtPos(pos, val);
            break;
        case 4:
            Sl.DeleteNodeFirst();
            break;
        case 5:
            Sl.DeleteNodeLast();
            break;
        case 6:
            cout << "Enter pos: ";
            cin >> pos;
            Sl.DeleteNodeAtPosition(pos);
            break;
        case 7:
            Sl.ReverseList();
            break;
        case 8:
            //int pos,val;
            cout << "Enter pos: ";
            cin >> pos;
            cout << "Enter val: ";
            cin >> val;
            Sl.UpdateList(pos, val);
            break;
        case 9:
            cout << Sl.CountList() + 1;
            break;
        case 10:
            Sl.DisplayList();
            break;
        default:
            cout << "\nInvalid Input!!" << endl;
            break;
        }
    } while (ch != 0);

    return 0;
}
