#ifndef SORTING_INSERTIONSORT_H
#define SORTING_INSERTIONSORT_H

template <typename Iterator>
void insertionSort(Iterator first, Iterator last) {
    for (auto selectedElement = first; selectedElement != last; ++selectedElement) {
        for (auto movableElement = selectedElement; movableElement != first; --movableElement) {
            if (*movableElement < *(movableElement - 1)) {
                std::iter_swap(movableElement, movableElement - 1);
            }
        }
    }
}


#endif //SORTING__INSERTIONSORT_H
