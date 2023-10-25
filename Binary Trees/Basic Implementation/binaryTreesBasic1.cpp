#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int val;
        Node *left;
        Node *right;

        Node(int value) {
            this->val = value;
            left = nullptr;
            right = nullptr;
        }
};

Node *buildBinaryTree(Node *root) {
    cout << "Enter value for node: ";
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) {
        return nullptr;
    }

    cout << "Enter the data for left node: " << data << endl;
    root->left =  buildBinaryTree(root->left);
    cout << "Enter the data for right node: " << data << endl;
    root->right = buildBinaryTree(root->right);
    return root;
}

void levelOrderTraversal(Node *&root) {
    queue<Node*> qu;
    qu.push(root);
    qu.push(NULL);

    while (!qu.empty()) {
        Node *temp = qu.front();
        qu.pop();
        if (temp == NULL) {
            cout << endl;
            if (!qu.empty())
                qu.push(NULL);
        } else {
            cout << temp->val << " ";
            if (temp->left) qu.push(temp->left);
            if (temp->right) qu.push(temp->right);
        }
    }
}

int main() {
    Node *root;

    // values: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildBinaryTree(root);

    levelOrderTraversal(root);

    return 0;
}

