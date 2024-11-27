#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    Node *left;
    Node *right;
    int data;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *createNode(){
    cout<<"enter data : "<<endl;
    int data;
    cin>>data;

    if(data == -1) return NULL;

    Node *root = new Node(data);

    root->left = createNode();
    root->right = createNode();

    return root;
}

void preOrder(Node *head){
    Node *root = head;
    if(root == NULL) return;

    cout<<root->data<<" ";
   preOrder(root->left);
   preOrder(root->right);
}

void postOrder(Node *head){
    Node *root = head;
    if(root == NULL) return;

    
   postOrder(root->left);
   postOrder(root->right);
   cout<<root->data<<" ";
}

void inOrder(Node *head){
    Node *root = head;
    if(root == NULL) return;

   
   inOrder(root->left);
    cout<<root->data<<" ";
   inOrder(root->right);
}

int main(){

    Node *root = createNode();

    cout<<"preOrder : ";
    preOrder(root);
    cout<<endl;

    cout<<"postOrder : ";
    postOrder(root);
    cout<<endl;


    cout<<"inOrder : ";
    inOrder(root);
    cout<<endl;


    return 0;
}