#pragma once

#include <vector>

template <typename T, typename U>
class LazySegmentTree {
    int n;
    std::vector<T> tree;
    std::vector<U> lazy;
public:
    LazySegmentTree() : n(0) {
    }

    LazySegmentTree(int _n) : n(_n) {
        tree.assign(4 * n, T());
        lazy.assign(4 * n, U());
    }

    template <typename K>
    LazySegmentTree(const std::vector<K>& base) {
        int _n = (int) base.size();
        n = _n;
        tree.assign(4 * n, T());
        lazy.assign(4 * n, U());
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

    void update(int v, int l, int r, int ul, int ur, U upd) {
        if (ul <= l && r <= ur) {
            apply(v, l, r, upd);
            return;
        }
        push(v, l, r);
        int m = (l + r) >> 1;
        if (ul < m) {
            update(2 * v, l, m, ul, ur, upd);
        } 
        if (ur > m) {
            update(2 * v + 1, m, r, ul, ur, upd);
        }
        pull(v);
    }

    void update(int ul, int ur, U upd) {
        update(1, 0, n, ul, ur, upd);
    }

    void updateInclusive(int ul, int ur, U upd) {
        update(ul, ur + 1, upd);
    }

    T query(int v, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[v];
        }
        push(v, l, r);
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

    void apply(int v, int l, int r, U upd) {
        lazy[v] += upd;
        tree[v] += (r - l) * upd;
    }

    void push(int v, int l, int r) {
        if (true) {
            int m = (l + r) >> 1;
            apply(2 * v, l, m, lazy[v]);
            apply(2 * v + 1, m, r, lazy[v]);
        }
        lazy[v] = U();
    }
};