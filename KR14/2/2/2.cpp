#include <iostream>
#include <vector>
#include <iterator>

template<class Container>
void Print(const Container& container, const std::string& delimiter) {
    auto it = container.begin();
    auto end = container.end();

    if (it != end) {
        std::cout << *it;  // выводим первый элемент

        ++it;

        // выводим остальные элементы с разделителем
        for (; it != end; ++it) {
            std::cout << delimiter << *it;
        }
    }

    std::cout << "\n"; // перевод строки в конце
}

int main() {
    std::vector<int> data = { 1, 2, 3 };
    Print(data, ", "); // на экране: 1, 2, 3

    return 0;
}
