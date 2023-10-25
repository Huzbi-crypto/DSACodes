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

int main() {
    Node *root;

    root = buildBinaryTree(root);

    return 0;
}

