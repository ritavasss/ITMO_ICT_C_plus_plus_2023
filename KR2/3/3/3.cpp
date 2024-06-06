#include <iostream>

using namespace std;

int main() {

    system("chcp 1251");
    int coins[] = { 10, 5, 2, 1 }; // Доступные номиналы монет
    int S; // Сумма, которую нужно выдать
    cout << "Введите необходимую сумму: ";
    cin >> S;

    int n = sizeof(coins) / sizeof(coins[0]); // Количество доступных монет

    cout << "Монеты, используемые для выдачи: ";

    for (int i = 0; i < n; i++) 
    {
        while (S >= coins[i]) 
        {
            cout << coins[i] << " ";
            S -= coins[i];
        }
    }
}
