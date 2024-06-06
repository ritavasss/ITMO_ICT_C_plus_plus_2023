#include <iostream>

template<class T>
double average(T arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    int intArray[] = { 1, 2, 3, 4, 5 };
    long longArray[] = { 10L, 20L, 30L, 40L, 50L };
    double doubleArray[] = { 1.5, 2.5, 3.5, 4.5, 5.5 };
    char charArray[] = { 'a', 'b', 'c', 'd', 'e' };

    int intSize = sizeof(intArray) / sizeof(int);
    int longSize = sizeof(longArray) / sizeof(long);
    int doubleSize = sizeof(doubleArray) / sizeof(double);
    int charSize = sizeof(charArray) / sizeof(char);

    std::cout << "Average of intArray: " << average(intArray, intSize) << std::endl;
    std::cout << "Average of longArray: " << average(longArray, longSize) << std::endl;
    std::cout << "Average of doubleArray: " << average(doubleArray, doubleSize) << std::endl;

    // Так как массив char содержит символы, среднее арифметическое не имеет смысла
    // Но можно преобразовать значения char в числовой тип и вычислить среднее
    double charAverage = average(charArray, charSize);
    std::cout << "Average of charArray (as numbers): " << charAverage << std::endl;

    return 0;
}
