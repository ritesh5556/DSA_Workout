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

Node * constructTreeFromPreAndInOrderTraversal(map<int, int> &valueToIndexMap, int preorder[] ,int inorder[], int size, int &preOrderIndex,
int inOrderStart, int inOrderEnd){
    if(preOrderIndex >= size || inOrderStart > inOrderEnd){
        return NULL;
    }

    //1st case  main solve karunga
    int element = preorder[preOrderIndex];
    preOrderIndex++;

    //element search karna padega inorder me
    
    // int pos = searchEle(inorder, size, element);
    int pos = valueToIndexMap[element];

    Node *root = new Node(element);

    //baaki recursion sambhal lega
    root->left = constructTreeFromPreAndInOrderTraversal(valueToIndexMap, preorder, inorder, size, preOrderIndex, inOrderStart, pos-1);
    root->right = constructTreeFromPreAndInOrderTraversal(valueToIndexMap, preorder, inorder, size, preOrderIndex, pos+1, inOrderEnd);

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
    int inorder[] = {10, 8 , 6, 2, 4, 12};
    int preorder[] = {2, 8, 10, 6, 4, 12};
    int size = 6;
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = 5;

    map<int, int> valueToIndexMap;

    searchInorder(inorder, size, valueToIndexMap);

    Node *root = constructTreeFromPreAndInOrderTraversal(valueToIndexMap, preorder, inorder, size, preOrderIndex, inOrderStart, inOrderEnd);

    levelOrderTraversal(root);
    return 0;
}