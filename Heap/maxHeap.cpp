#include <iostream>
using namespace std;

class Heap {
    public:
    int arr[100];
    int size;
    Heap() {
        size = 0;
        arr[0] = -1;
    }

    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    void deleteFromHeap() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }

        // step 1: swap first and last element
        arr[1] = arr[size];

        // step 2: delete last element
        size--;

        // step 3: heapify
        int index = 1;
        while (index < size) {
            int leftIndex = index * 2;
            int rightIndex = index * 2 + 1;

            if (leftIndex < size && arr[leftIndex] > arr[index]) {
                swap(arr[leftIndex], arr[index]);
                index = leftIndex;
            } else if (rightIndex < size && arr[rightIndex] > arr[index]) {
                swap(arr[rightIndex], arr[index]);
                index = rightIndex;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int* &arr, int size, int index) {
    int largest = index;
    int leftIndex = index * 2;
    int rightIndex = index * 2 + 1;

    // if left child is greater than parent then largest = left child
    if (leftIndex < size && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
    } else if (rightIndex < size && arr[largest] < arr[rightIndex]) { // if right child is greater than parent then largest = right child
        largest = rightIndex;
    } else { // if parent is greater than both children then return
        return;
    }

    // swap parent with largest child
    if (largest != index) {
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest); // recursively heapify the subtree with largest child as parent
    }
}

int main() {
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);


    h.print();

    h.deleteFromHeap();

    h.print();

    return 0;
}