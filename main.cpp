#include <iostream>
#include "numberGenerator.h"
#include "sortingAlgorithms.h"
#include <fstream>
#include <chrono>
#include <algorithm>
#include <cstring>
#include <csignal>

void removeFiles(){
    remove("stdTimes.txt");
    remove("insertionTimes.txt");
    remove("selectionTimes.txt");
    remove("bubbleTimes.txt");
    remove("heapTimes.txt");
    remove("countingTimes.txt");
    remove("radixTimes.txt");
    remove("mergeTimes.txt");
    remove("quickTimes.txt");
}

void stdCompileTimes(int numberOfRepetitions){
    double sx=0,sy=0;
    double x,y;
    std::ifstream stdTimes;
    stdTimes.open("stdTimes.txt");
    FILE *times = fopen("finalTimes.txt","a");
    while(stdTimes>>x>>y){
    printf("s %2.8f %2.8f\n",x,y);
    sx+=x;sy+=y;}
    stdTimes.close();
    fprintf(times,"stdSort %2.8f %2.8f\n",sx/numberOfRepetitions,sy/numberOfRepetitions);
    fclose(times);
}

void insertionCompileTimes(int numberOfRepetitions){
    double sx=0,sy=0;
    double x,y;
    std::ifstream insertionTimes;
    insertionTimes.open("insertionTimes.txt");
    FILE *times = fopen("finalTimes.txt","a");
    while(insertionTimes>>x>>y){
    printf("s %2.8f %2.8f\n",x,y);
    sx+=x;sy+=y;}
    insertionTimes.close();
    fprintf(times,"insertionSort %2.8f %2.8f\n",sx/numberOfRepetitions,sy/numberOfRepetitions);
    fclose(times);
}

void selectionCompileTimes(int numberOfRepetitions){
    double sx=0,sy=0;
    double x,y;
    std::ifstream selectionTimes;
    selectionTimes.open("selectionTimes.txt");
    FILE *times = fopen("finalTimes.txt","a");
    while(selectionTimes>>x>>y){
    printf("s %2.8f %2.8f\n",x,y);
    sx+=x;sy+=y;}
    selectionTimes.close();
    fprintf(times,"selectionSort %2.8f %2.8f\n",sx/numberOfRepetitions,sy/numberOfRepetitions);
    fclose(times);
}

void bubbleCompileTimes(int numberOfRepetitions){
    double sx=0,sy=0;
    double x,y;
    std::ifstream bubbleTimes;
    bubbleTimes.open("bubbleTimes.txt");
    FILE *times = fopen("finalTimes.txt","a");
    while(bubbleTimes>>x>>y){
    printf("s %2.8f %2.8f\n",x,y);
    sx+=x;sy+=y;}
    bubbleTimes.close();
    fprintf(times,"bubbleSort %2.8f %2.8f\n",sx/numberOfRepetitions,sy/numberOfRepetitions);
    fclose(times);
}

void heapCompileTimes(int numberOfRepetitions){
    double sx=0,sy=0;
    double x,y;
    std::ifstream heapTimes;
    heapTimes.open("heapTimes.txt");
    FILE *times = fopen("finalTimes.txt","a");
    while(heapTimes>>x>>y){
    printf("s %2.8f %2.8f\n",x,y);
    sx+=x;sy+=y;}
    heapTimes.close();
    fprintf(times,"heapSort %2.8f %2.8f\n",sx/numberOfRepetitions,sy/numberOfRepetitions);
    fclose(times);
}

void countingCompileTimes(int numberOfRepetitions){
    double sx=0,sy=0;
    double x,y;
    std::ifstream countingTimes;
    countingTimes.open("countingTimes.txt");
    FILE *times = fopen("finalTimes.txt","a");
    while(countingTimes>>x>>y){
    printf("s %2.8f %2.8f\n",x,y);
    sx+=x;sy+=y;}
    countingTimes.close();
    fprintf(times,"countingSort %2.8f %2.8f\n",sx/numberOfRepetitions,sy/numberOfRepetitions);
    fclose(times);
}

void radixCompileTimes(int numberOfRepetitions){
    double sx=0,sy=0;
    double x,y;
    std::ifstream radixTimes;
    radixTimes.open("radixTimes.txt");
    FILE *times = fopen("finalTimes.txt","a");
    while(radixTimes>>x>>y){
    printf("s %2.8f %2.8f\n",x,y);
    sx+=x;sy+=y;}
    radixTimes.close();
    fprintf(times,"radixSort %2.8f %2.8f\n",sx/numberOfRepetitions,sy/numberOfRepetitions);
    fclose(times);
}

