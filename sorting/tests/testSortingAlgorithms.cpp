//
// Created by darius on 15/09/18.
//

#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include <map>

#include "selectionSort.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "mergeSort.h"


/**
 * To add a sorting method:
 * - Define a test fixture that derives from GenericSortingTest
 * - Create a test pattern that creates two copies of the parameter std::vector, sorts and compares them
 * - Instantiate a test case that calls the pattern with all parameters from testInputs
 */

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


/**
 * Define fixture class with type of parameter values as the type a key/value pair of a std::map have
 */
class GenericSortingTest : public ::testing::TestWithParam<std::pair<const std::string, std::vector<int>>> {
public:
    /**
     * This custom test suffix generator returns the string name for the pair of values
     * of an element in the map testInputs.
     */
    struct printToStringName{
        template <typename ParamType>
        std::string operator()(const testing::TestParamInfo<ParamType>& info) const{
            return info.param.first;    // info.param will contain the pair of key/value from testInputs
        }
    };
};


/**
 * Create test fixture for sorting method, so every sorting methods test results
 * will be split. Additionally, more tests than just comparing to the std::sort
 * result could be implemented.
 */
class SelectionSortTest : public GenericSortingTest{};

class BubbleSortTest : public GenericSortingTest{};

class InsertionSortTest : public GenericSortingTest{};

class MergeSortTest : public GenericSortingTest{};


/**
 * Create test patterns that run the sorting algorithm for all vectors in testInputs
 * and compare the result to the std::sort function.
 */

TEST_P(SelectionSortTest, SameSortResultsAsSTLSort){
    auto v1 = GetParam().second;
    auto v2 = GetParam().second;
    selectionSort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v2, v1);
}

TEST_P(BubbleSortTest, SameSortResultsAsSTLSort){
    auto v1 = GetParam().second;
    auto v2 = GetParam().second;
    bubbleSort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v2, v1);
}

TEST_P(InsertionSortTest, SameSortResultsAsSTLSort){
    auto v1 = GetParam().second;
    auto v2 = GetParam().second;
    insertionSort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v2, v1);
}

TEST_P(MergeSortTest, SameSortResultsAsSTLSort){
    auto v1 = GetParam().second;
    auto v2 = GetParam().second;
    mergeSort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    EXPECT_EQ(v2, v1);
}

/**
 * Instantiate test cases with all parameters (differently sorted std::vectors) in testInputs.
 */
INSTANTIATE_TEST_CASE_P(SortingTest, SelectionSortTest, ::testing::ValuesIn(testInputs),
                        SelectionSortTest::printToStringName());

INSTANTIATE_TEST_CASE_P(SortingTest, BubbleSortTest, ::testing::ValuesIn(testInputs),
                        BubbleSortTest::printToStringName());

INSTANTIATE_TEST_CASE_P(SortingTest, InsertionSortTest, ::testing::ValuesIn(testInputs),
                        InsertionSortTest::printToStringName());

INSTANTIATE_TEST_CASE_P(SortingTest, MergeSortTest, ::testing::ValuesIn(testInputs), 
                        InsertionSortTest::printToStringName());