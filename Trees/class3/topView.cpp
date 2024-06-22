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

void topView(Node *root){
    map<int, int> hdToNode;
    
    queue<pair<Node*, int> >q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node  *frontNode = temp.first;
        int  hd = temp.second;

        //if there  is no entry for hd in map. then create entry
        if(hdToNode.find(hd) == hdToNode.end()){
            hdToNode[hd] = frontNode->val;
        }

        //child ko dekhna h
        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    for(auto i: hdToNode){
        cout<<i.second<<" ";
    }
    cout<<endl;
    

}



int main(){

    Node * root = createTree();

    levelOrderTraversal(root);
    cout<<"printing top view "<<endl;

    topView(root);

  



    return 0;
}
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1