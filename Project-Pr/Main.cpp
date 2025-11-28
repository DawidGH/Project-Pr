#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#include <type_traits>
#include "MergeSort.h" 

template <typename T>
std::vector<T> readVector(const std::string& typeName) {
    std::vector<T> vec;
    std::string line;
    T value;

    std::cout << "\n>>> Wprowadz elementy typu " << typeName << " oddzielone spacjami (zatwierdz ENTER): \n> ";
    std::getline(std::cin, line);
    std::stringstream ss(line);

    while (ss >> value) {
        vec.push_back(value);
    }

    if (vec.empty()) {
        std::cout << "(Brak danych - uzywam domyslnych)\n";
        if constexpr (std::is_same_v<T, int>)    return { 10, 5, 2, 8, 1, 12, -3, 0 };
        if constexpr (std::is_same_v<T, double>) return { 9.99, 3.14, 0.01, -2.5, 5.5, 1.1 };
        return {};
    }
    return vec;
}

template <typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const auto& x : vec) std::cout << x << " ";
    std::cout << "]\n";
}

int main() {
    int wybor;
    bool czyDalej = true;

    while (czyDalej) {
        std::cout << "\n MENU MERGE SORT \n";
        std::cout << "1. Sortuj INT\n";
        std::cout << "2. Sortuj DOUBLE\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wybor: ";
        std::cin >> wybor;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Blad! Podaj liczbe.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Czyszczenie bufora

        switch (wybor) {
        case 1: {
            MergeSorter<int> sorterInt;
            std::vector<int> dane = readVector<int>("INT");
            std::cout << "Przed: "; printVector(dane);
            sorterInt.sort(dane);
            std::cout << "Po:    "; printVector(dane);
            break;
        }
        case 2: {
            MergeSorter<double> sorterDouble;
            std::vector<double> dane = readVector<double>("DOUBLE");
            std::cout << "Przed: "; printVector(dane);
            sorterDouble.sort(dane);
            std::cout << "Po:    "; printVector(dane);
            break;
        }
        case 0:
            czyDalej = false;
            break;
        default:
            std::cout << "Nieznana opcja.\n";
        }
    }
    return 0;
}