#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include <random>
#include "mergeSort.h" 

// 1. Ju¿ posortowana
TEST(MergeSortTest, Req01_AlreadySorted) {
    MergeSorter<int> sorter;
    std::vector<int> input = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

// 2. Odwrotnie posortowana
TEST(MergeSortTest, Req02_ReverseSorted) {
    MergeSorter<int> sorter;
    std::vector<int> input = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

// 3. Losowa
TEST(MergeSortTest, Req03_RandomArray) {
    MergeSorter<int> sorter;
    std::vector<int> input = { 12, 7, 14, 9, 10, 11 };
    std::vector<int> expected = { 7, 9, 10, 11, 12, 14 };
    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

// 4. Tylko ujemne
TEST(MergeSortTest, Req04_OnlyNegative) {
    MergeSorter<int> sorter;
    std::vector<int> input = { -5, -1, -10, -3, -8 };
    std::vector<int> expected = { -10, -8, -5, -3, -1 };
    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

// 5. Ujemne i dodatnie
TEST(MergeSortTest, Req05_MixedNegativePositive) {
    MergeSorter<int> sorter;
    std::vector<int> input = { -5, 10, 0, -2, 5 };
    std::vector<int> expected = { -5, -2, 0, 5, 10 };
    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

// 6. Pusta tablica
TEST(MergeSortTest, Req06_EmptyArray) {
    MergeSorter<int> sorter;
    std::vector<int> input = {};
    EXPECT_NO_THROW(sorter.sort(input));
    EXPECT_TRUE(input.empty());
}

// 7. Jeden element
TEST(MergeSortTest, Req07_SingleElement) {
    MergeSorter<int> sorter;
    std::vector<int> input = { 42 };
    std::vector<int> expected = { 42 };
    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

// 8. Duplikaty (dodatnie)
TEST(MergeSortTest, Req08_DuplicatesPositive) {
    MergeSorter<int> sorter;
    std::vector<int> input = { 5, 1, 5, 2, 1 };
    std::vector<int> expected = { 1, 1, 2, 5, 5 };
    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

// 9. Duplikaty (ujemne)
TEST(MergeSortTest, Req09_DuplicatesNegative) {
    MergeSorter<int> sorter;
    std::vector<int> input = { -5, -10, -5, -2, -10 };
    std::vector<int> expected = { -10, -10, -5, -5, -2 };
    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

// 10. Mieszane z duplikatami
TEST(MergeSortTest, Req10_DuplicatesMixed) {
    MergeSorter<int> sorter;
    std::vector<int> input = { -2, 5, 0, -2, 5, 0 };
    std::vector<int> expected = { -2, -2, 0, 0, 5, 5 };
    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

// 11. Dwa elementy
TEST(MergeSortTest, Req11_TwoElementsSorted) {
    MergeSorter<int> sorter;
    std::vector<int> input = { 1, 10 };
    std::vector<int> expected = { 1, 10 };
    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

// 12. Du¿a tablica (>100)
TEST(MergeSortTest, Req12_LargeArraySimple) {
    MergeSorter<int> sorter;
    std::vector<int> input;
    for (int i = 150; i > 0; --i) input.push_back(i);

    std::vector<int> expected = input;
    std::sort(expected.begin(), expected.end());

    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

// 13. Du¿a tablica (>100) complex
TEST(MergeSortTest, Req13_LargeArrayComplex) {
    MergeSorter<int> sorter;
    std::vector<int> input;
    for (int i = 0; i < 200; ++i) input.push_back((i % 50) - 25);

    std::vector<int> expected = input;
    std::sort(expected.begin(), expected.end());

    sorter.sort(input);
    EXPECT_EQ(input, expected);
}