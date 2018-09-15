#include <iostream>
#include <vector>
#include <functional>

#include "selectionSort.h"
#include "bubbleSort.h"

template <typename T>
void printVector(const T& vec){
    for (auto const& value: vec){
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void sortFunction(T startIterator, T endIterator){
    bubbleSort(startIterator, endIterator);
}

int main() {
    std::vector<int> ascending{1, 2, 3, 4, 5};
    std::vector<int> descending{5, 4, 3, 2, 1};
    std::vector<int> unsorted{2, 3, 5, 1, 4};
    std::vector<int> multiples{3, 3, 4, 3, 2, 4, 2, 4, 4, 1};
    std::vector<int> empty{};

    //sortFunction(bubbleSort, unsorted.begin(), unsorted.end());
    //printVector(unsorted);

    printVector(descending);
    sortFunction(descending.begin(), descending.end());
    printVector(descending);
    std::cout << std::endl;

    printVector(ascending);
    sortFunction(ascending.begin(), ascending.end());
    printVector(ascending);
    std::cout << std::endl;

    printVector(unsorted);
    sortFunction(unsorted.begin(), unsorted.end());
    printVector(unsorted);
    std::cout << std::endl;

    printVector(empty);
    sortFunction(empty.begin(), empty.end());
    printVector(empty);
    std::cout << std::endl;

    printVector(multiples);
    sortFunction(multiples.begin(), multiples.end());
    printVector(multiples);
    std::cout << std::endl;

    return 0;
}