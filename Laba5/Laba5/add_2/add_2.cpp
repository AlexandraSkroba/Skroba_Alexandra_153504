// ������������ 5, ������ �������������� 2 :/. ���������: ������ �.�.

#include<iostream>

unsigned long long calculations(unsigned long long x, unsigned long long y, unsigned long long n) {
	if (!y) return 1;
	if (y & 1) return (x * calculations((x * x) % n, y / 2, n)) % n;
	return calculations((x * x) % n, y / 2, n);
}

long main() {
	setlocale(LC_ALL, "rus");
	int cs = 1;
	long long int k = 1, n = 1, t = 1, res;

	while (k + n + t > 0) {
		std::cout << "������� ��� �����: ";
		do {
			std::cin >> k;
			if (k < 0 || k > pow(10, 19)) std::cout << "\n����� k ������ ���� ������ ���� � ������ ������ � ������������� �������\n";
		} while (k < 0 || k > pow(10, 19));
		do {
			std::cin >> n;
			if (n < 0 || n > pow(10, 19)) std::cout << "\n����� n ������ ���� ������ ���� � ������ ������ � ������������� �������\n";
		} while (n < 0 || n > pow(10, 19));
		do {
			std::cin >> t;
			if (t < 0 || t > 10) std::cout << "\n����� t ������ ���� ������ ���� � ������ ������ � ������������� �������\n";
		} while (t < 0 || t > 10);

		if (k == 0 && n == 0 && t == 0) break;

		int m = 1; for (int i = 0; i < t; i++) m *= 10;
		res = calculations(k % m, n, m);

		std::cout << "Case #" << cs++ << ": " << res << std::endl << std::endl;
	}

	return 0;
}