#pragma once

#include <array>
#include <vector>

template <typename T, const int D>
class Tensor {
    std::array<int, D> shape;
    std::array<int, D> strides;
    std::vector<T> data;
    
    static_assert(D > 0);
public:
    Tensor(const std::array<int, D>& _shape) : shape(_shape) {
        int x = 1;
        for (int i = D - 1; i >= 0; i--) {
            strides[i] = x;
            x *= shape[i];
        }
        data.assign(x, T());
    }
 
    int find(const std::array<int, D>& idx) {
        int pos = 0;
        for (int i = 0; i < D; i++) {
            pos += strides[i] * idx[i];
        }
        return pos;
    }
 
    T& operator[](const std::array<int, D>& idx) {
        return data[find(idx)];
    }
};