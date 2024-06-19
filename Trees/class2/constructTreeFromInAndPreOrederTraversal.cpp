#include<iostream>
#include<queue>
#include<map>
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

void searchInorder(int inorder[], int size, map<int, int> &valueToIndexMap){
    for(int i=0; i<size; i++){
        int element = inorder[i];
        int index = i;
        valueToIndexMap[element] = i;
    }
}

int searchEle(int inorder[], int size, int element){
    for(int i=0;  i<size; i++){
        if(inorder[i] == element){
            return i;
        }
    }
    return -1;
}

Node * constructTreeFromPreAndInOrderTraversal(map<int, int> &valueToIndexMap, int postorder[] ,int inorder[], int size, int &postOrderIndex,
int inOrderStart, int inOrderEnd){
    if(postOrderIndex <0 || inOrderStart > inOrderEnd){
        return NULL;
    }

    //1st case  main solve karunga
    int element = postorder[postOrderIndex];
    postOrderIndex--;

    //element search karna padega inorder me
    
    // int pos = searchEle(inorder, size, element);
    int pos = valueToIndexMap[element];

    Node *root = new Node(element);

    //baaki recursion sambhal lega
    root->right = constructTreeFromPreAndInOrderTraversal(valueToIndexMap, postorder, inorder, size, postOrderIndex, pos+1, inOrderEnd);

    root->left = constructTreeFromPreAndInOrderTraversal(valueToIndexMap, postorder, inorder, size, postOrderIndex, inOrderStart, pos-1);

    return root;

}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";

            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}

int main(){
    int inorder[] = {8,14, 6, 2, 10, 4};
    int postorder[] = {8, 6, 14, 4, 10, 2};
    int size = 6;
    int postOrderIndex = size-1;
    int inOrderStart = 0;
    int inOrderEnd = 5;

    map<int, int> valueToIndexMap;

    searchInorder(inorder, size, valueToIndexMap);

    Node *root = constructTreeFromPreAndInOrderTraversal(valueToIndexMap, postorder, inorder, size, postOrderIndex, inOrderStart, inOrderEnd);
    levelOrderTraversal(root);
    return 0;
}