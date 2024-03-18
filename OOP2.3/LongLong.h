#pragma once
#ifndef LONGLONG_H
#define LONGLONG_H

#include <iostream>
#include <string>
using namespace std;

class LongLong {
private:
    unsigned long highPart;
    unsigned long lowPart;

public:
    LongLong(unsigned long high = 0, unsigned long low = 0);
    LongLong(const LongLong& other);
    unsigned long getHighPart() const;
    void setHighPart(unsigned long high);
    unsigned long getLowPart() const;
    void setLowPart(unsigned long low);
    LongLong& operator=(const LongLong& other);
    friend std::istream& operator>>(std::istream& in, LongLong& ll);
    friend std::ostream& operator<<(std::ostream& out, const LongLong& ll);
    operator string() const;
    LongLong& operator++();
    LongLong operator++(int);
    LongLong& operator--();
    LongLong operator--(int);
    LongLong operator+(const LongLong& other) const; 
    LongLong operator*(const LongLong& other) const;
    bool operator==(const LongLong& other) const;
    bool operator!=(const LongLong& other) const;
    bool operator<(const LongLong& other) const;
    bool operator<=(const LongLong& other) const;
    bool operator>(const LongLong& other) const;
    bool operator>=(const LongLong& other) const;
};

#endif // LONGLONG_H
