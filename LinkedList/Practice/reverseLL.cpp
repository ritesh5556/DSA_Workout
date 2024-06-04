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

Node *reverseLL(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(10, head, tail);
    insertAtHead(20, head, tail);
    insertAtHead(30, head, tail);
    insertAtHead(40, head, tail);
    insertAtHead(50, head, tail);

    Node *newHead = reverseLL(head);

    while (newHead != NULL)
    {
        cout << newHead->data << " ";
        newHead = newHead->next;
    }
    cout << endl;

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