#include<iostream>
#include<queue>
#include<vector>
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

void levelOrderTraversal(Node  * root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->val<<" ";

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }

        }
    }
    
}

void printRightView(Node *root , int level, vector<int>& rightView){
    if(root == NULL){
        return;
    }

    if(level == rightView.size()){
        rightView.push_back(root->val);
    }
    printRightView(root->right, level+1, rightView);
    printRightView(root->left, level+1, rightView);
    

}

int main(){

    Node * root = createTree();

    levelOrderTraversal(root);

    vector<int>rightView;

    printRightView(root, 0, rightView);

    cout<<"Printing left view"<<endl;
    for(int i=0; i<rightView.size(); i++){
        cout<<rightView[i]<<" ";
    }
    cout<<endl;



    return 0;
}
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1