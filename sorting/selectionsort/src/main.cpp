#include <iostream>
#include <vector>

#include "selectionSort.h"

template <typename T>
void printVector(const T& vec){
    for (auto const& value: vec){
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {

    std::vector<int> ascending{1, 2, 3, 4, 5};
    std::vector<int> descending{5, 4, 3, 2, 1};
    std::vector<int> unsorted{2, 3, 5, 1, 4};
    std::vector<int> multiples{3, 3, 3, 2, 1, 2, 1};
    std::vector<int> empty{};

    printVector(descending);
    selectionSort(descending.begin(), descending.end());
    printVector(descending);
    std::cout << std::endl;

    printVector(ascending);
    selectionSort(ascending.begin(), ascending.end());
    printVector(ascending);
    std::cout << std::endl;

    printVector(unsorted);
    selectionSort(unsorted.begin(), unsorted.end());
    printVector(unsorted);
    std::cout << std::endl;

    printVector(empty);
    selectionSort(empty.begin(), empty.end());
    printVector(empty);
    std::cout << std::endl;

    printVector(multiples);
    selectionSort(multiples.begin(), multiples.end());
    printVector(multiples);
    std::cout << std::endl;

    return 0;
}