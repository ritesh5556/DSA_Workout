#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left =  NULL;
        right = NULL;
    }
};

void levelTraversal(Node *root){
    if(root == NULL) return;

    queue <Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node * frontNode = q.front();
        q.pop();

        if(frontNode == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
            continue;
        }

        cout<<frontNode->data<<" ";

        if(frontNode->left){
            q.push(frontNode->left);
        }
        if(frontNode->right){
            q.push(frontNode->right);
        }
    }
}

Node * bstFromInorder(int inorder[], int s, int e){
    if(s > e) return NULL;

    int mid = (s+e) /2 ;

    Node *root = new Node(inorder[mid]);

    root->left = bstFromInorder(inorder, s, mid-1);

    root->right = bstFromInorder(inorder, mid+1, e);

    return root;
}



int main(){

    int inorder[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    int s = 0;
    int e = size-1;

    Node *root = bstFromInorder(inorder, s,  e);
    cout<<endl;
    levelTraversal(root);

    cout<<endl;

    return 0;

}