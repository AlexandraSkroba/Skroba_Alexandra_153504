// Лабораторная 5, задача дополнительная 1 :/. Выполнена: Скроба А.П.

#include<iostream>

/* проверка на ввод */
long input() {
    while (true) {
        long double value;

        std::cin >> value;

        if (std::cin.fail() || value - (long int)value != 0) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nОшибка\nВведите целое натуральное число - ";
        }
        else {
            std::cin.ignore(32767, '\n');
            return value;
        }
    }
}

long compute(long p) {
    long n = p % 10;
    if (p == 0) return 0;
    return n * (1 + n) / 2 + p / 10 * 45 + compute(p / 10);
}

long sum(long p, long q) {
    return compute(q) - compute(p - 1);
}

long main() {
    setlocale(LC_ALL, "rus");
    int p, q;
    
    std::cout << "Введите два целых положительных числа(p и q, где p <= q) и два отрицательных если хотите завершить программу: \n";
	while (true) {
        do {
            p = input();
            q = input();
            if ((p < 0 && q >= 0) || (q < 0 && p >= 0) || (p > q)) std::cout << "\nОба числа должны быть положительными (или отрицательными, если вы хотите выйти из программы)\nИ p должно быть меньше или равняться q\n";
        } while ((p < 0 && q >= 0) || (q < 0 && p >= 0) || (p > q));
        if (p < 0 && q < 0) break;

        compute(p);
        std::cout << "Результат вычислений = " << sum(p, q) << std::endl;
	}

	return 0;
}