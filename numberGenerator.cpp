//
// Created by dumi on 08.05.2023.
//

#include "numberGenerator.h"
#include <random>
#include <fstream>


void generateListOfPositiveIntegers(int minInteger,int maxInteger,int numberOfElements){
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice()); // seed the generator
    std::uniform_int_distribution<> distribution(minInteger,maxInteger);
    std::ofstream fout("posNumberList.txt");
    for(int i=1;i<=numberOfElements;i++) {
        fout << distribution(generator) << ' ';
        if (i % 20 == 0)
            fout << "\n";
    }
}

void generateListOfConsecutiveAscendingPositiveIntegers( int minDistanceBetweenIntegers,int maxDistanceBetweenIntegers,int numberOfElements, int minInteger){
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice()); // seed the generator
    std::uniform_int_distribution<> distribution(minDistanceBetweenIntegers,maxDistanceBetweenIntegers);
    std::ofstream fout("ascNumberList.txt");
    for(int i=1;i<=numberOfElements;i++) {
        fout << minInteger << " ";
        minInteger += distribution(generator);
        if (i % 20 == 0)
            fout << "\n";

    }
}

void generateListOfConsecutiveDescendingPositiveIntegers( int minDistanceBetweenIntegers, int maxDistanceBetweenIntegers,int numberOfElements,int maxInteger){
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice()); // seed the generator
    std::uniform_int_distribution<> distribution(minDistanceBetweenIntegers,maxDistanceBetweenIntegers);
    std::ofstream fout("descNumberList.txt");

    for(int i=numberOfElements;i>=1 && maxInteger>=0;i--) {
        fout << maxInteger << " ";
        maxInteger -= distribution(generator);
        if (i % 20 == 0)
            fout << "\n";

    }
}