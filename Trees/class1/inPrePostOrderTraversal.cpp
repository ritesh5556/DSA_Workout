#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        this->data = val;
        this->left= NULL;
        this-> right = NULL;
    }
};

Node * createTree(){
    cout<<"Enter value for Node : "<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    //step:1 create Node
    Node * root = new Node(data);

    //create left sub-tree
    root->left = createTree();

    //create right sub-tree
    root->right = createTree();


    return root;
}

void preOrderTraversal(Node* root){
    //NLR

    if(root == NULL){
        return;
    }

    //N
    cout<<root->data<<" ";
    //L
    preOrderTraversal(root->left);

    //R
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    //LNR

    if(root == NULL){
        return;
    }

    //L
    inOrderTraversal(root->left);
    //N
    cout<<root->data<<" ";
    //R
    inOrderTraversal(root->right);

}

void postOrderTraversal(Node* root){
    //LRN
    if(root  == NULL){
        return;
    }

    //L
    postOrderTraversal(root->left);
    //R
    postOrderTraversal(root->right);
    //N
    cout<<root->data<<" ";
}

int main(){

    Node *root = createTree();

    cout<<"printing  preOrder : ";
    preOrderTraversal(root);
    cout<<endl;

    cout<<"printing  inOrder : ";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"printing  postOrder : ";
    postOrderTraversal(root);
    cout<<endl;


    

    return 0;
}