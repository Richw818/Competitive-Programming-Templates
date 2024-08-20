#pragma once

#include <vector>

#include "ModInt.hpp"

template <const int Mod>
class Comb {
    int sz;
    std::vector<ModInt<Mod>> _fac, _ifac;
public:
    Comb(int _n) : sz(_n) {
        init();
    }

    void init() {
        _fac.resize(sz + 1);
        _ifac.resize(sz + 1);
        _fac[0] = 1;
        for (int i = 1; i <= sz; i++) {
            _fac[i] = _fac[i - 1] * ModInt<Mod>(i);
        }
        _ifac[sz] = inv(_fac[sz]);
        for (int i = sz - 1; i >= 0; i--) {
            _ifac[i] = _ifac[i + 1] * ModInt<Mod>(i + 1);
        }
    }

    ModInt<Mod> fac(int n) {
        return _fac[n];
    }

    ModInt<Mod> ifac(int n) {
        return _ifac[n];
    }

    ModInt<Mod> binom(int n, int k) {
        if (n < 0 || k < 0 || n < k) {
            return ModInt<Mod>();
        }
        return _fac[n] * _ifac[k] * _ifac[n - k];
    }
};