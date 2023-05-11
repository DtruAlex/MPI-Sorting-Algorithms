//
// Created by dumi on 09.05.2023.
//

#ifndef MPI_SORTING_SORTINGALGORITHMS_H
#define MPI_SORTING_SORTINGALGORITHMS_H

void insertionSort(int *A, int len);
void selectionSort(int *A,int n);
void bubbleSort(int *A, int size);
void heapSort(int *A, int size);
void countSort(int *A, int size);
void radixSort(int *A, int size);
void mergeSort(int *A, int begin, int end);
void quickSort(int *A, int begin, int end);

#endif //MPI_SORTING_SORTINGALGORITHMS_H
