#include <iostream>
using namespace std;

class Node {
    public:
    int val;
    Node *right;
    Node *left;
    
    Node(int v) {
        val = v;
        right = nullptr;
        left = nullptr;
    }
};

class CompleteBinaryTree {
    public:
    Node *root;

    CompleteBinaryTree() {
        root = nullptr;
    }

    Node * insert(int arr[], Node *root, int i, int n) {
        if (i < n) {
            if (root == nullptr) {
                root = new Node(arr[i]);
            }
            root->left = insert(arr, root->left, 2*i+1, n);
            root->right = insert(arr, root->right, 2*i+2, n);
        }
        return root;
    }
};