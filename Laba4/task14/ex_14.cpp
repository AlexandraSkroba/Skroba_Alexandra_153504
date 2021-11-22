// ������������ 4, ������ 14. ���������: ������ �.�.

/* �� ���� ������� ���� ��� ���� � "����" �������� n*m ��������, ��� ������ '.' �������� ������ �����, � ������ '*' - �����.
��������� ��������� ��� ���� ������� , ��� � ������������ ����. ��������� ������ ����� ������� ����� �. */

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    long long n, m;
    short k;

    cout << "������ �������� ���� - ";
    cin >> n;
    while (cin.fail() || cin.peek() != '\n' || n != (long long)n || n <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "������� ������������ ������, ���������� ��� ���:\n";
        cin >> n;
    }

    cout << "������� ����� �������� ���� - ";
    cin >> m;
    while (cin.fail() || cin.peek() != '\n' || m != (long long)m || m <= 0) {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "������� ������������ ������, ���������� ��� ���:\n";
        cin >> m;
    }
    // ���������� �������
    char** arr = (char**)malloc(n * sizeof(char*));
    for (long long int i = 0; i < n; ++i) {
        arr[i] = (char*)malloc(m * sizeof(char));
    }

    cout << "��������� ������� ����(\".\" - ������ �����; \"*\" - �����): \n";
    for (long long int i = 0; i < n; ++i) {
        for (long long int j = 0; j < m; ++j) {
            cout << "arr[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
            while (cin.fail() || cin.peek() != '\n' || arr[i][j] != '.' && arr[i][j] != '*') {
                cin.clear();
                cin.ignore(99999, '\n');
                cout << "������� ������������ ������, ���������� ��� ���:\n";
                cout << "arr[" << i << "][" << j << "] = ";
                cin >> arr[i][j];
            }
        }
    }

    cout << "\n�������� ������� ����:\n";
    for (long long int i = 0; i < n; ++i) {
        for (long long int j = 0; j < m; ++j) {
            cout << arr[i][j] << "\t";
        }
        cout << endl << endl;
    }
    // ������ ����� �� ����� (���-�� ���� ������ ������)
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
            k = 0;
            if (arr[i][j] == '.') {
                if (i - 1 > -1 && arr[i - 1][j] == '*') ++k;
                if (i + 1 < n && arr[i + 1][j] == '*') ++k;
                if (j - 1 > -1 && arr[i][j - 1] == '*') ++k;
                if (j + 1 < m && arr[i][j + 1] == '*') ++k;
                if (i - 1 > -1 && j - 1 > -1 && arr[i - 1][j - 1] == '*') ++k;
                if (i + 1 < n && j - 1 > -1 && arr[i + 1][j - 1] == '*') ++k;
                if (i - 1 > -1 && j + 1 < m && arr[i - 1][j + 1] == '*') ++k;
                if (i + 1 < n && j + 1 < m && arr[i + 1][j + 1] == '*') ++k;
                arr[i][j] = k + '0';
            }
        }
    }

   cout << "\n���� ����� ���������� ����:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << "\t";
        }

        cout << '\n' << endl;
    }
    // ������������ ������
    for (long long int i = 0; i < n; ++i) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}   