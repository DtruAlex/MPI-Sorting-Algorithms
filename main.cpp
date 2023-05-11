#include <iostream>
#include "numberGenerator.h"
#include "sortingAlgorithms.h"
#include <fstream>
#include <chrono>
#include <algorithm>
#include <cstring>

void stdSortTest(int arr[], int len){
    printf("stdSort - %d elements\n",len);
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    std::sort(arr,arr+len);
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
            return;
        }
    }
}

void insertionSortTest(int arr[], int len){
    printf("insertionSort - %d elements\n",len);
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
            return;
        }
    }
}


void selectionSortTest(int arr[], int len){
    printf("selectionSort - %d elements\n",len);
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
            return;
        }
    }
}

void bubbleSortTest(int arr[], int len){
    printf("bubbleSort - %d elements\n",len);
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
            return;

        }
    }
}

void heapSortTest(int arr[], int len){
    printf("heapSort - %d elements\n",len);
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
            return;
        }
    }
}


void countSortTest(int arr[], int len){
    printf("countingSort - %d elements\n",len);
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
            return;
        }
    }
}

void radixSortTest(int arr[], int len){
    printf("radixSort - %d elements\n",len);
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
            return;
        }
    }
}

void mergeSortTest(int arr[], int len){
    printf("mergeSort - %d elements\n",len);
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
            return;
        }
    }
}

void quickSortTest(int arr[], int len){
    printf("quickSort - %d elements\n",len);
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
            return;
        }
    }

}
int main(int argc, char **argv){
    int whatToDo,numberOfElements;
    std::cin>>whatToDo>>numberOfElements;

    if(whatToDo==1)
        generateListOfPositiveIntegers(0,1000000,numberOfElements);

    else {
        std::ifstream finN("posNumberList.txt");
        std::ifstream finA("ascNumberList.txt");
        std::ifstream finD("descNumberList.txt");
        int x, i = 0;
        auto array = new int[numberOfElements];
        while (finN>> x)
            array[i++] = x;
        printf("readEverything\n");
        int*arrayB= new int[numberOfElements];
        memcpy(arrayB,array,sizeof(int)*(numberOfElements-1));
        stdSortTest(arrayB,numberOfElements);
        printf("post sort %d \n",arrayB[0]);
        printf("------------------------------------\n");
        memcpy(arrayB,array,sizeof(int)*numberOfElements);
        printf("pre sort %d \n",arrayB[0]);
        insertionSortTest(arrayB,numberOfElements);
        printf("post sort %d \n",arrayB[0]);
        printf("------------------------------------\n");
        memcpy(arrayB,array,sizeof(int)*numberOfElements);
        printf("pre sort %d \n",arrayB[0]);
        selectionSortTest(arrayB,numberOfElements);
        printf("post sort %d \n",arrayB[0]);
        printf("------------------------------------\n");
        memcpy(arrayB,array,sizeof(int)*numberOfElements);
        printf("pre sort %d \n",arrayB[0]);
        bubbleSortTest(arrayB,numberOfElements);
        printf("post sort %d \n",arrayB[0]);
        printf("------------------------------------\n");
        memcpy(arrayB,array,sizeof(int)*numberOfElements);
        printf("pre sort %d \n",arrayB[0]);
        heapSortTest(arrayB,numberOfElements);
        printf("post sort %d \n",arrayB[0]);
        printf("------------------------------------\n");
        memcpy(arrayB,array,sizeof(int)*numberOfElements);
        printf("pre sort %d \n",arrayB[0]);
        countSortTest(arrayB,numberOfElements);
        printf("post sort %d \n",arrayB[0]);
        printf("------------------------------------\n");
        memcpy(arrayB,array,sizeof(int)*numberOfElements);
        printf("pre sort %d \n",arrayB[0]);
        radixSortTest(arrayB,numberOfElements);
        printf("post sort %d \n",arrayB[0]);
        printf("------------------------------------\n");
        memcpy(arrayB,array,sizeof(int)*numberOfElements);
        printf("pre sort %d \n",arrayB[0]);
        mergeSortTest(arrayB,numberOfElements);
        printf("post sort %d \n",arrayB[0]);
        printf("------------------------------------\n");
        memcpy(arrayB,array,sizeof(int)*numberOfElements);
        printf("pre sort %d \n",arrayB[0]);
        quickSortTest(arrayB,numberOfElements);
        printf("post sort %d \n",arrayB[0]);


    }
    return 0;
}