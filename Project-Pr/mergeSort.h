#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <iostream>

/**
 * @brief Klasa szablonowa realizuj¹ca algorytm sortowania przez scalanie (Merge Sort).
 *
 * Klasa udostêpnia metodê do sortowania wektorów dowolnego typu,
 * pod warunkiem, ¿e typ ten obs³uguje operatory porównania (<=).
 *
 * @tparam T Typ danych przechowywanych w wektorze (np. int, float, double).
 */
template <typename T>
class MergeSorter {
public:
    /**
     * @brief G³ówna metoda uruchamiaj¹ca sortowanie.
     *
     * Jest to publiczny interfejs klasy. Sprawdza poprawnoœæ danych wejœciowych
     * i wywo³uje w³aœciw¹, rekurencyjn¹ metodê sortuj¹c¹.
     *
     * @param arr Referencja do wektora, który ma zostaæ posortowany.
     */
    void sort(std::vector<T>& arr) {
        // Zabezpieczenie: jeœli wektor jest pusty, nie ma czego sortowaæ -> wychodzimy
        if (arr.empty()) return;

        // Wywo³ujemy rekurencyjn¹ funkcjê pomocnicz¹ dla ca³ego zakresu tablicy
        // od indeksu 0 do ostatniego elementu (size - 1)
        mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    }

private:
    /**
     * @brief Rekurencyjna metoda dziel¹ca tablicê na mniejsze czêœci.
     *
     * Metoda dzieli zakres na pó³, wywo³uje sam¹ siebie dla lewej i prawej czêœci,
     * a nastêpnie scala posortowane podci¹gi.
     *
     * @param arr Referencja do sortowanego wektora.
     * @param left Indeks pocz¹tku aktualnie rozpatrywanego zakresu.
     * @param right Indeks koñca aktualnie rozpatrywanego zakresu.
     */
    void mergeSort(std::vector<T>& arr, int left, int right) {
        // Warunek stopu rekurencji: jeœli lewy indeks jest wiêkszy lub równy prawemu,
        // oznacza to, ¿e mamy 0 lub 1 element, wiêc jest ju¿ "posortowane".
        if (left >= right) return;

        // Obliczamy œrodek zakresu.
        // U¿ywamy wzoru left + (right - left) / 2 zamiast (left + right) / 2,
        // aby unikn¹æ przekroczenia zakresu zmiennej int (overflow) przy du¿ych liczbach.
        int mid = left + (right - left) / 2;

        // KROK 1: Dziel (Divide)
        // Rekurencyjne sortowanie lewej po³owy (od pocz¹tku do œrodka)
        mergeSort(arr, left, mid);

        // Rekurencyjne sortowanie prawej po³owy (od œrodka + 1 do koñca)
        mergeSort(arr, mid + 1, right);

        // KROK 2: Rz¹dŸ/Scalaj (Conquer/Merge)
        // Scalamy dwie posortowane po³ówki w jedn¹ ca³oœæ
        merge(arr, left, mid, right);
    }

    /**
     * @brief Metoda scalaj¹ca dwie posortowane podtablice w jedn¹.
     *
     * Scala podtablicê arr[left..mid] oraz arr[mid+1..right].
     *
     * @param arr Referencja do oryginalnego wektora.
     * @param left Pocz¹tkowy indeks lewej podtablicy.
     * @param mid Indeks koñcz¹cy lew¹ podtablicê.
     * @param right Koñcowy indeks prawej podtablicy.
     */
    void merge(std::vector<T>& arr, int left, int mid, int right) {
        // Obliczamy rozmiary tymczasowych tablic
        int n1 = mid - left + 1; // Rozmiar lewej czêœci
        int n2 = right - mid;    // Rozmiar prawej czêœci

        // Tworzymy tymczasowe wektory na dane
        std::vector<T> L(n1);
        std::vector<T> R(n2);

        // Kopiujemy dane z g³ównej tablicy do tymczasowej tablicy lewej (L)
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];

        // Kopiujemy dane z g³ównej tablicy do tymczasowej tablicy prawej (R)
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        // Indeksy pomocnicze do iterowania:
        int i = 0;    // Indeks dla tablicy L
        int j = 0;    // Indeks dla tablicy R
        int k = left; // Indeks dla g³ównej tablicy arr, gdzie wstawiamy posortowane wartoœci

        // G³ówna pêtla scalaj¹ca: porównujemy elementy z L i R
        // i wstawiamy mniejszy z nich do tablicy wynikowej arr
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i]; // Wziêliœmy element z lewej, bo by³ mniejszy
                i++;           // Przesuwamy wskaŸnik w L
            }
            else {
                arr[k] = R[j]; // Wziêliœmy element z prawej, bo by³ mniejszy
                j++;           // Przesuwamy wskaŸnik w R
            }
            k++; // Przesuwamy wskaŸnik w g³ównej tablicy
        }

        // Jeœli w tablicy L zosta³y jeszcze jakieœ elementy (bo w R siê skoñczy³y),
        // to przepisujemy je wszystkie na koniec (s¹ ju¿ posortowane)
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Analogicznie, jeœli w tablicy R zosta³y elementy, przepisujemy je
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
};

#endif // MERGESORT_H