//
// Created by darius on 16/09/18.
//

#include "insertionSort.h"

template <typename Iterator>
void insertionSort(Iterator first, Iterator last){
    for (auto selectedElement = first; selectedElement != last; ++selectedElement){
        for (auto movableElement = selectedElement; movableElement != first; --movableElement){
            if (*movableElement < *(movableElement-1)){
                std::iter_swap(movableElement, movableElement-1);
            }
        }
    }
}