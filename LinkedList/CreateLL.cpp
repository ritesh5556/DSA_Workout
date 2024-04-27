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

void insertAtTail(Node *&head, int data){
    if(head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
    }   
    else{
        Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(data);
    temp->next = newNode;
    
    
    }
}

int lenght(Node *head){
    Node *temp = head;
    int count=0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
        
    }
    return count;
}

void insertAtPosition(Node *&head, int data, int pos){
    int len = lenght(head);
    cout<<"len -> "<<len<<endl;
    if(pos <= 1){
        insertAtHead(head, data);
    }
    else if(pos >= len){
        insertAtTail(head, data);
    }
    else{
        Node *curr = head;
        Node *prev = NULL;
        while (pos !=1)
        {
            pos--;
             prev = curr;
            curr = curr->next;
           
        }
        Node *newNode = new Node(data);
        newNode->next = curr;
        prev->next= newNode;
 
    }
}

void deleteHead(Node *&head){
    Node *temp = head;
    head = head->next;
    delete temp;

}

void deleteTail(Node  *&head){
    Node *prev = NULL;
    Node *curr = head;
    while(curr->next != NULL){
        prev = curr;
        curr= curr->next;
    }
    prev->next = NULL;
    delete curr;

}

void deleteAtPosition(Node *&head, int pos){
    int len = lenght(head);
    cout<<"len -> "<<len<<endl;
    if(pos <= 1){
        deleteHead(head);
    }
    else if(pos >= len){
        deleteTail(head);
    }
    else{
        Node *prev = NULL;
    Node* curr = head;
    while(pos != 1){
        pos--;
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    }
}

int main(){

    Node *head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 50);
    insertAtHead(head, 60);

    // insertAtTail(head, 500);
    //     insertAtTail(head, 600);
    // insertAtTail(head, 700);

    // insertAtPosition(head, 900, 2);

    // deleteHead(head);
    // deleteHead(head);
    // deleteHead(head);

    // deleteTail(head);
    //     deleteTail(head);
    //     deleteTail(head);

    deleteAtPosition(head, 4);
    

    



    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    

    return 0;
}



    // Node * node1 = new Node(10);
    //     Node * node2 = new Node(20);

    // Node * node3 = new Node(30);

    // Node * node4 = new Node(40);

    // Node * node5 = new Node(50);
    // node1->next = node2;
    // node2->next = node3;
    // node3->next = node4;
    // node4->next = node5;

    


