#pragma once

template <const int M>
class ModInt {
    int x;
    static int Mod;
public:
    ModInt() : x{0} {
    }

    ModInt(const int64_t& v) {
        x = (int) (v % getMod());
        if (x < 0) {
            x += getMod();
        }
    }

    constexpr static int getMod() {
        if (M > 0) {
            return M;
        }
        return Mod;
    }

    constexpr static void setMod(int _Mod) {
        Mod = _Mod;
    }

    friend constexpr std::ostream& operator<<(std::ostream& os, const ModInt& m) {
        os << m.x;
        return os;
    }

    constexpr ModInt& operator+=(const ModInt& other) {
        x += other.x;
        if (x >= getMod()) {
            x -= getMod();
        }
        return *this;
    }

    constexpr ModInt& operator-=(const ModInt& other) {
        x -= other.x;
        if (x < 0) {
            x += getMod();
        }
        return *this;
    }

    constexpr ModInt& operator*=(const ModInt& other) {
        int64_t prod = ((int64_t) x * other.x) % getMod();
        x = (int) prod;
        return *this;
    }

    constexpr ModInt& operator/=(const ModInt& other) {
        return (*this) *= inv(other);
    }

    friend constexpr ModInt operator+(ModInt a, const ModInt& b) {
        return a += b;
    }

    friend constexpr ModInt operator-(ModInt a, const ModInt& b) {
        return a -= b;
    }

    friend constexpr ModInt operator*(ModInt a, const ModInt& b) {
        return a *= b;
    }

    friend constexpr ModInt operator/(ModInt a, const ModInt& b) {
        return a /= b;
    }

    friend constexpr ModInt modPow(ModInt m, long long p) {
        ModInt ans = 1;
        for (; p; p >>= 1, m *= m) {
            if (p & 1) {
                ans *= m;
            }
        }
        return ans;
    }

    friend constexpr ModInt inv(const ModInt& m) {
        return modPow(m, getMod() - 2);
    }

    constexpr ModInt& operator++() {
        x++;
        if (x == getMod()) {
            x = 0;
        }
        return *this;
    }

    constexpr ModInt& operator--() {
        if (x == 0) {
            x = getMod();
        }
        x--;
        return *this;
    }

    friend constexpr ModInt operator++(ModInt& m, int) {
        ModInt other = m;
        ++m;
        return other;
    }

    friend constexpr ModInt operator--(ModInt& m, int) {
        ModInt other = m;
        --m;
        return other;
    }

    friend constexpr bool operator==(const ModInt& l, const ModInt& r) {
        return l.x == r.x;
    }

    friend constexpr bool operator!=(const ModInt& l, const ModInt& r) {
        return !(l == r);
    }

    constexpr operator int() const {
        return x;
    }
};

template <>
int ModInt<0>::Mod = 1000000007;