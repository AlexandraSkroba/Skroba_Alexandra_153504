// ������������ 5, ������ �������������� 3 :/. ���������: ������ �.�.

/* ����� f(n) - ���������� �������� �������� ������������ ����� n. 
�� ��������� ������������ n ���������� ��������� �������� ����� f(1) + f(2) + ... + f(n) */

#include<iostream>

/* �������� �� ���� */
long input() {
    while (true) {
        long double value;

        std::cin >> value;

        if (std::cin.fail() || value < 1 || value - (long int)value != 0) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\n������\n������� ����� ����������� ����� - ";
        }
        else {
            std::cin.ignore(32767, '\n');
            return value;
        }
    }
}

long function(long n) {
    long long k = (n + 1) / 2;
    if (n == 0) return 0;
    return k * k + function(n / 2);
}

long main() {
    setlocale(LC_ALL, "rus");

	long long n;
	std::cout << "��������� ������� �������� ����� f(1) + f(2) + ... + f(n) �� ��������� ������������ n.";
	std::cout << "\n������� ����� n - ";
    n = input();

    std::cout << "\nf(1) + f(2) + ... + f(" << n << ") = " << function(n) << std::endl;

	return 0;
}