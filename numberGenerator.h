//
// Created by dumi on 08.05.2023.
//

#ifndef MPI_SORTING_NUMBERGENERATOR_H
#define MPI_SORTING_NUMBERGENERATOR_H

void generateListOfPositiveIntegers(int minInteger,int maxInteger,int numberOfElements);
void generateListOfConsecutiveAscendingPositiveIntegers(int minDistanceBetweenIntegers,int maxDistanceBetweenIntegers,int numberOfElements,int minInteger);
void generateListOfConsecutiveDescendingPositiveIntegers( int minDistanceBetweenIntegers, int maxDistanceBetweenIntegers,int numberOfElements,int maxInteger);

#endif //MPI_SORTING_NUMBERGENERATOR_H
