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

void levelOrderTraversal(Node * root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node * curr = q.front();
        q.pop();
        if(curr == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        
    }
}


int main(){

    Node *root = createNode();
    levelOrderTraversal(root);


    return 0;
}

//10 20 40 -1 -1 50 90 -1 -1 100 -1 -1 30 60 -1 -1 70 -1 -1