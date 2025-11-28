#include "test1.h"
#include "mergeSort.h"
#include <vector>

// Zak³adamy, ¿e mergeSort.h zawiera namespace custom_sort
using std::vector;
using namespace custom_sort; // U³atwienie, aby nie pisaæ custom_sort:: wszêdzie

TEST(MergeSortTest, SortedArrayRemainsSorted) {
    // ZMIANA: Usuniêto: mergeSort<int> sorter;
    vector<int> arr = { 1, 2, 3, 4, 5 };

    // ZMIANA: Wywo³anie funkcji globalnej na zakresie
    merge_sort(arr.begin(), arr.end());

    EXPECT_EQ(arr, (vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTest, ReverseArrayGetsSorted) {
    // ZMIANA: Usuniêto: mergeSort<int> sorter;
    vector<int> arr = { 5,4,3,2,1 };

    // ZMIANA: Wywo³anie funkcji globalnej na zakresie
    merge_sort(arr.begin(), arr.end());

    EXPECT_EQ(arr, (vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTest, RandomArraySortsCorrectly) {
    // ZMIANA: Usuniêto: mergeSort<int> sorter;
    vector<int> arr = { 3,8,1,4,7,2 };

    // ZMIANA: Wywo³anie funkcji globalnej na zakresie
    merge_sort(arr.begin(), arr.end());

    EXPECT_EQ(arr, (vector<int>{1, 2, 3, 4, 7, 8}));
}

TEST(MergeSortTest, NegativeNumbersSortCorrectly) {
    // ZMIANA: Usuniêto: mergeSort<int> sorter;
    vector<int> arr = { -5, -1, -10, -3 };

    // ZMIANA: Wywo³anie funkcji globalnej na zakresie
    merge_sort(arr.begin(), arr.end());

    EXPECT_EQ(arr, (vector<int>{-10, -5, -3, -1}));
}

TEST(MergeSortTest, MixedPositiveNegativeSortsCorrectly) {
    // ZMIANA: Usuniêto: mergeSort<int> sorter;
    vector<int> arr = { 5, -2, 3, -1, 0 };

    // ZMIANA: Wywo³anie funkcji globalnej na zakresie
    merge_sort(arr.begin(), arr.end());

    EXPECT_EQ(arr, (vector<int>{-2, -1, 0, 3, 5}));
}

TEST(MergeSortTest, EmptyArrayDoesNotThrow) {
    // ZMIANA: Usuniêto: mergeSort<int> sorter;
    vector<int> arr;

    // ZMIANA: Wywo³anie funkcji globalnej na zakresie
    EXPECT_NO_THROW(merge_sort(arr.begin(), arr.end()));
    EXPECT_TRUE(arr.empty());
}

TEST(MergeSortTest, SingleElementArrayRemainsSame) {
    // ZMIANA: Usuniêto: mergeSort<int> sorter;
    vector<int> arr = { 42 };

    // ZMIANA: Wywo³anie funkcji globalnej na zakresie
    merge_sort(arr.begin(), arr.end());

    EXPECT_EQ(arr, (vector<int>{42}));
}

TEST(MergeSortTest, DuplicatesAreSortedCorrectly) {
    // ZMIANA: Usuniêto: mergeSort<int> sorter;
    vector<int> arr = { 4, 2, 2, 4, 1 };

    // ZMIANA: Wywo³anie funkcji globalnej na zakresie
    merge_sort(arr.begin(), arr.end());

    EXPECT_EQ(arr, (vector<int>{1, 2, 2, 4, 4}));
}

TEST(MergeSortTest, NegativeWithDuplicates) {
    // ZMIANA: Usuniêto: mergeSort<int> sorter;
    vector<int> arr = { -3, -1, -1, -5, -2 };

    // ZMIANA: Wywo³anie funkcji globalnej na zakresie
    merge_sort(arr.begin(), arr.end());

    EXPECT_EQ(arr, (vector<int>{-5, -3, -2, -1, -1}));
}

TEST(MergeSortTest, MixedWithDuplicates) {
    // ZMIANA: Usuniêto: mergeSort<int> sorter;
    vector<int> arr = { 3, -1, 2, -1, 3, 0 };

    // ZMIANA: Wywo³anie funkcji globalnej na zakresie
    merge_sort(arr.begin(), arr.end());

    EXPECT_EQ(arr, (vector<int>{-1, -1, 0, 2, 3, 3}));
}

TEST(MergeSortTest, TwoElementArraySorted) {
    // ZMIANA: Usuniêto: mergeSort<int> sorter;
    vector<int> arr = { 5, 1 };

    // ZMIANA: Wywo³anie funkcji globalnej na zakresie
    merge_sort(arr.begin(), arr.end());

    EXPECT_EQ(arr, (vector<int>{1, 5}));
}

TEST(MergeSortTest, LargeArrayOver100Elements) {
    // ZMIANA: Usuniêto: mergeSort<int> sorter;
    vector<int> arr;

    for (int i = 200; i >= 0; i--) arr.push_back(i);

    // ZMIANA: Wywo³anie funkcji globalnej na zakresie
    merge_sort(arr.begin(), arr.end());

    for (int i = 0; i < 201; i++) {
        EXPECT_EQ(arr[i], i);
    }
}

TEST(MergeSortTest, LargeArrayMixedSign) {
    // ZMIANA: Usuniêto: mergeSort<int> sorter;
    vector<int> arr;

    for (int i = 100; i >= -100; i--) arr.push_back(i);

    // ZMIANA: Wywo³anie funkcji globalnej na zakresie
    merge_sort(arr.begin(), arr.end());

    for (int i = 0; i < 201; i++) {
        EXPECT_EQ(arr[i], -100 + i);
    }
}