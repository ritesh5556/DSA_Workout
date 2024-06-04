#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(int data, Node *&head, Node *&tail)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {

        head = newNode;
        tail = newNode;
        return;
    }
    Node *temp = head;
    newNode->next = temp;
    head = newNode;
}

bool checkLoop(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
       
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
         if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    // Node *head = NULL;
    // Node *tail = NULL;

    // insertAtHead(10, head, tail);
    // insertAtHead(20, head, tail);
    // insertAtHead(30, head, tail);
    // insertAtHead(40, head, tail);
    // insertAtHead(50, head, tail);

    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);

    Node *head = first;

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = second;

    if (checkLoop(head))
    {
        cout << "Loop Present " << endl;
    }
    else
    {
        cout << "Loop  is not present" << endl;
    }

    // Node *temp = head;
    // int count = 0;
    // while (temp != NULL)
    // {
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }
    cout << endl;

    return 0;
}