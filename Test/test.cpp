/**
 * @file tests.cpp
 * @brief Zbiór testów jednostkowych dla klasy MergeSorter.
 *
 * Plik zawiera testy wykorzystuj¹ce framework Google Test (gtest).
 * Pokrywa ró¿ne scenariusze, w tym przypadki brzegowe, tablice losowe,
 * posortowane odwrotnie oraz duplikaty.
 */

#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include <random>
#include "mergeSort.h" 

 /**
  * @brief Test 1: Sprawdza zachowanie dla tablicy, która jest ju¿ posortowana.
  *
  * Oczekujemy, ¿e algorytm nie zmieni kolejnoœci elementów i zakoñczy siê sukcesem.
  */
TEST(MergeSortTest, Req01_AlreadySorted) {
    // Arrange (Przygotowanie): Tworzymy obiekt sortera i dane wejœciowe
    MergeSorter<int> sorter;
    std::vector<int> input = { 1, 2, 3, 4, 5 };

    // Oczekiwany wynik jest taki sam jak wejœcie
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    // Act (Dzia³anie): Uruchamiamy sortowanie
    sorter.sort(input);

    // Assert (Weryfikacja): Sprawdzamy, czy wynik jest zgodny z oczekiwaniami
    EXPECT_EQ(input, expected);
}

/**
 * @brief Test 2: Sprawdza sortowanie tablicy posortowanej odwrotnie (malej¹co).
 *
 * Jest to pesymistyczny przypadek dla niektórych algorytmów,
 * Merge Sort powinien sobie z nim poradziæ stabilnie.
 */
TEST(MergeSortTest, Req02_ReverseSorted) {
    MergeSorter<int> sorter;
    // Dane wejœciowe w kolejnoœci malej¹cej
    std::vector<int> input = { 5, 4, 3, 2, 1 };
    // Oczekujemy tablicy rosn¹cej
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    sorter.sort(input);

    // Weryfikacja równoœci wektorów
    EXPECT_EQ(input, expected);
}

/**
 * @brief Test 3: Sprawdza sortowanie losowej tablicy liczb dodatnich.
 *
 * Standardowy przypadek u¿ycia algorytmu.
 */
