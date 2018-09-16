//
// Created by darius on 16/09/18.
//

#include <vector>

#include "mergeSort.h"

template <typename Iterator>
std::vector<typename Iterator::value_type> merge(const Iterator first, const Iterator mid, const Iterator last){
    std::vector<typename Iterator::value_type> result;
    result.reserve(std::distance(first, last));
    Iterator left = first, right = mid;
    // push back smallest element from left or right until either is exhausted
    while (left != mid and right != last){
        result.push_back( *left < *right ? *left++ : *right++ );
    }
    // push back remaining values if one of the iterators had more elements
    if (left == mid){
        // left was exhausted, insert remaining elements from the right
        result.insert(result.end(), right, last);
    }else {
        // right was exhausted, insert remaining elements from the left
        result.insert(result.end(), left, mid);
    }
    return result;

}

template <typename Iterator>
void mergeSort(Iterator first, Iterator last){
    auto length = std::distance(first, last);
    if (length < 2)
        return;
    auto mid = std::next(first, length/2);
    mergeSort(first, mid);
    mergeSort(mid, last);

    auto mergedVector = merge(first, mid, last);
    // copy over results to input iterator
    for (auto element : mergedVector){
        *first = element;
        ++first;
    }
}