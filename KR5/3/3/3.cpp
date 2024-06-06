#include <iostream>
using namespace std;

// Функция для поиска элемента с использованием метода транспозиции
int transposeSearch(int const n, int* a, int key) {

    int left = 0; // Левая граница поиска
    int right = n - 1; // Правая граница поиска

    while (left <= right) {
        if (a[left] == key) {
            return left; // Элемент найден в начале массива
        }

        // Поиск элемента в оставшейся части массива
        for (int i = left + 1; i <= right; i++) {
            if (a[i] == key) {
                // Обмен элемента с предыдущим для выполнения транспозиции
                swap(a[i], a[i - 1]);
                return i - 1; // Возвращаем новую позицию элемента
            }
        }

        left++; // Переходим к следующему элементу
    }

    return -1; // Элемент не найден
}

int main() {

    system("chcp 1251");

    int const N = 8;
    int arr[N] = {5, 3, 8, 2, 7, 1, 4, 6};
    int key = 8;

    int index = (transposeSearch(N, arr, key));

    if (index != -1) {
        cout << "Элемент " << key << " найден на позиции " << index << endl;
    }
    else {
        cout << "Элемент " << key << " не найден в массиве." << endl;
    }

    return 0;
}
