#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    cout << "Enter value for Node : " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // step:1 create Node
    Node *root = new Node(data);

    // create left sub-tree
    root->left = createTree();

    // create right sub-tree
    root->right = createTree();

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

int main()
{

    Node *root = createTree();
    cout << "Lever Order : ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}

// 10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1

//10 20 40 -1 -1 50 90 -1 -1 100 -1 -1 30 60 -1 -1 70 -1 -1