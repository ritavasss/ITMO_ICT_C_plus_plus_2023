#include <iostream>

using namespace std; // Директива для использования std

bool Input(int& a, int& b) {
    cout << "Введите два целых числа: ";
    cin >> a >> b;

    if (!(a && b)) {  // Попытка считать два целых числа
        cin.clear();  // Сброс флага ошибки ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
        return false;
    }

    return true;
}

int main() {
    system("chcp 1251");

    int a, b;

    if (!Input(a, b)) {
        cerr << "Ошибка" << endl;
        return 1;
    }

    int s = a + b;

    cout << s << endl;

    return 0;
}
