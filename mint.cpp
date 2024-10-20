template <unsigned int mod = M>
struct mint {
    unsigned int x;
 
    mint() : x(0) {}
 
    mint(long long _x) {
        _x %= mod;
        if (_x < 0) _x += mod;
        x = _x;
    }
 
    mint& operator+=(const mint& a) {
        x += a.x;
        if (x >= mod) x -= mod;
        return *this;
    }
 
    mint& operator-=(const mint& a) {
        x += mod - a.x;
        if (x >= mod) x -= mod;
        return *this;
    }
 
    mint& operator*=(const mint& a) {
        x = (long long)x * a.x % mod;
        return *this;
    }
 
    mint pow(long long pw) const {
        mint res = 1;
        mint cur = *this;
        while (pw) {
            if (pw & 1) res *= cur;
            cur *= cur;
            pw >>= 1;
        }
        return res;
    }
 
    mint inv() const {
        assert(x != 0);
        unsigned int t = x;
        unsigned int res = 1;
        while (t != 1) {
            unsigned int Mint = mod / t;
            res = (long long)res * (mod - Mint) % mod;
            t = mod - t * Mint;
        }
        return res;
    }
 
    mint& operator/=(const mint& a) {
        return *this *= a.inv();
    }
 
    mint operator+(const mint& a) const {
        return mint(*this) += a;
    }
 
    mint operator-(const mint& a) const {
        return mint(*this) -= a;
    }
 
    mint operator*(const mint& a) const {
        return mint(*this) *= a;
    }
 
    mint operator/(const mint& a) const {
        return mint(*this) /= a;
    }
 
    bool operator==(const mint& a) const {
        return x == a.x;
    }
 
    bool operator!=(const mint& a) const {
        return x != a.x;
    }
 
    bool operator<(const mint& a) const {
        return x < a.x;
    }
 
    friend ostream& operator<<(std::ostream& os, mint const& a) {
        return os << a.x;
    }
 
    friend istream& operator>>(istream& is, mint& a) {
        long long _x;
        is >> _x;
        a = mint(_x);
        return is;
    }
};
