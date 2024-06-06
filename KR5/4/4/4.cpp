#include <iostream>
#include <cstring>
#include <cstdlib>

int main(int argc, char* argv[]) {

    system("chcp 1251");

    // Проверяем, переданы ли правильное количество параметров (должно быть 4 параметра).
    if (argc != 4) {
        std::cout << "Использование: " << argv[0] << " -a/-m операнд1 операнд2" << std::endl;
        return 1;
    }

    // Получаем флаг (-a или -m) из второго параметра.
    char* flag = argv[1];

    // Проверяем, что флаг соответствует ожидаемым значениям -a или -m.
    if (strncmp(flag, "-a", 2) != 0 && strncmp(flag, "-m", 2) != 0) {
        std::cout << "Неверный флаг. Используйте -a для сложения или -m для умножения." << std::endl;
        return 1;
    }

    // Преобразуем операнды из строк в целые числа.
    int operand1 = atoi(argv[2]);
    int operand2 = atoi(argv[3]);

    // Выполняем соответствующую операцию в зависимости от флага.
    if (strncmp(flag, "-a", 2) == 0) {
        int result = operand1 + operand2;
        std::cout << "Сумма: " << result << std::endl;
    }
    else if (strncmp(flag, "-m", 2) == 0) {
        int result = operand1 * operand2;
        std::cout << "Произведение: " << result << std::endl;
    }

    return 0;
}
