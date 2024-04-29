#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data){
    if(head == NULL){
        Node * newNode = new Node(data);
        head = newNode;
    }
    else{
        Node * newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

}

Node *getTail(Node *head){
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

Node * reverseLinkedList(Node *&head){
    //base case
    Node *prev = NULL;
    Node *curr = head;
    while(curr->next != NULL){
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr= next;
    }
    return prev;
    

}

int main(){
    Node *head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);
    insertAtHead(head, 60);

    // Node * tail = getTail(head);

    // reverseLinkedList(head, tail);

    
    Node *temp = reverseLinkedList(head);
    // Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    
 


    return 0;
}