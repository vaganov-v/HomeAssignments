/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 5
 */

#include <gtest/gtest.h>
#include "../src/Matrix.h"
#include "../src/Rational.h"

// Tests for int
TEST(MatrixTest, IntAddition) {
    Matrix<2, 2, int> a;
    a.at(0, 0) = 1; a.at(0, 1) = 2;
    a.at(1, 0) = 3; a.at(1, 1) = 4;

    Matrix<2, 2, int> b;
    b.at(0, 0) = 5; b.at(0, 1) = 6;
    b.at(1, 0) = 7; b.at(1, 1) = 8;

    auto c = a + b;
    EXPECT_EQ(c.at(0, 0), 6);
    EXPECT_EQ(c.at(1, 1), 12);
}

TEST(MatrixTest, IntScalarMultiplication) {
    Matrix<2, 2, int> a;
    a.at(0, 0) = 2; a.at(1, 1) = 3;
    auto b = a * 2;
    EXPECT_EQ(b.at(0, 0), 4);
    EXPECT_EQ(b.at(1, 1), 6);
    auto c = 3 * a;
    EXPECT_EQ(c.at(0, 0), 6);
}

TEST(MatrixTest, IntMatrixMultiplication) {
    Matrix<2, 3, int> a;
    a.at(0, 0) = 1; a.at(0, 1) = 2; a.at(0, 2) = 3;
    a.at(1, 0) = 4; a.at(1, 1) = 5; a.at(1, 2) = 6;

    Matrix<3, 2, int> b;
    b.at(0, 0) = 7; b.at(0, 1) = 8;
    b.at(1, 0) = 9; b.at(1, 1) = 10;
    b.at(2, 0) = 11; b.at(2, 1) = 12;

    auto c = a * b;
    EXPECT_EQ(c.at(0, 0), 58);
    EXPECT_EQ(c.at(1, 1), 154);
}

TEST(MatrixTest, IntTranspose) {
    Matrix<2, 3, int> a;
    a.at(0, 0) = 1; a.at(0, 1) = 2; a.at(0, 2) = 3;
    a.at(1, 0) = 4; a.at(1, 1) = 5; a.at(1, 2) = 6;

    auto t = a.transpose();
    EXPECT_EQ(t.at(0, 0), 1);
    EXPECT_EQ(t.at(0, 1), 4);
    EXPECT_EQ(t.at(2, 0), 3);
    EXPECT_EQ(t.at(2, 1), 6);
}

// Tests for double
TEST(MatrixTest, DoubleOperations) {
    Matrix<2, 2, double> a;
    a.at(0, 0) = 1.5; a.at(1, 1) = 2.5;
    auto b = a * 2.0;
    EXPECT_DOUBLE_EQ(b.at(0, 0), 3.0);
    EXPECT_DOUBLE_EQ(b.at(1, 1), 5.0);
}

// Tests for Rational
TEST(RationalTest, Basic) {
    Rational r(2, 4);
    EXPECT_EQ(r.getNumerator(), 1);
    EXPECT_EQ(r.getDenominator(), 2);
}

TEST(MatrixTest, RationalMatrix) {
    Matrix<2, 2, Rational> a;
    a.at(0, 0) = Rational(1, 2);
    a.at(0, 1) = Rational(1, 3);
    a.at(1, 0) = Rational(1, 4);
    a.at(1, 1) = Rational(1, 5);

    auto b = a * Rational(6, 1);
    EXPECT_EQ(b.at(0, 0), Rational(3, 1)); // (1/2)*6 = 3
    EXPECT_EQ(b.at(0, 1), Rational(2, 1)); // (1/3)*6 = 2

    auto c = a + a;
    EXPECT_EQ(c.at(0, 0), Rational(1, 1)); // 1/2 + 1/2 = 1
}

TEST(MatrixTest, RationalTranspose) {
    Matrix<1, 2, Rational> a;
    a.at(0, 0) = Rational(3, 4);
    a.at(0, 1) = Rational(5, 6);
    auto t = a.transpose();
    EXPECT_EQ(t.at(0, 0), Rational(3, 4));
    EXPECT_EQ(t.at(1, 0), Rational(5, 6));
}