void mergeCompileTimes(int numberOfRepetitions){
    double sx=0,sy=0;
    double x,y;
    std::ifstream mergeTimes;
    mergeTimes.open("mergeTimes.txt");
    FILE *times = fopen("finalTimes.txt","a");
    while(mergeTimes>>x>>y){
    printf("s %2.8f %2.8f\n",x,y);
    sx+=x;sy+=y;}
    mergeTimes.close();
    fprintf(times,"mergeSort %2.8f %2.8f\n",sx/numberOfRepetitions,sy/numberOfRepetitions);
    fclose(times);
}

void quickCompileTimes(int numberOfRepetitions){
    double sx=0,sy=0;
    double x,y;
    std::ifstream quickTimes;
    quickTimes.open("quickTimes.txt");
    FILE *times = fopen("finalTimes.txt","a");
    while(quickTimes>>x>>y){
    printf("s %2.8f %2.8f\n",x,y);
    sx+=x;sy+=y;}
    quickTimes.close();
    fprintf(times,"quickSort %2.8f %2.8f\n",sx/numberOfRepetitions,sy/numberOfRepetitions);
    fclose(times);
}

void compileTimes(int numberOfRepetitions){
    stdCompileTimes(numberOfRepetitions);
//    insertionCompileTimes(numberOfRepetitions);
//    selectionCompileTimes(numberOfRepetitions);
//    bubbleCompileTimes(numberOfRepetitions);
    heapCompileTimes(numberOfRepetitions);
    countingCompileTimes(numberOfRepetitions);
    radixCompileTimes(numberOfRepetitions);
    mergeCompileTimes(numberOfRepetitions);
    quickCompileTimes(numberOfRepetitions);
}

