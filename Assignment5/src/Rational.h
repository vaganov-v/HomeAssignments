/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 5
 */

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <numeric>
#include <stdexcept>

class Rational {
public:
    Rational(long num = 0, long den = 1);

    long getNumerator() const;
    long getDenominator() const;

    Rational& operator+=(const Rational& other);
    Rational& operator*=(const Rational& other);

    friend Rational operator+(Rational a, const Rational& b);
    friend Rational operator*(Rational a, const Rational& b);
    friend bool operator==(const Rational& a, const Rational& b);
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);

private:
    long numerator_;
    long denominator_;

    void normalize();
};

#endif
