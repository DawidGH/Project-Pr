/**
 * @file main.cpp
 * @brief G³ówny plik aplikacji demonstracyjnej algorytmu Merge Sort.
 *
 * Plik zawiera funkcjê main z pêtl¹ obs³uguj¹c¹ menu u¿ytkownika,
 * a tak¿e szablony funkcji pomocniczych do wczytywania i wyœwietlania danych.
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#include <type_traits>
#include "MergeSort.h" 

 /**
  * @brief Funkcja pomocnicza do wczytywania wektora danych od u¿ytkownika.
  *
  * Pobiera ca³¹ liniê tekstu, a nastêpnie parsuje j¹ na pojedyncze elementy.
  * Jeœli u¿ytkownik nie poda danych (wciœnie tylko ENTER), funkcja zwraca
  * domyœlny zestaw danych testowych odpowiedni dla danego typu.
  *
  * @tparam T Typ danych w wektorze (np. int, double).
  * @param typeName Nazwa typu wyœwietlana w komunikacie dla u¿ytkownika (np. "INT").
  * @return std::vector<T> Wektor wype³niony danymi wprowadzonymi przez u¿ytkownika lub danymi domyœlnymi.
  */
template <typename T>
std::vector<T> readVector(const std::string& typeName) {
    std::vector<T> vec;
    std::string line;
    T value;

    std::cout << "\n>>> Wprowadz elementy typu " << typeName << " oddzielone spacjami (zatwierdz ENTER): \n> ";

    // U¿ywamy getline, aby wczytaæ ca³¹ liniê tekstu (wraz ze spacjami)
    std::getline(std::cin, line);

    // Tworzymy strumieñ z wczytanej linii, co u³atwia wyci¹ganie poszczególnych liczb
    std::stringstream ss(line);

    // Operator >> automatycznie pomija bia³e znaki i konwertuje tekst na typ T
    while (ss >> value) {
        vec.push_back(value);
    }

    // Obs³uga przypadku, gdy u¿ytkownik nic nie wpisa³
    if (vec.empty()) {
        std::cout << "(Brak danych - uzywam domyslnych)\n";

        // 'if constexpr' (C++17) pozwala na sprawdzenie typu w czasie kompilacji.
        // Dziêki temu kompilator wygeneruje tylko ten kod, który pasuje do typu T.
        if constexpr (std::is_same_v<T, int>)    return { 10, 5, 2, 8, 1, 12, -3, 0 };
        if constexpr (std::is_same_v<T, double>) return { 9.99, 3.14, 0.01, -2.5, 5.5, 1.1 };

        return {}; // Pusty wektor dla innych typów
    }
    return vec;
}

/**
 * @brief Wypisuje zawartoœæ wektora na standardowe wyjœcie.
 *
 * @tparam T Typ danych przechowywanych w wektorze.
 * @param vec Referencja do wektora, który ma zostaæ wyœwietlony.
 */
template <typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << "[ ";
    // Pêtla range-based for - iteruje po wszystkich elementach wektora
    for (const auto& x : vec) std::cout << x << " ";
    std::cout << "]\n";
}

/**
 * @brief G³ówna funkcja programu.
 *
 * Realizuje proste menu konsolowe (CLI) pozwalaj¹ce u¿ytkownikowi wybraæ
 * typ danych do sortowania lub zakoñczyæ dzia³anie programu.
 * Posiada zabezpieczenia przed b³êdnym wprowadzeniem danych.
 *
 * @return int Kod wyjœcia (0 oznacza poprawne zakoñczenie).
 */
int main() {
    int wybor;
    bool czyDalej = true;

    // G³ówna pêtla programu
    while (czyDalej) {
        std::cout << "\n MENU MERGE SORT \n";
        std::cout << "1. Sortuj INT\n";
        std::cout << "2. Sortuj DOUBLE\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wybor: ";
        std::cin >> wybor;

        // Obs³uga b³êdu wejœcia (np. gdy u¿ytkownik wpisze literê zamiast cyfry)
        if (std::cin.fail()) {
            std::cin.clear(); // Reset flag b³êdu strumienia
            // Ignorujemy wszystkie znaki w buforze a¿ do znaku nowej linii
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Blad! Podaj liczbe.\n";
            continue; // Wracamy na pocz¹tek pêtli
        }

        // Wa¿ne: po wczytaniu liczby (cin >> wybor) w buforze zostaje znak nowej linii '\n'.
        // Jeœli go nie usuniemy, funkcja getline w readVector() "po³knie" go i uzna, ¿e wpisano pust¹ liniê.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (wybor) {
        case 1: {
            // Tworzymy obiekt sortuj¹cy dla liczb ca³kowitych
            MergeSorter<int> sorterInt;
            // Pobieramy dane (z parametrem szablonu <int>)
            std::vector<int> dane = readVector<int>("INT");

            std::cout << "Przed: "; printVector(dane);
            sorterInt.sort(dane); // Wywo³anie w³aœciwego algorytmu
            std::cout << "Po:    "; printVector(dane);
            break;
        }
        case 2: {
            // To samo dla liczb zmiennoprzecinkowych (double)
            MergeSorter<double> sorterDouble;
            std::vector<double> dane = readVector<double>("DOUBLE");

            std::cout << "Przed: "; printVector(dane);
            sorterDouble.sort(dane);
            std::cout << "Po:    "; printVector(dane);
            break;
        }
        case 0:
            // Zakoñczenie pêtli
            czyDalej = false;
            break;
        default:
            std::cout << "Nieznana opcja.\n";
        }
    }
    return 0;
}