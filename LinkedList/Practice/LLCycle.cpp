#include <iostream>
#include<map>
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

    // Node *head = NULL;
    // Node *tail = NULL;

    // insertAtHead(10, head, tail);
    // insertAtHead(20, head, tail);
    // insertAtHead(30, head, tail);
    // insertAtHead(40, head, tail);
    // insertAtHead(50, head, tail);

    Node  *first = new Node(10);
    Node  *second = new Node(20);
    Node  *third = new Node(30);
    Node  *fourth = new Node(40);
    Node  *fifth = new Node(50);
    Node  *sixth = new Node(60);

    Node *head = first;

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = second;
    




    map<Node*, bool>table;
    Node *temp = head;

    while(temp != NULL){
        if(table[temp] == false){
            table[temp] = true;
        }
        else{
            cout<<"Loop Exist "<<endl;
            return 1;

        }
        temp = temp->next;
    }
    cout<<"Loop not exist "<<endl;







  

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