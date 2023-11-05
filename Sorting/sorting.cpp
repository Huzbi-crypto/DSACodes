#include <iostream>
using namespace std;

// merge sort
int *mergeSort(int low, int high, int *arr) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(low, mid, arr);
        mergeSort(mid + 1, high, arr);
        int subPointer1 = low, subPointer2 = mid + 1, pointer = 0;
        int *temp = new int[high - low + 1];
        while (subPointer1 <= mid && subPointer2 <= high) {
            if (arr[subPointer1] < arr[subPointer2]) {
                temp[pointer] = arr[subPointer1];
                subPointer1++;
            } else {
                temp[pointer] = arr[subPointer2];
                subPointer2++;
            }
            pointer++;
        }
        while (subPointer1 <= mid) {
            temp[pointer] = arr[subPointer1];
            subPointer1++;
            pointer++;
        }
        while (subPointer2 <= high) {
            temp[pointer] = arr[subPointer2];
            subPointer2++;
            pointer++;
        }
        return temp;    
    }
}

// quick sort
int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j) {
        do {
            i++;
        } while (arr[i] >= pivot || arr[i] == pivot);
        do {
            j--;
        } while (arr[j] < pivot || arr[j] == pivot);
        if (i < j) {
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot);
        quickSort(arr, pivot + 1, high);
    }
}

// 3-way quick sort
void partition(int *arr, int low, int high, int &i, int &j) {
    int pivot = arr[low];
    int left = low;
    int right = high;
    i = low;
    while (i <= right) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[left]);
            left++;
            i++;
        } else if (arr[i] > pivot) {
            swap(arr[i], arr[right]);
            right--;
            i++;
        } else {
            i++;
        }
    }
    j = left - 1;
}
void quickSort3Way(int *arr, int low, int high) {
    if (low < high) {
        int i, j;
        partition(arr, low, high, i, j);
        quickSort3Way(arr, low, j);
        quickSort3Way(arr, i, high);
    }
}