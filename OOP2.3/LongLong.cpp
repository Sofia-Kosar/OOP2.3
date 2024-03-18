#include "LongLong.h"
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// Конструктори
LongLong::LongLong(unsigned long high, unsigned long low) : highPart(high), lowPart(low) {}

LongLong::LongLong(const LongLong& other) : highPart(other.highPart), lowPart(other.lowPart) {}

// Гетери і сетери для старшої частини
unsigned long LongLong::getHighPart() const {
    return highPart;
}

void LongLong::setHighPart(unsigned long high) {
    highPart = high;
}

// Гетери і сетери для молодшої частини
unsigned long LongLong::getLowPart() const {
    return lowPart;
}

void LongLong::setLowPart(unsigned long low) {
    lowPart = low;
}

// Оператор присвоєння
LongLong& LongLong::operator=(const LongLong& other) {
    if (this != &other) {
        highPart = other.highPart;
        lowPart = other.lowPart;
    }
    return *this;
}
// Оператор вводу з клавіатури
istream& operator>>(istream& in, LongLong& ll) {
    cout << "Enter high part: ";
    in >> ll.highPart;
    cout << "Enter low part: ";
    in >> ll.lowPart;
    return in;
}
// Оператор виводу на екран
ostream& operator<<(ostream& out, const LongLong& ll) {
    out << "Number: " << ll.highPart * 10000 + ll.lowPart;
    return out;
}

// Оператор приведення типу – перетворення у літерний рядок
LongLong::operator string() const {
    stringstream ss;
    ss << highPart << " " << lowPart;
    return ss.str();
}

// Оператор інкременту (префіксний)
LongLong& LongLong::operator++() {
    if (++lowPart == 0)
        ++highPart;
    return *this;
}

// Оператор інкременту (постфіксний)
LongLong LongLong::operator++(int) {
    LongLong temp(*this);
    ++(*this);
    return temp;
}

// Оператор декременту (префіксний)
LongLong& LongLong::operator--() {
    if (lowPart-- == 0)
        --highPart;
    return *this;
}

// Оператор декременту (постфіксний)
LongLong LongLong::operator--(int) {
    LongLong temp(*this);
    --(*this);
    return temp;
}
LongLong LongLong::operator+(const LongLong& other) const {
    unsigned long sum_low = lowPart + other.lowPart;
    unsigned long sum_high = highPart + other.highPart;

    if (sum_low < lowPart) // Якщо сума молодших частин перевищує максимальне значення
        sum_high++; // Збільшуємо старшу частину на 1

    return LongLong(sum_high, sum_low);
}
// Оператор множення
LongLong LongLong::operator*(const LongLong& other) const {
    // Отримуємо старшу та молодшу частини обох чисел
    unsigned long aLow = lowPart;
    unsigned long aHigh = highPart;
    unsigned long bLow = other.getLowPart();
    unsigned long bHigh = other.getHighPart();

    // Розраховуємо проміжні результати
    unsigned long long res1 = static_cast<unsigned long long>(aLow) * bLow;
    unsigned long long res2 = static_cast<unsigned long long>(aLow) * bHigh;
    unsigned long long res3 = static_cast<unsigned long long>(aHigh) * bLow;

    // Сума результатів
    unsigned long long sum = res1 + (res2 << 32) + (res3 << 32);

    // Отримуємо молодшу та старшу частини результату
    unsigned int resultLow = static_cast<unsigned int>(sum & 0xFFFFFFFF);
    unsigned int resultHigh = static_cast<unsigned int>((sum >> 32) & 0xFFFFFFFF);

    // Повертаємо результат у форматі LongLong
    return LongLong(resultHigh, resultLow);
}


// Оператор порівняння ==
bool LongLong::operator==(const LongLong& other) const {
    return (highPart == other.highPart) && (lowPart == other.lowPart);
}

// Оператор порівняння !=
bool LongLong::operator!=(const LongLong& other) const {
    return !(*this == other);
}

// Оператор порівняння <
bool LongLong::operator<(const LongLong& other) const {
    return (highPart < other.highPart) || ((highPart == other.highPart) && (lowPart < other.lowPart));
}

// Оператор порівняння <=
bool LongLong::operator<=(const LongLong& other) const {
    return (*this < other) || (*this == other);
}

// Оператор порівняння >
bool LongLong::operator>(const LongLong& other) const {
    return !(*this <= other);
}

// Оператор порівняння >=
bool LongLong::operator>=(const LongLong& other) const {
    return !(*this < other);
}
