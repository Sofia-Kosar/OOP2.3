#include "LongLong.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    LongLong a, b;

    // �������� � ���������
    cout << "Enter values for a:" << endl;
    cin >> a;
    cout << "Enter values for b:" << endl;
    cin >> b;

    // ���� �� �����
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    // ��������� �� ��������
    LongLong sum = a + b; // ������������� �������� ���������
    LongLong product = a * b; // ������������� �������� ��������
    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    // ���������� ���� �� ������������ ����������/����������
    string strSum = sum;
    cout << "Sum as string: " << strSum << endl;

    LongLong c = sum++;
    cout << "Sum++: " << c << endl;
    cout << "After increment: " << sum << endl;

    c = sum--;
    cout << "Sum--: " << c << endl;
    cout << "After decrement: " << sum << endl;

    // �������� ���������
    cout << "Comparison: " << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a <= b: " << (a <= b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a >= b: " << (a >= b) << endl;

    return 0;
}
