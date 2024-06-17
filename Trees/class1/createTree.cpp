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

int main(){

    Node *root = createTree();

    cout<<root->data <<endl;
    

    return 0;
}