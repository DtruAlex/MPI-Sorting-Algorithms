#include <iostream>
#include "numberGenerator.h"
#include "sortingAlgorithms.h"
#include <fstream>
#include <chrono>
#include <algorithm>

void stdSortTest(int arr[], int len){
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    std::sort(arr,arr+len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
}

void insertionSortTest(int arr[], int len){
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    insertionSort(arr,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    for(int j=0;j<len-1;j++)
    {
        if(arr[j] > arr[j + 1])
        {
            printf("wroooong\n");

        }
    }
}


void selectionSortTest(int arr[], int len){
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    selectionSort(arr,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    for(int j=0;j<len-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            printf("wroooong\n");

        }
    }
}

void bubbleSortTest(int arr[], int len){
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    bubbleSort(arr,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    for(int j=0;j<len-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            printf("wroooong\n");

        }
    }
}

void heapSortTest(int arr[], int len){
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    heapSort(arr,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    for(int j=0;j<len-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            printf("wroooong\n");

        }
    }
}


void countSortTest(int arr[], int len){
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    countSort(arr,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    for(int j=0;j<len-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            printf("wroooong\n");

        }
    }
}

void radixSortTest(int arr[], int len){
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    radixSort(arr,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    for(int j=0;j<len-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            printf("wroooong\n");

        }
    }
}

void mergeSortTest(int arr[], int len){
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    mergeSort(arr,0,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    for(int j=0;j<len-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            printf("wroooong\n");

        }
    }
}

void quickSortTest(int arr[], int len){
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    quickSort(arr,0,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    for(int j=0;j<len-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            printf("wroooong\n");

        }
    }

}
int main(int argc, char **argv){
    int whatToDo,numberOfElements;
    std::cin>>whatToDo>>numberOfElements;

    if(whatToDo==1)
        generateListOfPositiveIntegers(0,10000,numberOfElements);

    else {
        std::ifstream finN("posNumberList.txt");
        std::ifstream finA("ascNumberList.txt");
        std::ifstream finD("descNumberList.txt");
        int x, i = 0;
        auto array = new int[numberOfElements];
        while (finN>> x)
            array[i++] = x;


        printf("PreSorted:");
        for(int j=0;j<numberOfElements;j++)
            printf(" %d",array[j]);
        printf("\n");
        stdSortTest(array,numberOfElements);

        printf("Sorted:");
        for(int j=0;j<numberOfElements;j++)
            printf(" %d",array[j]);
        printf("\n");
    }
    return 0;
}