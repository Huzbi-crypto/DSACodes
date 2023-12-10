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

void heapify(int arr[], int size, int index) {
    int largest = index;
    int leftIndex = index * 2;
    int rightIndex = index * 2 + 1;

    // if left child is greater than parent then largest = left child
    if (leftIndex <= size && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
    } else if (rightIndex <= size && arr[largest] < arr[rightIndex]) { // if right child is greater than parent then largest = right child
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

void heapSort(int arr[], int size) {
    int s = size;
    while (s > 1) {
        swap(arr[1], arr[s]);
        s--;
        heapify(arr, s, 1);
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

    // code for heapifying an array
    int arr[] = {-1, 50, 55, 53, 52, 54};
    int size = 5;
    for (int i = size / 2; i >= 1; i--) {
        heapify(arr, size, i);
    }
    cout << "Heapified array: ";
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }

    // code for heap sort
    int arr2[] = {-1, 54, 53, 55, 52, 50};
    int size2 = 5;
    for (int i = size2 / 2; i >= 1; i--) {
        heapify(arr2, size2, i);
    }
    cout << endl << "Heapified array: ";
    for (int i = 1; i <= size2; i++) {
        cout << arr2[i] << " ";
    }
    heapSort(arr2, size2);
    cout << endl << "Sorted array: ";
    for (int i = 1; i <= size2; i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}