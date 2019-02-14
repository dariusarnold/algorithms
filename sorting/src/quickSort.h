#ifndef SORTINGQUICKSORT_H
#define SORTINGQUICKSORT_H

template <typename Iterator>
void quickSort(Iterator begin, Iterator end){
    if (std::distance(begin, end) < 2){
        // one element is sorted per definition
        return;
    }
    auto right = std::prev(end);
    auto left = std::next(begin);
    auto pivot = begin;
    while (left < right) {
        if (*left <= *pivot) {
            // leave elements in position if no swap required
            ++left;
        } else {
            // dont increment left so the swapped in element from right is checked in the next iteration
            std::iter_swap(left, right);
            --right;
        }
    }
    if (*pivot > *left) {
        std::iter_swap(left, pivot);
    }
    quickSort(begin, left);
    quickSort(left, end);
}


#endif //SORTINGQUICKSORT_H
