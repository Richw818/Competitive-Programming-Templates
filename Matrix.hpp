#pragma once

#include <array>

template <typename T, const int N>
class Matrix {
    std::array<std::array<T, N>, N> m{};
public:
    Matrix() {
    }

    Matrix(const std::array<std::array<T, N>, N>& _m) : m(_m) {
    }

    std::array<T, N>& operator[](int p) {
        return m[p];
    }

    Matrix operator*=(Matrix& other) {
        Matrix prod;
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    prod[i][j] += m[i][k] * other[k][j];
                }
            }
        }
        *this = prod;
        return *this;
    }

    Matrix operator*(Matrix& other) {
        Matrix prod;
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    prod[i][j] += m[i][k] * other[k][j];
                }
            }
        }
        return prod;
    }

    Matrix& operator^=(uint64_t p) {
        Matrix power, base(*this);
        for (int i = 0; i < N; i++) {
            power[i][i] = 1;
        }
        for (; p; p >>= 1) {
            if (p & 1) {
                power *= base;
            }
            base *= base;
        }
        *this = power;
        return *this;
    }

    Matrix operator^(uint64_t p) {
        Matrix power, base(*this);
        for (int i = 0; i < N; i++) {
            power[i][i] = 1;
        }
        for (; p; p >>= 1) {
            if (p & 1) {
                power *= base;
            }
            base *= base;
        }
        return power;
    }

    T at(int i, int j) {
        return m[i][j];
    }
};