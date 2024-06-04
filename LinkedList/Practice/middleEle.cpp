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

int findMiddleEle(Node  *&head){
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast ->next;
            slow = slow->next;
        }
    }
    cout<<"Middle Ele : "<<slow->data;
    return slow->data;
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
    insertAtHead(60, head, tail);

 
findMiddleEle(head);
cout<<endl;
    

    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}