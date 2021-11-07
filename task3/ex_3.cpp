// ������������ 4, ������ 3. ���������: ������ �.�.

/* ����� ������ �������� N �� N, ��������� �� 0 � 1.
��������� �������� ������� �� 90 �������� �� ������� ������� */

#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	// �������� � ���������� �������
	int rowCol;

	do {
		cout << "������� ������ �������: ";
		cin >> rowCol;

		if (rowCol < 0) cout << "������ ������� ����� ���� ������ ������������� � �� ������ ����!" << endl;
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

	cout << "\n����������� ������: " << endl;

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