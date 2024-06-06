#include <iostream>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251");

	string snils;
	cout << "Введите номер СНИЛС: " << ends;
	cin >> snils;
	
	bool l = true;

	if (snils.length() != 11)
		l = false;

	if (l == true)
	{
		for (int i = 2; i < snils.length() - 2; ++i) 
		{
			// Проверяем, что текущий символ равен предыдущему и символ перед ним тоже равен
			if (snils[i] == snils[i - 1] && snils[i] == snils[i - 2]) 
			{
				l = false; // Если найдены более двух одинаковых символов рядом, возвращаем false
			}
		}
	}
	
	int sum = 0, j = 9;

	if (l == true)
	{
		// Вычисление контрольного числа
		for (int i = 0; i < snils.length() - 2; ++i)
		{
			int s = snils[i] - '0';
			sum = sum + (s) * j;
			--j;
		}

		// Проверка контрольного числа
		if (sum < 100) {
			if (sum == (snils[9] - '0') * 10 + (snils[10] - '0'))
				l = true;
			else 
				l = false;
		}
		else {
			int remainder = sum % 101;
			if ((remainder < 100) && (remainder == (snils[9] - '0') * 10 + (snils[10] - '0')))
				l = true;
			else 
				l = false;
		}
	}
	if (l == true)
		cout << "СНИЛС валиден" << endl;
	else
		cout << "СНИЛС невалиден" << endl;
}
