#include <iostream>
#include "numberGenerator.h"
#include "sortingAlgorithms.h"
#include <fstream>
#include <chrono>
#include <algorithm>
#include <cstring>

class finalTime{
public:
    double cpuTime,realTime;
    finalTime();
};
finalTime::finalTime() {
    this->cpuTime=0;
    this->realTime=0;
}

//UTILITIES
finalTime getFinalTimesFromFile(std::ifstream& file,int numberOfRepetitions){
    finalTime times;
    double x,y;
    printf("1shit %2.8f %2.8f \n",times.cpuTime,times.realTime);
    while(file>>x>>y)
    {
        printf("x:%f y:%f\n",x,y);
        times.cpuTime+=x;
        times.realTime+=y;
    }
    printf("2shit %2.8f %2.8f \n",times.cpuTime,times.realTime);
    times.cpuTime/=(double)numberOfRepetitions;
    times.realTime/=(double)numberOfRepetitions;
    printf("3shit %2.8f %2.8f \n\n",times.cpuTime,times.realTime);
    return times;

}

void writeToFile(const char *filename, double cpuTime, std::chrono::duration<double> realTime)
{
    FILE* fp = fopen(filename, "a");
    double x=cpuTime,y=realTime.count();
    printf("writeToFile %2.8f %2.8f \n",x,y);
    fprintf(fp,"%2.8f %2.8f\n",cpuTime,realTime.count());
}

void compileTimes(int numberOfElements,int numberOfRepetitions) {
//    std::ofstream pstdTime("stdTimes.txt");
//    std::ofstream pinsertion("insertionTimes.txt");
//    std::ofstream pselection("selectionTimes.txt");
//    std::ofstream pbubble("bubbleTimes.txt");
//    std::ofstream pheap("heapTimes.txt");
//    std::ofstream pcount("countTimes.txt");
//    std::ofstream pradix("radixTimes.txt");
//    std::ofstream pmerge("mergeTimes.txt");
//    std::ofstream pquick("quickTimes.txt");
//    pstdTime<<"\n";pinsertion<<"\n";pselection<<"\n";pbubble<<"\n";pheap<<"\n";pcount<<"\n";pradix<<"\n";pmerge<<"\n";pquick<<"\n";
//    pstdTime.close();pinsertion.close();pselection.close();pbubble.close();pheap.close();pcount.close();pradix.close();pmerge.close();pquick.close();
    finalTime finalTimes= *new finalTime;
    FILE* times = fopen("finalTimes.txt", "a+");
    std::ifstream std;std.open("stdTimes.txt");
    std::ifstream insertion;insertion.open("insertionTimes.txt");
    std::ifstream selection;selection.open("selectionTimes.txt");
    std::ifstream bubble;bubble.open("bubbleTimes.txt");
    std::ifstream heap;heap.open("heapTimes.txt");
    std::ifstream count;count.open("countTimes.txt");
    std::ifstream radix;radix.open("radixTimes.txt");
    std::ifstream merge;merge.open("mergeTimes.txt");
    std::ifstream quick;quick.open("quickTimes.txt");
    fprintf(times,"%d %d\n",numberOfElements,numberOfRepetitions);
    double x,y;
    std>>x>>y;
    printf("x:%f y:%f\n",x,y);
    finalTimes=getFinalTimesFromFile(std,numberOfRepetitions);
    fprintf(times,"StdSort %2.8f %2.8f \n",finalTimes.realTime,finalTimes.cpuTime);

    finalTimes=getFinalTimesFromFile(insertion,numberOfRepetitions);
    fprintf(times,"InsertionSort %2.8f %2.8f \n",finalTimes.realTime,finalTimes.cpuTime);
    //std::remove("insertionTimes.txt");

    finalTimes=getFinalTimesFromFile(selection,numberOfRepetitions);
    fprintf(times,"SelectionSort %2.8f %2.8f \n",finalTimes.realTime,finalTimes.cpuTime);
    //std::remove("selectionTimes.txt");

    finalTimes=getFinalTimesFromFile(bubble,numberOfRepetitions);
    fprintf(times,"BubbleSort %2.8f %2.8f \n",finalTimes.realTime,finalTimes.cpuTime);
    //std::remove("bubbleTimes.txt");

    finalTimes=getFinalTimesFromFile(heap,numberOfRepetitions);
    fprintf(times,"heapSort %2.8f %2.8f \n",finalTimes.realTime,finalTimes.cpuTime);
    //std::remove("heapTimes.txt");

    finalTimes=getFinalTimesFromFile(count,numberOfRepetitions);
    fprintf(times,"countSort %2.8f %2.8f \n",finalTimes.realTime,finalTimes.cpuTime);
    //std::remove("countTimes.txt");

    finalTimes=getFinalTimesFromFile(radix,numberOfRepetitions);
    fprintf(times,"radixSort %2.8f %2.8f \n",finalTimes.realTime,finalTimes.cpuTime);
    //std::remove("radixTimes.txt");

    finalTimes=getFinalTimesFromFile(merge,numberOfRepetitions);
    fprintf(times,"mergeSort %2.8f %2.8f \n",finalTimes.realTime,finalTimes.cpuTime);
    //std::remove("mergeTimes.txt");

    finalTimes=getFinalTimesFromFile(quick,numberOfRepetitions);
    fprintf(times,"quickSort %2.8f %2.8f \n",finalTimes.realTime,finalTimes.cpuTime);
    //std::remove("quickTimes.txt");
}
//SORTING TESTS
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
    writeToFile("stdTimes.txt",elapsed,fp_ms);
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
    writeToFile("insertionTimes.txt",elapsed,fp_ms);
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
    writeToFile("selectionTimes.txt",elapsed,fp_ms);
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
    writeToFile("bubbleTimes.txt",elapsed,fp_ms);
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
    writeToFile("heapTimes.txt",elapsed,fp_ms);
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
    writeToFile("countTimes.txt",elapsed,fp_ms);
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
    writeToFile("radixTimes.txt",elapsed,fp_ms);
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
    writeToFile("mergeTimes.txt",elapsed,fp_ms);
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
    writeToFile("quickTimes.txt",elapsed,fp_ms);

}

