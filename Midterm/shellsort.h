#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <iostream>
#include <iomanip> // for table formatting
using namespace std;

// Function to perform Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Function to display array in a simple table
void displayArray(int arr[], int n) {
    cout << "Index | Value\n";
    cout << "----------------\n";
    for (int i = 0; i < n; i++) {
        cout << setw(5) << i << " | " << setw(5) << arr[i] << endl;
    }
    cout << endl;
}

#endif
