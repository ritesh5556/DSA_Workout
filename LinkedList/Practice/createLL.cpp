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

void insertAtTail(int data, Node *&head, Node *&tail)
{
    Node *newNode = new Node(data);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    Node *temp = tail;
    temp->next = newNode;
    tail = newNode;
}

int findLength(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtPos(int data, Node *&head, Node *&tail, int pos)
{
    int length = findLength(head);

    if (head == NULL || pos <= 1)
    {
        insertAtHead(data, head, tail);
        return;
    }
    else if (pos >= length)
    {
        insertAtTail(data, head, tail);
        return;
    }
    else
    {
        Node *newNode = new Node(data);
        Node *curr = head;
        Node *prev = NULL;
        cout << "pos : " << pos << endl;
        while (--pos)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
        newNode->next = curr;
    }
}

void deleteHead(Node *&head){
    if(head == NULL){
        cout<<"Linked List is empty "<<endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    return;
}

void deleteTail(Node  *&head, Node *&tail){
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return;
    }
    Node *curr = head;
    Node *prev = NULL;
    while(curr->next !=NULL){
        prev = curr;
        curr = curr->next;
    }
    tail = prev;
    prev->next = NULL;
    delete curr;

}

void deleteAtPos(Node *&head, Node *& tail, int pos){
    int length = findLength(head);
    if(head == NULL || pos <= 1){
        deleteHead(head);
        return;
    }
    else if(pos >= length){
        deleteTail(head, tail);
        return;
    }
    else{
        Node *curr = head;
        Node *prev = NULL;
        while(--pos){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
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
    // insertAtTail(500, head, tail);
    // insertAtTail(900, head, tail);
    // cout<<"length : "<< findLength(head)<<endl;
    // insertAtPos(500, head, tail, 1);

    // deleteHead(head);

    // deleteTail(head, tail);
        // deleteTail(head, tail);
        //     deleteTail(head, tail);

    deleteAtPos(head, tail, 3);


    
    

    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node *five = new Node(50);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = five;
    // Node *temp = first;
    // while(temp != NULL){
    //     cout<<temp->data<<" ";
    //     temp = temp->next;
    // }

    return 0;
}