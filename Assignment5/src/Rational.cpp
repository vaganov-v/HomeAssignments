/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 5
 */

#include "Rational.h"
#include <numeric>

Rational::Rational(long num, long den)
    : numerator_(num), denominator_(den) {
    if (denominator_ == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    if (denominator_ < 0) {
        numerator_ = -numerator_;
        denominator_ = -denominator_;
    }
    normalize();
}

long Rational::getNumerator() const { return numerator_; }
long Rational::getDenominator() const { return denominator_; }

Rational& Rational::operator+=(const Rational& other) {
    numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_;
    denominator_ *= other.denominator_;
    normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    numerator_ *= other.numerator_;
    denominator_ *= other.denominator_;
    normalize();
    return *this;
}

Rational operator+(Rational a, const Rational& b) {
    a += b;
    return a;
}

Rational operator*(Rational a, const Rational& b) {
    a *= b;
    return a;
}

bool operator==(const Rational& a, const Rational& b) {
    return a.numerator_ == b.numerator_ && a.denominator_ == b.denominator_;
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.numerator_ << "/" << r.denominator_;
    return os;
}

void Rational::normalize() {
    if (numerator_ == 0) {
        denominator_ = 1;
        return;
    }
    long g = std::gcd(std::abs(numerator_), std::abs(denominator_));
    numerator_ /= g;
    denominator_ /= g;
}
