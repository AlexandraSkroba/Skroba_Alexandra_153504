#include<iostream>
using namespace std;

int power(int x, int p) {
	switch (p) {
	case 0:
		return 1;
		break;
	default:
		return x * power(x, p - 1);
		break;
	}
}

int main() {
	int x, p;
	cout << "Enter x: "; cin >> x;
	cout << "\nEnter digree of x: "; cin >> p;

	cout << power(x, p) << endl;
	return 0;
}