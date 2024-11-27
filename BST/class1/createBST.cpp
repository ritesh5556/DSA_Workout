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

Node *insertIntoBst(Node *root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data < root->data){
        root->left = insertIntoBst(root->left, data);
    }
    else{
        root->right = insertIntoBst(root->right, data);
    }

    return root;
}

void createBst(Node *& root){
    int data;
    cout<<"Enter data : ";
    cin>>data;

    while(data != -1){                                                                                                                                                                                                                                                                                                                                                                                                                                                           
        root = insertIntoBst(root, data);
        cout<<"Enter data : ";
        cin>>data;
    }
}

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

void inorder(Node *root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void preorder(Node *root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);

    preorder(root->right);

}

void postorder(Node *root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    postorder(root->left);

    postorder(root->right);

}


bool searchInBst(Node *root, int target){
    if(root == NULL) return false;

    if(root->data == target){
        return true;
    }

    bool leftAns;
    bool rightAns;
    
    if(target > root->data){
        leftAns = searchInBst(root->right, target);
    }
    else{
        rightAns = searchInBst(root->left, target);
    }

    return leftAns || rightAns;
}

Node *maxValue(Node * root){
    if(root == NULL) return NULL;

    Node *temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }

    return temp;
}


Node *minValue(Node * root){
    if(root == NULL) return NULL;

    Node *temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

///////////////////// Delete From   Binary Search Tree ////////////////////////////

Node * deleteFromBst(Node *root, int target){
    if(root == NULL) return NULL;

    if(root->data == target){
        // root left null and root right null
        if(root->left == NULL && root->right == NULL){
            delete(root);
            return NULL;
        }
        else if(root->left != NULL && root->right == NULL){
            Node * childSubTree = root->left;
            delete root;
            return childSubTree;
        }
        else if(root->left == NULL && root->right != NULL){
            Node *childSubTree = root->right;
            delete root;
            return childSubTree;
        }
        else{
            Node * maxi = maxValue(root->left);
            root->data = maxi->data;

            root->left = deleteFromBst(root->left , maxi->data);

            return root;
        }
    }

    if(root->data > target){
        root->left = deleteFromBst(root->left, target);
    }
    else{
        root->right = deleteFromBst(root->right, target);
    }

    return root;
}




int main(){

    Node * root = NULL;

    createBst(root);

    cout<<endl;

    levelTraversal(root);

    int target;
    cout<<"Enter target : ";
    cin>> target;

    while(target != -1){
        Node * newRoot = deleteFromBst(root, target);
        cout<< endl <<" printing level order " <<endl;
        levelTraversal(newRoot);
        cout<<"Enter target : ";
        cin>> target;
    }


    // cout<<endl<<"Inorder : ";
    // inorder(root);
    
    // cout<<endl <<"PreOrder : ";
    // preorder(root);

    // cout<< endl <<"PostOrder : ";
    // postorder(root);

    // cout<<endl;

    // int target = 101;

    // if(searchInBst(root, target)){
    //     cout<<"Found";
    // }
    // else cout<<"Not Found";

    cout<<endl;
    return 0;
}

// 50 30 40 20 60 55 70 80 25 -1