#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorts.h"
using namespace std;

const int SIZE = 100;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    srand(time(0));

    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;  
    }

    cout << "Original Array:\n";
    printArray(arr, SIZE);
    cout << "=================================\n";

    // Shell Sort
    int shellArr[SIZE];
    copyArray(arr, shellArr, SIZE);
    shellSort(shellArr, SIZE);
    cout << "Array after Shell Sort:\n";
    printArray(shellArr, SIZE);
    cout << "=================================\n";

    // Merge Sort
    int mergeArr[SIZE];
    copyArray(arr, mergeArr, SIZE);
    mergeSort(mergeArr, 0, SIZE - 1);
    cout << "Array after Merge Sort:\n";
    printArray(mergeArr, SIZE);
    cout << "=================================\n";

    // Quick Sort
    int quickArr[SIZE];
    copyArray(arr, quickArr, SIZE);
    quickSort(quickArr, 0, SIZE - 1);
    cout << "Array after Quick Sort:\n";
    printArray(quickArr, SIZE);
    cout << "=================================\n";

    return 0;
}
