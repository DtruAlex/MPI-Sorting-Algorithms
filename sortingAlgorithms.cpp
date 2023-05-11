//
// Created by dumi on 09.05.2023.
//

#include <cstdio>
#include "sortingAlgorithms.h"

//utility functions
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int getMaximumOfArray(const int *A, int size)
{
    int mx = A[0];
    for (int i = 1; i < size; i++)
        if (A[i] > mx)
            mx = A[i];
    return mx;
}

/*INSERTION SORT*/
void insertionSort(int *A, int size)
{
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

//SELECTION SORT
void selectionSort(int *A, int size)
{
    int i, j, min_idx;
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++)
        {
            if (A[j] < A[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element
        // with the first element
        if (min_idx!=i)
            swap(&A[min_idx], &A[i]);
    }
}

//BUBBLE SORT
void bubbleSort(int A[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(A+j, A+(j + 1));
}

//HEAP SORT
void heapify(int *A, int size, int i)
{

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && A[l] > A[largest])
        largest = l;
    if (r < size && A[r] > A[largest])
        largest = r;
    if (largest != i) {
        swap(A+i, A+largest);
        heapify(A, size, largest);
    }
}
void heapSort(int *A, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(A, size, i);

    for (int i = size- 1; i > 0; i--) {
        swap(A, A+i);
        heapify(A, i, 0);
    }
}

//COUNTING SORT
void countSort(int *A, int size){
    int output[size+1];
    int max = getMaximumOfArray(A, size);
    int count[max+1]; //create count array with size [max+1]


    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0; // Initialize count array with all zeros
    }

    for (int i = 0; i < size; i++) // Store the count of each element
    {
        count[A[i]]++;
    }

    for(int i = 1; i<=max; i++)
        count[i] += count[i-1]; //find cumulative frequency

    /* This loop will find the index of each element of the original array in count array, and
     place the elements in output array*/
    for (int i = size - 1; i >= 0; i--) {
        output[count[A[i]] - 1] = A[i];
        count[A[i]]--; // decrease count for same numbers
    }

    for(int i = 0; i<size; i++) {
        A[i] = output[i]; //store the sorted elements into main array
    }
}

//RADIX SORT
void radixCountSort(int *A, int size , int exp)
{
    int output[size]; // output array
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < size; i++)
        count[(A[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = size - 1; i >= 0; i--) {
        output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10]--;
    }

    // Copy the output array to *A, so that *A now
    // contains sorted numbers according to current digit
    for (i = 0; i < size; i++)
        A[i] = output[i];
}
void radixSort(int *A, int size)
{
    // Find the maximum number to know number of digits
    int m = getMaximumOfArray(A, size);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        radixCountSort(A, size, exp);
}


//MERGE SORT
void merge(int *A, int left, int mid, int right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
            *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = A[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = A[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
            indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            A[indexOfMergedArray]
                    = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            A[indexOfMergedArray]
                    = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        A[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        A[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int *A, int begin, int end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(A, begin, mid);
    mergeSort(A, mid + 1, end);
    merge(A, begin, mid, end);
}

//QUICK SORT
int partition(int *A, int p, int r)
{
    int i = p - 1;
    int x = A[r];
    for(int j = p; j < r; j++)
    {
        if(A[j] <= x)
        {
            i++;
            swap(A+i, A+j);
        }
    }

    swap(A+(i+1), A+r);

    return i+1;
}
void quickSort(int *A, int begin, int end)
{
    if(begin < end)
    {
        int q = partition(A, begin, end);
        quickSort(A, begin, q-1);
        quickSort(A, q+1, end);
    }
}