#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    system("chcp 1251");
    string poem;

    // Запрос стихотворения у пользователя
    cout << "Введите стихотворение (для завершения введите 'конец' без кавычек):\n";

    while (true) {
        string line;
        getline(cin, line);

        if (line == "конец") {
            break;
        }

        poem += line + "\n";
    }

    // Откроем файл для записи
    ofstream out("стихотворение.txt");

    // Проверяем, успешно ли открыт файл
    if (out.is_open()) {
        // Записываем стихотворение в файл
        out << poem;
        out.close();
        cout << "Стихотворение успешно записано в файл 'стихотворение.txt'.\n";
    }
    else {
        cerr << "Не удалось открыть файл для записи.\n";
    }

    return 0;
}
