#include <iostream>
#include <cmath>

using namespace std;

bool prime(int n)
{
	// Проверка на отрицательные числа и 0, которые не являются простыми
	if (n <= 1) 
	{
		return false;
	}

	// Перебираем все числа от 2 до квадратного корня из n
	for (int i = 2; i <= sqrt(n); ++i) 
	{
		// Если n делится без остатка на i, то оно не является простым
		if (n % i == 0) 
		{
			return false;
		}
	}

	// Если ни одно из чисел от 2 до квадратного корня не поделит n без остатка, то оно простое
	return true;
}


bool superprime(int n)
{
	if (!prime(n)) return false;

	int k = 0;
	for (int i = 1; i < n; ++i)
	{
		if (prime(i))
		{
			k++;
		}
	}
	
	if (prime(k + 1))
		return true;
	else
		return false;
}

int main()
{
    system("chcp 1251");
	int a;
	cout << "Введите число " << ends; 
	cin >> a;
	if (superprime(a))
	{
		cout << "Число " <<  a << " является суперпростым" << endl;
	}
	else
	{
		cout << "Число " << a << " не является суперпростым" << endl;
	}
}
