#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
	system("chcp 1251");

	const int N = 10;
	int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
	int original[N]; // Создаем массив для хранения начального массива
	int min = 0; // для записи минимального значения
	int buf = 0; // для обмена значениями

	// Копируем исходный массив в массив original
	for (int i = 0; i < N; i++) 
	{
		original[i] = a[i];
	}

	for (int i = 0; i < N; i++)
	{
		min = i; // номер текущей ячейки, как ячейки с минимальным значением
		// в цикле найдем реальный номер ячейки с минимальным значением
		for (int j = i + 1; j < N; j++)
			min = (a[j] < a[min]) ? j : min;
		// перестановка этого элемента, поменяв его местами с текущим
		if (i != min)
		{
			buf = a[i];
			a[i] = a[min];
			a[min] = buf;
		}
	}

	// Открываем файл для записи
	ofstream out("arrays.txt");

	if (out.is_open()) {
		out << "Исходный массив: ";
		for (int i = 0; i < N; i++) {
			out << original[i] << " ";
		}
		out << endl;

		out << "Отсортированный массив: ";
		for (int i = 0; i < N; i++) {
			out << a[i] << " ";
		}
		out << endl;

		out.close();
		cout << "Массивы успешно записаны в файл 'arrays.txt'" << endl;
	}
	else {
		cout << "Ошибка открытия файла." << endl;
	}

	return 0;
}