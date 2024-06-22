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

void printLeftView(Node *root , int level, vector<int>& leftView){
    if(root == NULL){
        return;
    }

    if(level == leftView.size()){
        leftView.push_back(root->val);
    }

    printLeftView(root->left, level+1, leftView);
    printLeftView(root->right, level+1, leftView);

}

int main(){

    Node * root = createTree();

    levelOrderTraversal(root);

    vector<int>leftView;

    printLeftView(root, 0, leftView);

    cout<<"Printing left view"<<endl;
    for(int i=0; i<leftView.size(); i++){
        cout<<leftView[i]<<" ";
    }
    cout<<endl;



    return 0;
}
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1