// Лабораторная 4, задача 3. Выполнена: Скроба А.П.

/* Задан массив размером N на N, состоящий из 0 и 1.
Повернуть элементы массива на 90 градусов по часовой стрелке */

#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	// создание и объявление массива
	int rowCol;

	do {
		cout << "Введите размер массива: ";
		cin >> rowCol;

		if (rowCol < 0) cout << "Размер массива может быть только положительным и не равным нулю!" << endl;
	} while (rowCol < 0);

	int** arr = new int* [rowCol];
	for (int i = 0; i < rowCol; i++) {
		arr[i] = new int[rowCol];
	}

	int** mass = new int* [rowCol];
	for (int i = 0; i < rowCol; i++) {
		mass[i] = new int[rowCol];
	}

	/////////////////////////////////////////////////////////////////////

	for (int i = 0; i < rowCol; i++) {
		for (int j = 0; j < rowCol; j++) {
			arr[i][j] = rand() % 2;
		}
	}

	for (int i = 0; i < rowCol; i++) {
		for (int j = 0; j < rowCol; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}

	for (int i = 0; i < rowCol; i++) {
		for (int j = 0; j < rowCol; j++) {
			mass[i][rowCol - 1 - j] = arr[j][i];
		}
	}

	cout << "\nПеревёрнутый массив: " << endl;

	for (int i = 0; i < rowCol; i++) {
		for (int j = 0; j < rowCol; j++) {
			cout << mass[i][j] << '\t';
		}
		cout << endl;
	}

	for (int i = 0; i < rowCol; i++) {
		delete[] mass[i];
	}

	delete[] mass;

	for (int i = 0; i < rowCol; i++) {
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}