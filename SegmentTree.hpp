#pragma once

#include <vector>

template <typename T>
class SegmentTree {
    int n;
    std::vector<T> tree;
public:
    SegmentTree() : n(0) {
    }

    SegmentTree(int _n) : n(_n) {
        tree.assign(4 * n, T());
    }

    template <typename K>
    SegmentTree(const std::vector<K>& base) {
        int _n = (int) base.size();
        n = _n;
        tree.assign(4 * n, T());
        build(1, 0, n, base);
    }

    template <typename K>
    void build(int v, int l, int r, const std::vector<K>& base) {
        if (r - l == 1) {
            tree[v] = (T) base[l];
            return;
        }
        int m = (l + r) >> 1;
        build(2 * v, l, m, base);
        build(2 * v + 1, m, r, base);
        pull(v);
    }

    void pull(int v) {
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }

    void update(int v, int l, int r, int p, T val) {
        if (r - l == 1) {
            tree[v] = val;
            return;
        }
        int m = (l + r) >> 1;
        if (p < m) {
            update(2 * v, l, m, p, val);
        } else {
            update(2 * v + 1, m, r, p, val);
        }
        pull(v);
    }

    void update(int p, T val) {
        update(1, 0, n, p, val);
    }

    T query(int v, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[v];
        }
        int m = (l + r) >> 1;
        if (qr <= m) {
            return query(2 * v, l, m, ql, qr);
        } else if (ql >= m) {
            return query(2 * v + 1, m, r, ql, qr);
        }
        return combine(query(2 * v, l, m, ql, qr), query(2 * v + 1, m, r, ql, qr));
    }

    T query(int ql, int qr) {
        return query(1, 0, n, ql, qr);
    }

    T queryInclusive(int ql, int qr) {
        return query(ql, qr + 1);
    }

    // Modify
    T combine(const T a, const T b) {
        return a + b;
    }
};