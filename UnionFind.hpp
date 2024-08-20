#pragma once

#include <vector>
#include <numeric>

class UnionFind {
    std::vector<int> _p, _size;
public:
    UnionFind(int n) {
        _p.resize(n);
        std::iota(_p.begin(), _p.end(), 0);
        _size.assign(n, 1);
    }
    int find(int n) {
        if (_p[n] == n) {
            return n;
        }
        _p[n] = find(_p[n]);
        return _p[n];
    }
    int size(int n) {
        n = find(n);
        return _size[n];
    }
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (_size[a] > _size[b]) {
            std::swap(a, b);
        }
        _size[b] += _size[a];
        _p[a] = b;
        return true;
    }
};