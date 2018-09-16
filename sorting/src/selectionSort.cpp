//
// Created by darius on 15/09/18.
//

#include <iostream>
#include <algorithm>

#include "selectionSort.h"

template <typename Iterator>
inline
Iterator iter_min(Iterator a, Iterator b){
    // Return iterator with minimum value
    return (*a < *b ? a : b);
}

template <typename Iterator>
inline
void iter_swap(Iterator &a, Iterator &b){
    // Swap values of two iterators
    auto temp = *a;
    *a = *b;
    *b = temp;
}

template <typename Iterator>
void selectionSort(Iterator begin, Iterator end){
    for (auto outer_iterator = begin; outer_iterator != end; ++outer_iterator){
        Iterator min_element = outer_iterator;
        for (auto inner_iterator = outer_iterator; inner_iterator != end; ++inner_iterator){
            min_element = iter_min(min_element, inner_iterator);
        }
        iter_swap(outer_iterator, min_element);
    }
}