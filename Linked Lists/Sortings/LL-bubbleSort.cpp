#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void traverseList(Node *head) {
    Node *current = head;
    
    while(current != NULL) {
        cout << current->data << endl;
        current = current->next;
    }
}

Node *createNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

void swap(Node *node, Node *headNext) {
    int temp = node->data;
    node->data = headNext->data;
    headNext->data = temp;
}

void bubbleSort(Node *head) {
    Node *current;
    Node *end = NULL;
    bool swapped;
    
    do {
        swapped = false;
        current = head;
        
        while(current->next != end) {
            if(current->data > current->next->data) {
                swap(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
        end = current;
    }
    while(swapped);
}

int main() {
    Node *head = createNode(3);
    head->next = createNode(2);
    head->next->next = createNode(1);
    
    cout << "Before Sorting\n";
    traverseList(head);
    
    cout << "After Sorting\n";
    bubbleSort(head);
    traverseList(head);
    
    return 0;
}