//LIST GENERATION
void testAscendingListOfNumbers(int numberOfElements){
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
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    insertionSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    selectionSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    bubbleSortTest(arrayB,numberOfElements);
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
    generateListOfConsecutiveDescendingPositiveIntegers(0,10,numberOfElements,1000000);
    std::ifstream fin("descNumberList.txt");
    int x, i = 0;
    auto array = new int[numberOfElements];
    while (fin>> x)
        array[i++] = x;
    printf("DESCENDING\n");
    int*arrayB= new int[numberOfElements];
    memcpy(arrayB,array,sizeof(int)*(numberOfElements-1));
    stdSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    insertionSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    selectionSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    bubbleSortTest(arrayB,numberOfElements);
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
    generateListOfPositiveIntegers(0,1000000,numberOfElements);
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
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    insertionSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    selectionSortTest(arrayB,numberOfElements);
    printf("------------------------------------\n");
    memcpy(arrayB,array,sizeof(int)*numberOfElements);
    bubbleSortTest(arrayB,numberOfElements);
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

int main(){
    int numberOfRepetitions,numberOfElements;
    std::cin>>numberOfRepetitions>>numberOfElements;
    for(int i=0;i<numberOfRepetitions;i++) {
        testAscendingListOfNumbers(numberOfElements);
        compileTimes(numberOfElements,numberOfRepetitions);
        testDescendingListOfNumbers(numberOfElements);
        compileTimes(numberOfElements,numberOfRepetitions);
        testRandomListOfNumbers(numberOfElements);
        compileTimes(numberOfElements,numberOfRepetitions);
    }

}