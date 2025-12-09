/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 5
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <ostream>
#include <stdexcept>

template<size_t M, size_t N, typename T = double>
class Matrix {
public:
    Matrix() : data_(M * N, T{}) {}

    T& at(size_t i, size_t j) {
        if (i >= M || j >= N) throw std::out_of_range("Matrix index out of range");
        return data_[i * N + j];
    }

    const T& at(size_t i, size_t j) const {
        if (i >= M || j >= N) throw std::out_of_range("Matrix index out of range");
        return data_[i * N + j];
    }

    // Multiplying by a scalar
    template<typename U>
    Matrix<M, N, T> operator*(U scalar) const {
        Matrix<M, N, T> result;
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                result.at(i, j) = at(i, j) * static_cast<T>(scalar);
            }
        }
        return result;
    }

    // Summation
    Matrix<M, N, T> operator+(const Matrix<M, N, T>& other) const {
        Matrix<M, N, T> result;
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                result.at(i, j) = at(i, j) + other.at(i, j);
            }
        }
        return result;
    }

    // Multiplying matrix: MxP x PxN -> MxN
    template<size_t P>
    Matrix<M, P, T> operator*(const Matrix<N, P, T>& other) const {
        Matrix<M, P, T> result;
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < P; ++j) {
                T sum = T{};
                for (size_t k = 0; k < N; ++k) {
                    sum += at(i, k) * other.at(k, j);
                }
                result.at(i, j) = sum;
            }
        }
        return result;
    }

    // Transposition: MxN -> NxM
    Matrix<N, M, T> transpose() const {
        Matrix<N, M, T> result;
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                result.at(j, i) = at(i, j);
            }
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix<M, N, T>& m) {
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                os << m.at(i, j);
                if (j + 1 < N) os << " ";
            }
            os << "\n";
        }
        return os;
    }

private:
    std::vector<T> data_;
};

// Function for multiplying a scalar by a matrix
template<size_t M, size_t N, typename T, typename U>
Matrix<M, N, T> operator*(U scalar, const Matrix<M, N, T>& m) {
    return m * scalar;
}

#endif
