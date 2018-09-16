//
// Created by darius on 15/09/18.
//

#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <map>

#include "../src/selectionSort.h"
#include "../src/bubbleSort.h"


class GenericSortingTest : public ::testing::TestWithParam<std::pair<const std::string, std::vector<int>>> {

};

/**
 * This test runs for all key/value combinations in testInputs.
 * It sorts them using selectionSort and compares the result to the
 * official std::sort implementation.
 */
TEST_P(GenericSortingTest, SelectionSortTest){
    auto v1 = GetParam().second;
    auto v2 = GetParam().second;
    selectionSort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v2, v1);
}

/**
 * This test runs for all key/value combinations in testInputs.
 * It sorts them using bubbleSort and compares the result to the
 * official std::sort implementation.
 */
TEST_P(GenericSortingTest, BubbleSortTest){
    auto v1 = GetParam().second;
    auto v2 = GetParam().second;
    bubbleSort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v2, v1);
}


/**
 * This custom test suffix generator returns the string name for the pair of values
 * of an element in the map testInputs.
 */
struct getInputName{
    template <typename ParamType>
    std::string operator()(const testing::TestParamInfo<ParamType>& info) const{
        return info.param.first;
    }
};

/**
 * Map containing all input sequences. Their keys are the test names to be used.
 */
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


INSTANTIATE_TEST_CASE_P(InstantiationName, GenericSortingTest, ::testing::ValuesIn(testInputs),
                        getInputName());
