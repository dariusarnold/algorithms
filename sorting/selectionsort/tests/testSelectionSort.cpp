//
// Created by darius on 15/09/18.
//

#include "gtest/gtest.h"
#include <vector>
#include <algorithm>

#include "../src/selectionSort.h"

std::vector<int> ascending{1, 2, 3, 4, 5};
std::vector<int> descending{5, 4, 3, 2, 1};
std::vector<int> unsorted{2, 3, 5, 1, 4};
std::vector<int> multiples{3, 3, 3, 2, 1, 2, 1};
std::vector<int> empty{};
std::vector<int> one_element{42};
std::vector<int> two_elements_in_order{6, 9};
std::vector<int> two_elements_no_order{9, 6};
std::vector<int> same_two{9, 9};

/**
 * Edge case of empty input: Sorting should be able to handle an empty sequence
 */
TEST(SelectionSortTestCase, EmptySequence){
    std::vector<int> v1 = empty;
    selectionSort(v1.begin(), v1.end());
    std::vector<int> v2 = v1;
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v1, v2);
}


/**
 * Trivial case: Only one element in input sequence
 */
TEST(SelectionSortTestCase, OneElement){
    std::vector<int> v1 = one_element;
    selectionSort(v1.begin(), v1.end());
    std::vector<int> v2 = v1;
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v1, v2);
}

/**
 * Test all combinations of two values: different but sorted, different and unsorted, different
 */
TEST(SelectionSortTestCase, TwoAlreadySortedElements){
    std::vector<int> v1 = two_elements_in_order;
    selectionSort(v1.begin(), v1.end());
    std::vector<int> v2 = v1;
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v1, v2);
}

TEST(SelectionSortTestCase, TwoUnsortedElements){
    std::vector<int> v1 = two_elements_no_order;
    selectionSort(v1.begin(), v1.end());
    std::vector<int> v2 = v1;
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v1, v2);
}

TEST(SelectionSortTestCase, SameTwoElements){
    std::vector<int> v1 = same_two;
    selectionSort(v1.begin(), v1.end());
    std::vector<int> v2 = v1;
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v1, v2);
}

/**
 * Test whether input in already sorted descending order is sorted correctly
 */
TEST(SelectionSortTestCase, DescendingOrder){
    std::vector<int> v1 = descending;
    selectionSort(v1.begin(), v1.end());
    std::vector<int> v2 = v1;
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v1, v2);
}

/**
 * Test whether input in already sorted ascending order is sorted correctly
 */
TEST(SelectionSortTestCase, AscendingOrder){
    std::vector<int> v1 = ascending;
    selectionSort(v1.begin(), v1.end());
    std::vector<int> v2 = v1;
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v1, v2);
}

/**
 * Test whether input in random order is sorted correctly
 */
TEST(SelectionSortTestCase, RandomOrder){
    std::vector<int> v1 = unsorted;
    selectionSort(v1.begin(), v1.end());
    std::vector<int> v2 = v1;
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v1, v2);
}

/**
 * Test whether input with multiples of the same values is sorted correctly. Does not test
 */
TEST(SelectionSortTestCase, MultiplesOfSameValues){
    std::vector<int> v1 = multiples;
    selectionSort(v1.begin(), v1.end());
    std::vector<int> v2 = v1;
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v1, v2);
}
