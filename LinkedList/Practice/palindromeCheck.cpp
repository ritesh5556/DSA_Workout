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

Node *findMid(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

bool compareLL(Node *head1, Node *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(10, head, tail);
    insertAtHead(20, head, tail);
    insertAtHead(30, head, tail);
    insertAtHead(50, head, tail);
    insertAtHead(30, head, tail);
    insertAtHead(20, head, tail);
    insertAtHead(10, head, tail);

    Node *mid = findMid(head);
    Node *head2 = mid->next;
    mid->next == NULL;

    head2 = reverseLL(head2);

    if (compareLL(head, head2))
    {
        cout << "isPalindrome " << endl;
    }
    else
    {
        cout << "notPalindrome " << endl;
    }

    return 0;
}