TEST(MergeSortTest, Req03_RandomArray) {
    MergeSorter<int> sorter;
    std::vector<int> input = { 12, 7, 14, 9, 10, 11 };
    // Rêcznie ustalamy oczekiwany wynik
    std::vector<int> expected = { 7, 9, 10, 11, 12, 14 };

    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

/**
 * @brief Test 4: Sprawdza sortowanie tablicy zawieraj¹cej tylko liczby ujemne.
 *
 * Upewniamy siê, ¿e algorytm poprawnie porównuje liczby ze znakiem minus.
 */
TEST(MergeSortTest, Req04_OnlyNegative) {
    MergeSorter<int> sorter;
    std::vector<int> input = { -5, -1, -10, -3, -8 };
    // Pamiêtamy: -10 jest mniejsze od -1
    std::vector<int> expected = { -10, -8, -5, -3, -1 };

    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

/**
 * @brief Test 5: Sprawdza sortowanie mieszanki liczb dodatnich, ujemnych i zera.
 */
TEST(MergeSortTest, Req05_MixedNegativePositive) {
    MergeSorter<int> sorter;
    std::vector<int> input = { -5, 10, 0, -2, 5 };
    // Sprawdzamy poprawnoœæ przejœcia przez zero
    std::vector<int> expected = { -5, -2, 0, 5, 10 };

    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

/**
 * @brief Test 6: Sprawdza obs³ugê pustej tablicy.
 *
 * Jest to wa¿ny przypadek brzegowy. Algorytm nie powinien wyrzuciæ b³êdu,
 * a tablica powinna pozostaæ pusta.
 */
TEST(MergeSortTest, Req06_EmptyArray) {
    MergeSorter<int> sorter;
    std::vector<int> input = {};

    // Sprawdzamy, czy wywo³anie funkcji nie powoduje wyj¹tku/crashu
    EXPECT_NO_THROW(sorter.sort(input));

    // Sprawdzamy, czy tablica nadal jest pusta
    EXPECT_TRUE(input.empty());
}

/**
 * @brief Test 7: Sprawdza sortowanie tablicy jednoelementowej.
 *
 * Przypadek brzegowy rekurencji (warunek stopu).
 */
TEST(MergeSortTest, Req07_SingleElement) {
    MergeSorter<int> sorter;
    std::vector<int> input = { 42 };
    std::vector<int> expected = { 42 };

    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

/**
 * @brief Test 8: Sprawdza sortowanie tablicy z duplikatami (liczby dodatnie).
 *
 * Merge Sort jest algorytmem stabilnym (zachowuje kolejnoœæ równych elementów),
 * test sprawdza czy duplikaty s¹ poprawnie zgrupowane obok siebie.
 */
TEST(MergeSortTest, Req08_DuplicatesPositive) {
    MergeSorter<int> sorter;
    std::vector<int> input = { 5, 1, 5, 2, 1 };
    std::vector<int> expected = { 1, 1, 2, 5, 5 };

    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

/**
 * @brief Test 9: Sprawdza sortowanie tablicy z duplikatami (liczby ujemne).
 */
TEST(MergeSortTest, Req09_DuplicatesNegative) {
    MergeSorter<int> sorter;
    std::vector<int> input = { -5, -10, -5, -2, -10 };
    std::vector<int> expected = { -10, -10, -5, -5, -2 };

    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

/**
 * @brief Test 10: Sprawdza sortowanie tablicy mieszanej z duplikatami i zerami.
 */
TEST(MergeSortTest, Req10_DuplicatesMixed) {
    MergeSorter<int> sorter;
    std::vector<int> input = { -2, 5, 0, -2, 5, 0 };
    std::vector<int> expected = { -2, -2, 0, 0, 5, 5 };

    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

/**
 * @brief Test 11: Sprawdza sortowanie tablicy dwuelementowej.
 *
 * Najmniejszy nietrywialny przypadek wymagaj¹cy scalania.
 */
TEST(MergeSortTest, Req11_TwoElementsSorted) {
    MergeSorter<int> sorter;
    std::vector<int> input = { 1, 10 };
    std::vector<int> expected = { 1, 10 };

    sorter.sort(input);
    EXPECT_EQ(input, expected);
}

/**
 * @brief Test 12: Test wydajnoœciowy/poprawnoœci dla wiêkszej tablicy (prosta generacja).
 *
 * Generuje tablicê liczb od 150 do 1, sortuje j¹ i porównuje
 * z wynikiem standardowego sortowania bibliotecznego (std::sort).
 */
TEST(MergeSortTest, Req12_LargeArraySimple) {
    MergeSorter<int> sorter;
    std::vector<int> input;

    // Generowanie danych: 150, 149, ..., 1
    for (int i = 150; i > 0; --i) input.push_back(i);

    // Tworzymy wzorzec (expected) kopiuj¹c input
    std::vector<int> expected = input;
    // U¿ywamy zaufanej funkcji std::sort do wygenerowania poprawnego wyniku
    std::sort(expected.begin(), expected.end());

    // Sortujemy nasz¹ implementacj¹
    sorter.sort(input);

    // Porównujemy nasz wynik z wynikiem wzorcowym
    EXPECT_EQ(input, expected);
}

/**
 * @brief Test 13: Test dla wiêkszej tablicy z bardziej skomplikowanymi danymi.
 *
 * Generuje dane za pomoc¹ operacji modulo, co tworzy powtarzaj¹ce siê
 * sekwencje i liczby ujemne. Sprawdza poprawnoœæ na 200 elementach.
 */
TEST(MergeSortTest, Req13_LargeArrayComplex) {
    MergeSorter<int> sorter;
    std::vector<int> input;

    // Generowanie danych pseudolosowych za pomoc¹ wzoru matematycznego
    // (i % 50) - 25 da wartoœci w zakresie od -25 do 24
    for (int i = 0; i < 200; ++i) input.push_back((i % 50) - 25);

    // Przygotowanie wzorca za pomoc¹ std::sort
    std::vector<int> expected = input;
    std::sort(expected.begin(), expected.end());

    // Sortowanie i weryfikacja
    sorter.sort(input);
    EXPECT_EQ(input, expected);
}