#include <iostream>
using namespace std;

void sum_array(const int ARR[], const int N)
{
	int s = 0;
	for (int i = 0; i < N; i++)
	{
		s += ARR[i];
	}
	cout << "Сумма массива: " << s << endl;
}

void sort_array(int ARR[], const int N)
{
	int min = 0; // для записи минимального значения
	int buf = 0; // для обмена значениями

	for (int i = 0; i < N; i++)
	{
		min = i; // номер текущей ячейки, как ячейки с минимальным значением
		// в цикле найдем реальный номер ячейки с минимальным значением
		for (int j = i + 1; j < N; j++)
			min = (ARR[j] < ARR[min]) ? j : min;
		// перестановка этого элемента, поменяв его местами с текущим
		if (i != min)
		{
			buf = ARR[i];
			ARR[i] = ARR[min];
			ARR[min] = buf;
		}
	}
}

int main() {
	system("chcp 1251");
	const int n = 10;
	int mas[n] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
	sum_array(mas, n);
	sort_array(mas, n);
	cout << "Отсортированный массив: ";
	for (int i : mas)
		cout << i << " ";
}