#include<iostream>
#include<queue>
#include<vector>
#include<map>
using  namespace std;

class Node{
    public:
    int val;
    Node *left;
    Node *right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node * createTree(){
    cout<<"enter value for Node : ";
    cout<<endl;
    int value;
    cin>>value;

    if(value == -1){
        return NULL;
    }
    //create node
    Node * root = new Node(value);

    //create left tree
    cout<<"enter val for left sub tree";
    root->left = createTree();
    //create right tree
    cout<<"enter val for right sub tree";
    root->right = createTree();

    return root;
    
}

void printLeftBoundry(Node *root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }

    cout<<root->val<<" ";

    if(root->left != NULL){
        printLeftBoundry(root->left);
    }
    else{
        printLeftBoundry(root->right);
    }                       
}

void printLeafBoundry(Node *root){
    if(root == NULL){
        return ;
    }

    if(root->left == NULL && root->right == NULL){
        cout<<root->val<<" ";
    } 
    printLeafBoundry(root->left);
    printLeafBoundry(root->right);
}

void printRightBoundry(Node *root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }


    if(root->right != NULL){
        printRightBoundry(root->right);
    }
    else{
        printRightBoundry(root->left);
    } 

    cout<<root->val<<" ";                      
}

void boundryTraversal(Node *root){
    printLeftBoundry(root);
    printLeafBoundry(root);
    if(root->right != NULL){
        printRightBoundry(root->right);

    }
    else{
        printRightBoundry(root->left);
    }
    
}

int main(){
    Node * root = createTree();
    boundryTraversal(root);
    cout<<endl;

    return 0;
}

// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1