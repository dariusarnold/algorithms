//
// Created by darius on 15/09/18.
//

#include <algorithm>

template <typename Iterator>
void bubbleSort(Iterator begin, Iterator end){
    for (auto outer_iterator = begin; outer_iterator != end; ++outer_iterator){
        for (auto inner_iterator = begin; inner_iterator != (end-1); ++inner_iterator){
            if (*inner_iterator > *(inner_iterator+1)){
                std::iter_swap(inner_iterator, inner_iterator+1);
            }
        }
    }
}