void stdSortTest(int arr[], int len){
    printf("stdSort - %d elements\n",len);
    FILE *file = fopen("stdTimes.txt","a");
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    std::sort(arr,arr+len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    fprintf(file,"%2.8f %2.8f \n",elapsed,fp_ms.count());
    fclose(file);
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
    FILE *file = fopen("insertionTimes.txt","a");
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    insertionSort(arr,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    fprintf(file,"%2.8f %2.8f \n",elapsed,fp_ms.count());
    fclose(file);
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
    FILE *file = fopen("selectionTimes.txt","a");
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    selectionSort(arr,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    fprintf(file,"%2.8f %2.8f \n",elapsed,fp_ms.count());
    fclose(file);
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
    FILE *file = fopen("bubbleTimes.txt","a");
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    bubbleSort(arr,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    fprintf(file,"%2.8f %2.8f \n",elapsed,fp_ms.count());
    fclose(file);
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
    FILE *file = fopen("heapTimes.txt","a");
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    heapSort(arr,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    fprintf(file,"%2.8f %2.8f \n",elapsed,fp_ms.count());
    fclose(file);
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
    FILE *file = fopen("countingTimes.txt","a");
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    countSort(arr,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    fprintf(file,"%2.8f %2.8f \n",elapsed,fp_ms.count());
    fclose(file);
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
    FILE *file = fopen("radixTimes.txt","a");
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    radixSort(arr,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    fprintf(file,"%2.8f %2.8f \n",elapsed,fp_ms.count());
    fclose(file);
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
    FILE *file = fopen("mergeTimes.txt","a");
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    mergeSort(arr,0,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    fprintf(file,"%2.8f %2.8f \n",elapsed,fp_ms.count());
    fclose(file);
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
    FILE *file = fopen("quickTimes.txt","a");
    auto t1 = std::chrono::high_resolution_clock::now();
    clock_t start = clock();
    quickSort(arr,0,len);
    clock_t stop = clock();
    auto t2 = std::chrono::high_resolution_clock::now(); //real time
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC; //cpu time
    std::chrono::duration<double> fp_ms = t2 - t1;
    printf("%2.8f -cpu time\n",elapsed);printf("%2.8f -real time \n",fp_ms.count());
    fprintf(file,"%2.8f %2.8f \n",elapsed,fp_ms.count());
    fclose(file);
    for(int j=0;j<len-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            printf("wroooong\n");
            return;
        }
    }

}


void testAscendingListOfNumbers(int numberOfElements){
    remove("ascNumberList.txt");
    generateListOfConsecutiveAscendingPositiveIntegers(0,10,numberOfElements,0);
    std::ifstream fin("ascNumberList.txt");
    int x, i = 0;
    auto array = new int[numberOfElements];
    while (fin>> x)
        array[i++] = x;
    printf("ASCENDING\n");
    int*arrayB= new int[numberOfElements];
    memcpy(arrayB,array,sizeof(int)*(numberOfElements-1));
    stdSortTest(arrayB,numberOfElements);
//    printf("------------------------------------\n");
//    memcpy(arrayB,array,sizeof(int)*numberOfElements);
//    insertionSortTest(arrayB,numberOfElements);
//    printf("------------------------------------\n");
//    memcpy(arrayB,array,sizeof(int)*numberOfElements);
//    selectionSortTest(arrayB,numberOfElements);
//    printf("------------------------------------\n");
//    memcpy(arrayB,array,sizeof(int)*numberOfElements);
//    bubbleSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    heapSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    countSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    radixSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    mergeSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    quickSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
}

void testDescendingListOfNumbers(int numberOfElements){
    remove("descNumberList.txt");
    generateListOfConsecutiveDescendingPositiveIntegers(0,10,numberOfElements,100000);
    std::ifstream fin("descNumberList.txt");
    int x, i = 0;
    auto array = new int[numberOfElements];
    while (fin>> x)
        array[i++] = x;
    printf("DESCENDING\n");
    int*arrayB= new int[numberOfElements];
    memcpy(arrayB,array,sizeof(int)*(numberOfElements-1));
    stdSortTest(arrayB,numberOfElements);
//    printf("------------------------------------\n");
//    memcpy(arrayB,array,sizeof(int)*numberOfElements);
//    insertionSortTest(arrayB,numberOfElements);
//    printf("------------------------------------\n");
//    memcpy(arrayB,array,sizeof(int)*numberOfElements);
//    selectionSortTest(arrayB,numberOfElements);
//    printf("------------------------------------\n");
//    memcpy(arrayB,array,sizeof(int)*numberOfElements);
//    bubbleSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    heapSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    countSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    radixSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    mergeSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    quickSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
}

void testRandomListOfNumbers(int numberOfElements){
    remove("posNumberList.txt");
    generateListOfPositiveIntegers(0,100000,numberOfElements);
    std::ifstream fin("posNumberList.txt");
    int x, i = 0;
    auto array = new int[numberOfElements];
    while (fin>> x)
        array[i++] = x;

    int*arrayB= new int[numberOfElements];
    printf("RANDOM\n");
    memcpy(arrayB,array,sizeof(int)*(numberOfElements-1));
    stdSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
   // memcpy(arrayB,array,sizeof(int)*numberOfElements);
   // insertionSortTest(arrayB,numberOfElements);
   // printf("------------------------------------\n");
//    memcpy(arrayB,array,sizeof(int)*numberOfElements);
//    selectionSortTest(arrayB,numberOfElements);
//    printf("------------------------------------\n");
//    memcpy(arrayB,array,sizeof(int)*numberOfElements);
//    bubbleSortTest(arrayB,numberOfElements);
//    printf("------------------------------------\n");
//    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    heapSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    countSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    radixSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    mergeSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    quickSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");

}

int main(int argc, char* argv[]){
    int rep,//= atoi(argv[1]),
        type,//= atoi(argv[2]),
        elem,//= atoi(argv[3]),
        i=1;
    std::cin>>rep>>type>>elem;

        while (i <= rep) {
            switch (type) {
                case 1: {
                    testAscendingListOfNumbers(elem);
                    break;
                }
                case 2: {
                    testDescendingListOfNumbers(elem);
                    break;
                }
                case 3: {
                    testRandomListOfNumbers(elem);
                    break;
                }
                default:
                    removeFiles();
            }
            i++;
        }
        FILE *times = fopen("finalTimes.txt", "a");
        switch (type) {
            case 1: {
                fprintf(times, "TestType: %s  Number of elements:%d  Number of Runs:%d \n", "List of Ascending Numbers",
                        elem, rep);
                fclose(times);
                compileTimes(rep);
                break;
            }
            case 2: {
                fprintf(times, "TestType: %s  Number of elements:%d  Number of Runs:%d \n",
                        "List of Descending Numbers",
                        elem, rep);
                fclose(times);
                compileTimes(rep);
                break;
            }
            case 3: {
                fprintf(times, "TestType: %s  Number of elements:%d  Number of Runs:%d \n", "List Random Numbers",
                        elem, rep);
                fclose(times);
                compileTimes(rep);
                break;}
            default:    {
                fprintf(times,"DELETED FILES - PLS IGNORE\n");
                fclose(times);
                break;
            }
        }
    usleep(1*1000*1000);
    return 0;
}