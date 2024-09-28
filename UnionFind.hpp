#pragma once

#include <vector>
#include <numeric>

class UnionFind {
    std::vector<int> p, s;
public:
    UnionFind(int n) {
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
        s.assign(n, 1);
    }

    int find(int x) {
        if (p[x] == x) {
            return x;
        }
        p[x] = find(p[x]);
        return p[x];
    }

    int size(int x) {
        return s[find(x)];
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (s[x] > s[y]) {
            std::swap(x, y);
        }
        s[y] += s[x];
        p[x] = y;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};