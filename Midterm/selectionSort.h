#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
using namespace std;

// Routine to find the smallest element position
template <typename T>
int Routine_Smallest(T A[], int K, const int arrSize) {
    int position = K;
    T smallestElem = A[K];

    for(int J = K + 1; J < arrSize; J++) {
        if(A[J] < smallestElem) {
            smallestElem = A[J];
            position = J;
        }
    }
    return position;
}

// Selection Sort
template <typename T>
void selectionSort(T arr[], const int N) {
    int POS, pass = 0;

    for(int i = 0; i < N; i++) {
        POS = Routine_Smallest(arr, i, N);

        // Swap arr[i] and arr[POS]
        T temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;

        pass++;
    }
}

#endif
