#include <iostream>
using namespace std;

int sumOfSeries(int n) {
    if (n == 1) {
        return 5;
    }
    else {
        return 5 * n + sumOfSeries(n - 1);
    }
}

int main() {
    system("chcp 1251");
    int n;
    cout << "Введите значение n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Значение n должно быть больше 0" << endl;
    }
    else {
        int result = sumOfSeries(n);
        cout << "Сумма ряда S = 5 + 10 + 15 + … + 5·n при n = " << n << " равна " << result << endl;
    }

    return 0;
}
