#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include "selectionSort.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"

template <typename T>
void printVector(const T& vec){
    for (auto const& value: vec){
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void sortFunction(T startIterator, T endIterator){
    quickSort(startIterator, endIterator);
}

int main() {
    std::map<std::string, std::vector<int>> testInputs = {
            {"empty", {}},
            {"oneElement", {42}},
            {"sameTwo", {9, 9}},
            {"twoElementsOrdered", {6, 9}},
            {"twoElementsUnordered", {9, 6}},
            {"ascending", {1, 3, 6, 9, 10}},
            {"descending", {50, 40, 35, 25, 10}},
            {"unsorted", {2, 3, 5, 1, 9, 4}},
            {"multiples", {3, 3, 4, 3, 2, 4, 2, 4, 4, 1}}
            };

    bool allTestsPassed = true;
    for (const auto& pair : testInputs){
        auto sortInput = pair.second;
        auto stdSortInput = pair.second;
        sortFunction(sortInput.begin(), sortInput.end());
        std::sort(stdSortInput.begin(), stdSortInput.end());
        std::cout << pair.first << ": ";     // print input sequence name
        if (stdSortInput == sortInput){
            std::cout << "PASS";
        }else{
            std::cout << "FAIL";
            allTestsPassed = false;
        }
        std::cout << std::endl;
        // print before/after of sequence
        std::cout << std::string(4, ' ');
        printVector(pair.second);
        std::cout << std::string(4, ' ');
        printVector(sortInput);
        std::cout << std::endl;
    }
    allTestsPassed ? std::cout << "ALL PASS" : std::cout << "NOT ALL PASS";
    return !allTestsPassed;
}