#include "LongLong.h"
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// ������������
LongLong::LongLong(unsigned long high, unsigned long low) : highPart(high), lowPart(low) {}

LongLong::LongLong(const LongLong& other) : highPart(other.highPart), lowPart(other.lowPart) {}

// ������ � ������ ��� ������ �������
unsigned long LongLong::getHighPart() const {
    return highPart;
}

void LongLong::setHighPart(unsigned long high) {
    highPart = high;
}

// ������ � ������ ��� ������� �������
unsigned long LongLong::getLowPart() const {
    return lowPart;
}

void LongLong::setLowPart(unsigned long low) {
    lowPart = low;
}

// �������� ���������
LongLong& LongLong::operator=(const LongLong& other) {
    if (this != &other) {
        highPart = other.highPart;
        lowPart = other.lowPart;
    }
    return *this;
}
// �������� ����� � ���������
istream& operator>>(istream& in, LongLong& ll) {
    cout << "Enter high part: ";
    in >> ll.highPart;
    cout << "Enter low part: ";
    in >> ll.lowPart;
    return in;
}
// �������� ������ �� �����
ostream& operator<<(ostream& out, const LongLong& ll) {
    out << "Number: " << ll.highPart * 10000 + ll.lowPart;
    return out;
}

// �������� ���������� ���� � ������������ � ������� �����
LongLong::operator string() const {
    stringstream ss;
    ss << highPart << " " << lowPart;
    return ss.str();
}

// �������� ���������� (����������)
LongLong& LongLong::operator++() {
    if (++lowPart == 0)
        ++highPart;
    return *this;
}

// �������� ���������� (�����������)
LongLong LongLong::operator++(int) {
    LongLong temp(*this);
    ++(*this);
    return temp;
}

// �������� ���������� (����������)
LongLong& LongLong::operator--() {
    if (lowPart-- == 0)
        --highPart;
    return *this;
}

// �������� ���������� (�����������)
LongLong LongLong::operator--(int) {
    LongLong temp(*this);
    --(*this);
    return temp;
}
LongLong LongLong::operator+(const LongLong& other) const {
    unsigned long sum_low = lowPart + other.lowPart;
    unsigned long sum_high = highPart + other.highPart;

    if (sum_low < lowPart) // ���� ���� �������� ������ �������� ����������� ��������
        sum_high++; // �������� ������ ������� �� 1

    return LongLong(sum_high, sum_low);
}
// �������� ��������
LongLong LongLong::operator*(const LongLong& other) const {
    // �������� ������ �� ������� ������� ���� �����
    unsigned long aLow = lowPart;
    unsigned long aHigh = highPart;
    unsigned long bLow = other.getLowPart();
    unsigned long bHigh = other.getHighPart();

    // ����������� ������ ����������
    unsigned long long res1 = static_cast<unsigned long long>(aLow) * bLow;
    unsigned long long res2 = static_cast<unsigned long long>(aLow) * bHigh;
    unsigned long long res3 = static_cast<unsigned long long>(aHigh) * bLow;

    // ���� ����������
    unsigned long long sum = res1 + (res2 << 32) + (res3 << 32);

    // �������� ������� �� ������ ������� ����������
    unsigned int resultLow = static_cast<unsigned int>(sum & 0xFFFFFFFF);
    unsigned int resultHigh = static_cast<unsigned int>((sum >> 32) & 0xFFFFFFFF);

    // ��������� ��������� � ������ LongLong
    return LongLong(resultHigh, resultLow);
}


// �������� ��������� ==
bool LongLong::operator==(const LongLong& other) const {
    return (highPart == other.highPart) && (lowPart == other.lowPart);
}

// �������� ��������� !=
bool LongLong::operator!=(const LongLong& other) const {
    return !(*this == other);
}

// �������� ��������� <
bool LongLong::operator<(const LongLong& other) const {
    return (highPart < other.highPart) || ((highPart == other.highPart) && (lowPart < other.lowPart));
}

// �������� ��������� <=
bool LongLong::operator<=(const LongLong& other) const {
    return (*this < other) || (*this == other);
}

// �������� ��������� >
bool LongLong::operator>(const LongLong& other) const {
    return !(*this <= other);
}

// �������� ��������� >=
bool LongLong::operator>=(const LongLong& other) const {
    return !(*this < other);
}
