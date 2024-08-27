#pragma once

#include <vector>

template <typename T>
class FenwickTree {
    int n;
    std::vector<T> tree;
public:
    FenwickTree(int _n) : n(_n) {
        tree.assign(n, T());
    }

    void update(int i, T upd) {
        for (; i < n; i |= (i + 1)) {
            tree[i] += upd;
        }
    }

    T query(int i) {
        T sum{};
        for (; i >= 0; i = (i & (i + 1)) - 1) {
            sum += tree[i];
        }
        return sum;
    }

    T query(int l, int r) {
        return query(r) - query(l - 1);
    }

    int find(const T& k) {
        int x = 0;
        for (int i = 1 << (31 - __builtin_clz(n)); i > 0; i >>= 1) {
            if (i + x <= n && k > tree[i + x - 1]) {
                x += i;
                k -= tree[x - 1];
            }
        }
        return x;
    }
};