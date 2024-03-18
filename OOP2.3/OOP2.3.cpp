#include "LongLong.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    LongLong a, b;

    // Введення з клавіатури
    cout << "Enter values for a:" << endl;
    cin >> a;
    cout << "Enter values for b:" << endl;
    cin >> b;

    // Вивід на екран
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    // Додавання та множення
    LongLong sum = a + b; // Використовуємо оператор додавання
    LongLong product = a * b; // Використовуємо оператор множення
    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    // Приведення типу та демонстрація інкременту/декременту
    string strSum = sum;
    cout << "Sum as string: " << strSum << endl;

    LongLong c = sum++;
    cout << "Sum++: " << c << endl;
    cout << "After increment: " << sum << endl;

    c = sum--;
    cout << "Sum--: " << c << endl;
    cout << "After decrement: " << sum << endl;

    // Операції порівняння
    cout << "Comparison: " << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a <= b: " << (a <= b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a >= b: " << (a >= b) << endl;

    return 0;
}
