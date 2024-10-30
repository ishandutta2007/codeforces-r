#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep_(i, a_, b_, a, b, ...) for (int i = (a), lim##i = (b); i < lim##i; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define drep_(i, a_, b_, a, b, ...) for (int i = (a)-1, lim##i = (b); i >= lim##i; --i)
#define drep(i, ...) drep_(i, __VA_ARGS__, __VA_ARGS__, __VA_ARGS__, 0)
#define rrep(i,n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define rrep2(i,n,k) for(int (i)=(n)-1;(i)>=(n)-(k);(i)--)
#define vll(n,i) vector<long long>(n,i)
#define v2ll(n,m,i) vector<vector<long long>>(n,vll(m,i))
#define v3ll(n,m,k,i) vector<vector<vector<long long>>>(n,v2ll(m,k,i))
#define v4ll(n,m,k,l,i) vector<vector<vector<vector<long long>>>>(n,v3ll(m,k,l,i))
#define all(v) v.begin(),v.end()
#define chmin(k,m) k = min(k,m)
#define chmax(k,m) k = max(k,m)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

//ACL internal_math/type_traits/bit
namespace atcoder {

    namespace internal {

    // @param m `1 <= m`
    // @return x mod m
    constexpr long long safe_mod(long long x, long long m) {
        x %= m;
        if (x < 0) x += m;
        return x;
    }

    // Fast modular multiplication by barrett reduction
    // Reference: https://en.wikipedia.org/wiki/Barrett_reduction
    // NOTE: reconsider after Ice Lake
    struct barrett {
        unsigned int _m;
        unsigned long long im;

        // @param m `1 <= m < 2^31`
        explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

        // @return m
        unsigned int umod() const { return _m; }

        // @param a `0 <= a < m`
        // @param b `0 <= b < m`
        // @return `a * b % m`
        unsigned int mul(unsigned int a, unsigned int b) const {
            // [1] m = 1
            // a = b = im = 0, so okay

            // [2] m >= 2
            // im = ceil(2^64 / m)
            // -> im * m = 2^64 + r (0 <= r < m)
            // let z = a*b = c*m + d (0 <= c, d < m)
            // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im
            // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) < 2^64 * 2
            // ((ab * im) >> 64) == c or c + 1
            unsigned long long z = a;
            z *= b;
    #ifdef _MSC_VER
            unsigned long long x;
            _umul128(z, im, &x);
    #else
            unsigned long long x =
                (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
    #endif
            unsigned int v = (unsigned int)(z - x * _m);
            if (_m <= v) v += _m;
            return v;
        }
    };

    // @param n `0 <= n`
    // @param m `1 <= m`
    // @return `(x ** n) % m`
    constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
        if (m == 1) return 0;
        unsigned int _m = (unsigned int)(m);
        unsigned long long r = 1;
        unsigned long long y = safe_mod(x, m);
        while (n) {
            if (n & 1) r = (r * y) % _m;
            y = (y * y) % _m;
            n >>= 1;
        }
        return r;
    }

    // Reference:
    // M. Forisek and J. Jancina,
    // Fast Primality Testing for Integers That Fit into a Machine Word
    // @param n `0 <= n`
    constexpr bool is_prime_constexpr(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 7 || n == 61) return true;
        if (n % 2 == 0) return false;
        long long d = n - 1;
        while (d % 2 == 0) d /= 2;
        constexpr long long bases[3] = {2, 7, 61};
        for (long long a : bases) {
            long long t = d;
            long long y = pow_mod_constexpr(a, t, n);
            while (t != n - 1 && y != 1 && y != n - 1) {
                y = y * y % n;
                t <<= 1;
            }
            if (y != n - 1 && t % 2 == 0) {
                return false;
            }
        }
        return true;
    }
    template <int n> constexpr bool is_prime = is_prime_constexpr(n);

    // @param b `1 <= b`
    // @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
    constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
        a = safe_mod(a, b);
        if (a == 0) return {b, 0};

        // Contracts:
        // [1] s - m0 * a = 0 (mod b)
        // [2] t - m1 * a = 0 (mod b)
        // [3] s * |m1| + t * |m0| <= b
        long long s = b, t = a;
        long long m0 = 0, m1 = 1;

        while (t) {
            long long u = s / t;
            s -= t * u;
            m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

            // [3]:
            // (s - t * u) * |m1| + t * |m0 - m1 * u|
            // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
            // = s * |m1| + t * |m0| <= b

            auto tmp = s;
            s = t;
            t = tmp;
            tmp = m0;
            m0 = m1;
            m1 = tmp;
        }
        // by [3]: |m0| <= b/g
        // by g != b: |m0| < b/g
        if (m0 < 0) m0 += b / s;
        return {s, m0};
    }

    // Compile time primitive root
    // @param m must be prime
    // @return primitive root (and minimum in now)
    constexpr int primitive_root_constexpr(int m) {
        if (m == 2) return 1;
        if (m == 167772161) return 3;
        if (m == 469762049) return 3;
        if (m == 754974721) return 11;
        if (m == 998244353) return 3;
        int divs[20] = {};
        divs[0] = 2;
        int cnt = 1;
        int x = (m - 1) / 2;
        while (x % 2 == 0) x /= 2;
        for (int i = 3; (long long)(i)*i <= x; i += 2) {
            if (x % i == 0) {
                divs[cnt++] = i;
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1) {
            divs[cnt++] = x;
        }
        for (int g = 2;; g++) {
            bool ok = true;
            for (int i = 0; i < cnt; i++) {
                if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) return g;
        }
    }
    template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

    // @param n `n < 2^32`
    // @param m `1 <= m < 2^32`
    // @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)
    unsigned long long floor_sum_unsigned(unsigned long long n,
                                        unsigned long long m,
                                        unsigned long long a,
                                        unsigned long long b) {
        unsigned long long ans = 0;
        while (true) {
            if (a >= m) {
                ans += n * (n - 1) / 2 * (a / m);
                a %= m;
            }
            if (b >= m) {
                ans += n * (b / m);
                b %= m;
            }

            unsigned long long y_max = a * n + b;
            if (y_max < m) break;
            // y_max < m * (n + 1)
            // floor(y_max / m) <= n
            n = (unsigned long long)(y_max / m);
            b = (unsigned long long)(y_max % m);
            std::swap(m, a);
        }
        return ans;
    }

    }  // namespace internal

}  // namespace atcoder
namespace atcoder {

    namespace internal {

    #ifndef _MSC_VER
    template <class T>
    using is_signed_int128 =
        typename std::conditional<std::is_same<T, __int128_t>::value ||
                                    std::is_same<T, __int128>::value,
                                std::true_type,
                                std::false_type>::type;

    template <class T>
    using is_unsigned_int128 =
        typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                    std::is_same<T, unsigned __int128>::value,
                                std::true_type,
                                std::false_type>::type;

    template <class T>
    using make_unsigned_int128 =
        typename std::conditional<std::is_same<T, __int128_t>::value,
                                __uint128_t,
                                unsigned __int128>;

    template <class T>
    using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                    is_signed_int128<T>::value ||
                                                    is_unsigned_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

    template <class T>
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                    std::is_signed<T>::value) ||
                                                        is_signed_int128<T>::value,
                                                    std::true_type,
                                                    std::false_type>::type;

    template <class T>
    using is_unsigned_int =
        typename std::conditional<(is_integral<T>::value &&
                                std::is_unsigned<T>::value) ||
                                    is_unsigned_int128<T>::value,
                                std::true_type,
                                std::false_type>::type;

    template <class T>
    using to_unsigned = typename std::conditional<
        is_signed_int128<T>::value,
        make_unsigned_int128<T>,
        typename std::conditional<std::is_signed<T>::value,
                                std::make_unsigned<T>,
                                std::common_type<T>>::type>::type;

    #else

    template <class T> using is_integral = typename std::is_integral<T>;

    template <class T>
    using is_signed_int =
        typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                                std::true_type,
                                std::false_type>::type;

    template <class T>
    using is_unsigned_int =
        typename std::conditional<is_integral<T>::value &&
                                    std::is_unsigned<T>::value,
                                std::true_type,
                                std::false_type>::type;

    template <class T>
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                                std::make_unsigned<T>,
                                                std::common_type<T>>::type;

    #endif

    template <class T>
    using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

    template <class T>
    using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

    template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

    }  // namespace internal

}  // namespace atcoder
namespace atcoder {

    namespace internal {

    // @param n `0 <= n`
    // @return minimum non-negative `x` s.t. `n <= 2**x`
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }

    // @param n `1 <= n`
    // @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
    constexpr int bsf_constexpr(unsigned int n) {
        int x = 0;
        while (!(n & (1 << x))) x++;
        return x;
    }

    // @param n `1 <= n`
    // @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
    int bsf(unsigned int n) {
    #ifdef _MSC_VER
        unsigned long index;
        _BitScanForward(&index, n);
        return index;
    #else
        return __builtin_ctz(n);
    #endif
    }

    }  // namespace internal

}  // namespace atcoder

//ACL modint
namespace atcoder {

    namespace internal {

        struct modint_base {};
        struct static_modint_base : modint_base {};

        template <class T> using is_modint = std::is_base_of<modint_base, T>;
        template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

    }  // namespace internal

    template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
    struct static_modint : internal::static_modint_base {
        using mint = static_modint;

    public:
        static constexpr int mod() { return m; }
        static mint raw(int v) {
            mint x;
            x._v = v;
            return x;
        }

        static_modint() : _v(0) {}
        template <class T, internal::is_signed_int_t<T>* = nullptr>
        static_modint(T v) {
            long long x = (long long)(v % (long long)(umod()));
            if (x < 0) x += umod();
            _v = (unsigned int)(x);
        }
        template <class T, internal::is_unsigned_int_t<T>* = nullptr>
        static_modint(T v) {
            _v = (unsigned int)(v % umod());
        }

        unsigned int val() const { return _v; }

        mint& operator++() {
            _v++;
            if (_v == umod()) _v = 0;
            return *this;
        }
        mint& operator--() {
            if (_v == 0) _v = umod();
            _v--;
            return *this;
        }
        mint operator++(int) {
            mint result = *this;
            ++*this;
            return result;
        }
        mint operator--(int) {
            mint result = *this;
            --*this;
            return result;
        }

        mint& operator+=(const mint& rhs) {
            _v += rhs._v;
            if (_v >= umod()) _v -= umod();
            return *this;
        }
        mint& operator-=(const mint& rhs) {
            _v -= rhs._v;
            if (_v >= umod()) _v += umod();
            return *this;
        }
        mint& operator*=(const mint& rhs) {
            unsigned long long z = _v;
            z *= rhs._v;
            _v = (unsigned int)(z % umod());
            return *this;
        }
        mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

        mint operator+() const { return *this; }
        mint operator-() const { return mint() - *this; }

        mint pow(long long n) const {
            assert(0 <= n);
            mint x = *this, r = 1;
            while (n) {
                if (n & 1) r *= x;
                x *= x;
                n >>= 1;
            }
            return r;
        }
        mint inv() const {
            if (prime) {
                assert(_v);
                return pow(umod() - 2);
            } else {
                auto eg = internal::inv_gcd(_v, m);
                assert(eg.first == 1);
                return eg.second;
            }
        }

        friend mint operator+(const mint& lhs, const mint& rhs) {
            return mint(lhs) += rhs;
        }
        friend mint operator-(const mint& lhs, const mint& rhs) {
            return mint(lhs) -= rhs;
        }
        friend mint operator*(const mint& lhs, const mint& rhs) {
            return mint(lhs) *= rhs;
        }
        friend mint operator/(const mint& lhs, const mint& rhs) {
            return mint(lhs) /= rhs;
        }
        friend bool operator==(const mint& lhs, const mint& rhs) {
            return lhs._v == rhs._v;
        }
        friend bool operator!=(const mint& lhs, const mint& rhs) {
            return lhs._v != rhs._v;
        }
        friend constexpr ostream &operator<<(ostream& os,const mint &x) noexcept{
            return os<<(x._v);
        }
        friend constexpr istream &operator>>(istream& is,mint& x) noexcept{
            uint64_t t;
            is>>t,x=mint(t);
            return is;
        }

    private:
        unsigned int _v;
        static constexpr unsigned int umod() { return m; }
        static constexpr bool prime = internal::is_prime<m>;
    };


    template <int id> struct dynamic_modint : internal::modint_base {
        using mint = dynamic_modint;

    public:
        static int mod() { return (int)(bt.umod()); }
        static void set_mod(int m) {
            assert(1 <= m);
            bt = internal::barrett(m);
        }
        static mint raw(int v) {
            mint x;
            x._v = v;
            return x;
        }

        dynamic_modint() : _v(0) {}
        template <class T, internal::is_signed_int_t<T>* = nullptr>
        dynamic_modint(T v) {
            long long x = (long long)(v % (long long)(mod()));
            if (x < 0) x += mod();
            _v = (unsigned int)(x);
        }
        template <class T, internal::is_unsigned_int_t<T>* = nullptr>
        dynamic_modint(T v) {
            _v = (unsigned int)(v % mod());
        }

        unsigned int val() const { return _v; }

        mint& operator++() {
            _v++;
            if (_v == umod()) _v = 0;
            return *this;
        }
        mint& operator--() {
            if (_v == 0) _v = umod();
            _v--;
            return *this;
        }
        mint operator++(int) {
            mint result = *this;
            ++*this;
            return result;
        }
        mint operator--(int) {
            mint result = *this;
            --*this;
            return result;
        }

        mint& operator+=(const mint& rhs) {
            _v += rhs._v;
            if (_v >= umod()) _v -= umod();
            return *this;
        }
        mint& operator-=(const mint& rhs) {
            _v += mod() - rhs._v;
            if (_v >= umod()) _v -= umod();
            return *this;
        }
        mint& operator*=(const mint& rhs) {
            _v = bt.mul(_v, rhs._v);
            return *this;
        }
        mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

        mint operator+() const { return *this; }
        mint operator-() const { return mint() - *this; }

        mint pow(long long n) const {
            assert(0 <= n);
            mint x = *this, r = 1;
            while (n) {
                if (n & 1) r *= x;
                x *= x;
                n >>= 1;
            }
            return r;
        }
        mint inv() const {
            auto eg = internal::inv_gcd(_v, mod());
            assert(eg.first == 1);
            return eg.second;
        }

        friend mint operator+(const mint& lhs, const mint& rhs) {
            return mint(lhs) += rhs;
        }
        friend mint operator-(const mint& lhs, const mint& rhs) {
            return mint(lhs) -= rhs;
        }
        friend mint operator*(const mint& lhs, const mint& rhs) {
            return mint(lhs) *= rhs;
        }
        friend mint operator/(const mint& lhs, const mint& rhs) {
            return mint(lhs) /= rhs;
        }
        friend bool operator==(const mint& lhs, const mint& rhs) {
            return lhs._v == rhs._v;
        }
        friend bool operator!=(const mint& lhs, const mint& rhs) {
            return lhs._v != rhs._v;
        }
        friend constexpr ostream &operator<<(ostream& os,const mint &x) noexcept{
            return os<<(x._v);
        }
        friend constexpr istream &operator>>(istream& is,mint& x) noexcept{
            uint64_t t;
            is>>t,x=mint(t);
            return is;
        }

    private:
        unsigned int _v;
        static internal::barrett bt;
        static unsigned int umod() { return bt.umod(); }
    };
    template <int id> internal::barrett dynamic_modint<id>::bt(998244353);

    using modint = dynamic_modint<-1>;

    namespace internal {

    template <class T>
    using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

    template <class T>
    using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

    template <class> struct is_dynamic_modint : public std::false_type {};
    template <int id>
    struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

    template <class T>
    using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

    }  // namespace internal

}  // namespace atcoder

//ACL convolution
namespace atcoder {

    namespace internal {

    template <class mint,
            int g = internal::primitive_root<mint::mod()>,
            internal::is_static_modint_t<mint>* = nullptr>
    struct fft_info {
        static constexpr int rank2 = bsf_constexpr(mint::mod() - 1);
        std::array<mint, rank2 + 1> root;   // root[i]^(2^i) == 1
        std::array<mint, rank2 + 1> iroot;  // root[i] * iroot[i] == 1

        std::array<mint, std::max(0, rank2 - 2 + 1)> rate2;
        std::array<mint, std::max(0, rank2 - 2 + 1)> irate2;

        std::array<mint, std::max(0, rank2 - 3 + 1)> rate3;
        std::array<mint, std::max(0, rank2 - 3 + 1)> irate3;

        fft_info() {
            root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);
            iroot[rank2] = root[rank2].inv();
            for (int i = rank2 - 1; i >= 0; i--) {
                root[i] = root[i + 1] * root[i + 1];
                iroot[i] = iroot[i + 1] * iroot[i + 1];
            }

            {
                mint prod = 1, iprod = 1;
                for (int i = 0; i <= rank2 - 2; i++) {
                    rate2[i] = root[i + 2] * prod;
                    irate2[i] = iroot[i + 2] * iprod;
                    prod *= iroot[i + 2];
                    iprod *= root[i + 2];
                }
            }
            {
                mint prod = 1, iprod = 1;
                for (int i = 0; i <= rank2 - 3; i++) {
                    rate3[i] = root[i + 3] * prod;
                    irate3[i] = iroot[i + 3] * iprod;
                    prod *= iroot[i + 3];
                    iprod *= root[i + 3];
                }
            }
        }
    };

    template <class mint, internal::is_static_modint_t<mint>* = nullptr>
    void butterfly(std::vector<mint>& a) {
        int n = int(a.size());
        int h = internal::ceil_pow2(n);

        static const fft_info<mint> info;

        int len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
        while (len < h) {
            if (h - len == 1) {
                int p = 1 << (h - len - 1);
                mint rot = 1;
                for (int s = 0; s < (1 << len); s++) {
                    int offset = s << (h - len);
                    for (int i = 0; i < p; i++) {
                        auto l = a[i + offset];
                        auto r = a[i + offset + p] * rot;
                        a[i + offset] = l + r;
                        a[i + offset + p] = l - r;
                    }
                    if (s + 1 != (1 << len))
                        rot *= info.rate2[bsf(~(unsigned int)(s))];
                }
                len++;
            } else {
                // 4-base
                int p = 1 << (h - len - 2);
                mint rot = 1, imag = info.root[2];
                for (int s = 0; s < (1 << len); s++) {
                    mint rot2 = rot * rot;
                    mint rot3 = rot2 * rot;
                    int offset = s << (h - len);
                    for (int i = 0; i < p; i++) {
                        auto mod2 = 1ULL * mint::mod() * mint::mod();
                        auto a0 = 1ULL * a[i + offset].val();
                        auto a1 = 1ULL * a[i + offset + p].val() * rot.val();
                        auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();
                        auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();
                        auto a1na3imag =
                            1ULL * mint(a1 + mod2 - a3).val() * imag.val();
                        auto na2 = mod2 - a2;
                        a[i + offset] = a0 + a2 + a1 + a3;
                        a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
                        a[i + offset + 2 * p] = a0 + na2 + a1na3imag;
                        a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);
                    }
                    if (s + 1 != (1 << len))
                        rot *= info.rate3[bsf(~(unsigned int)(s))];
                }
                len += 2;
            }
        }
    }

    template <class mint, internal::is_static_modint_t<mint>* = nullptr>
    void butterfly_inv(std::vector<mint>& a) {
        int n = int(a.size());
        int h = internal::ceil_pow2(n);

        static const fft_info<mint> info;

        int len = h;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
        while (len) {
            if (len == 1) {
                int p = 1 << (h - len);
                mint irot = 1;
                for (int s = 0; s < (1 << (len - 1)); s++) {
                    int offset = s << (h - len + 1);
                    for (int i = 0; i < p; i++) {
                        auto l = a[i + offset];
                        auto r = a[i + offset + p];
                        a[i + offset] = l + r;
                        a[i + offset + p] =
                            (unsigned long long)(mint::mod() + l.val() - r.val()) *
                            irot.val();
                        ;
                    }
                    if (s + 1 != (1 << (len - 1)))
                        irot *= info.irate2[bsf(~(unsigned int)(s))];
                }
                len--;
            } else {
                // 4-base
                int p = 1 << (h - len);
                mint irot = 1, iimag = info.iroot[2];
                for (int s = 0; s < (1 << (len - 2)); s++) {
                    mint irot2 = irot * irot;
                    mint irot3 = irot2 * irot;
                    int offset = s << (h - len + 2);
                    for (int i = 0; i < p; i++) {
                        auto a0 = 1ULL * a[i + offset + 0 * p].val();
                        auto a1 = 1ULL * a[i + offset + 1 * p].val();
                        auto a2 = 1ULL * a[i + offset + 2 * p].val();
                        auto a3 = 1ULL * a[i + offset + 3 * p].val();

                        auto a2na3iimag =
                            1ULL *
                            mint((mint::mod() + a2 - a3) * iimag.val()).val();

                        a[i + offset] = a0 + a1 + a2 + a3;
                        a[i + offset + 1 * p] =
                            (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();
                        a[i + offset + 2 * p] =
                            (a0 + a1 + (mint::mod() - a2) + (mint::mod() - a3)) *
                            irot2.val();
                        a[i + offset + 3 * p] =
                            (a0 + (mint::mod() - a1) + (mint::mod() - a2na3iimag)) *
                            irot3.val();
                    }
                    if (s + 1 != (1 << (len - 2)))
                        irot *= info.irate3[bsf(~(unsigned int)(s))];
                }
                len -= 2;
            }
        }
    }

    template <class mint, internal::is_static_modint_t<mint>* = nullptr>
    std::vector<mint> convolution_naive(const std::vector<mint>& a,
                                        const std::vector<mint>& b) {
        int n = int(a.size()), m = int(b.size());
        std::vector<mint> ans(n + m - 1);
        if (n < m) {
            for (int j = 0; j < m; j++) {
                for (int i = 0; i < n; i++) {
                    ans[i + j] += a[i] * b[j];
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i + j] += a[i] * b[j];
                }
            }
        }
        return ans;
    }

    template <class mint, internal::is_static_modint_t<mint>* = nullptr>
    std::vector<mint> convolution_fft(std::vector<mint> a, std::vector<mint> b) {
        int n = int(a.size()), m = int(b.size());
        int z = 1 << internal::ceil_pow2(n + m - 1);
        a.resize(z);
        internal::butterfly(a);
        b.resize(z);
        internal::butterfly(b);
        for (int i = 0; i < z; i++) {
            a[i] *= b[i];
        }
        internal::butterfly_inv(a);
        a.resize(n + m - 1);
        mint iz = mint(z).inv();
        for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
        return a;
    }

    }  // namespace internal

    template <class mint, internal::is_static_modint_t<mint>* = nullptr>
    std::vector<mint> convolution(std::vector<mint>&& a, std::vector<mint>&& b) {
        int n = int(a.size()), m = int(b.size());
        if (!n || !m) return {};
        if (std::min(n, m) <= 60) return convolution_naive(a, b);
        return internal::convolution_fft(a, b);
    }

    template <class mint, internal::is_static_modint_t<mint>* = nullptr>
    std::vector<mint> convolution(const std::vector<mint>& a,
                                const std::vector<mint>& b) {
        int n = int(a.size()), m = int(b.size());
        if (!n || !m) return {};
        if (std::min(n, m) <= 60) return convolution_naive(a, b);
        return internal::convolution_fft(a, b);
    }

    template <unsigned int mod = 998244353,
            class T,
            std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
    std::vector<T> convolution(const std::vector<T>& a, const std::vector<T>& b) {
        int n = int(a.size()), m = int(b.size());
        if (!n || !m) return {};

        using mint = static_modint<mod>;
        std::vector<mint> a2(n), b2(m);
        for (int i = 0; i < n; i++) {
            a2[i] = mint(a[i]);
        }
        for (int i = 0; i < m; i++) {
            b2[i] = mint(b[i]);
        }
        auto c2 = convolution(move(a2), move(b2));
        std::vector<T> c(n + m - 1);
        for (int i = 0; i < n + m - 1; i++) {
            c[i] = c2[i].val();
        }
        return c;
    }

    std::vector<long long> convolution_ll(const std::vector<long long>& a,
                                        const std::vector<long long>& b) {
        int n = int(a.size()), m = int(b.size());
        if (!n || !m) return {};

        static constexpr unsigned long long MOD1 = 754974721;  // 2^24
        static constexpr unsigned long long MOD2 = 167772161;  // 2^25
        static constexpr unsigned long long MOD3 = 469762049;  // 2^26
        static constexpr unsigned long long M2M3 = MOD2 * MOD3;
        static constexpr unsigned long long M1M3 = MOD1 * MOD3;
        static constexpr unsigned long long M1M2 = MOD1 * MOD2;
        static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;

        static constexpr unsigned long long i1 =
            internal::inv_gcd(MOD2 * MOD3, MOD1).second;
        static constexpr unsigned long long i2 =
            internal::inv_gcd(MOD1 * MOD3, MOD2).second;
        static constexpr unsigned long long i3 =
            internal::inv_gcd(MOD1 * MOD2, MOD3).second;

        auto c1 = convolution<MOD1>(a, b);
        auto c2 = convolution<MOD2>(a, b);
        auto c3 = convolution<MOD3>(a, b);

        std::vector<long long> c(n + m - 1);
        for (int i = 0; i < n + m - 1; i++) {
            unsigned long long x = 0;
            x += (c1[i] * i1) % MOD1 * M2M3;
            x += (c2[i] * i2) % MOD2 * M1M3;
            x += (c3[i] * i3) % MOD3 * M1M2;
            // B = 2^63, -B <= x, r(real value) < B
            // (x, x - M, x - 2M, or x - 3M) = r (mod 2B)
            // r = c1[i] (mod MOD1)
            // focus on MOD1
            // r = x, x - M', x - 2M', x - 3M' (M' = M % 2^64) (mod 2B)
            // r = x,
            //     x - M' + (0 or 2B),
            //     x - 2M' + (0, 2B or 4B),
            //     x - 3M' + (0, 2B, 4B or 6B) (without mod!)
            // (r - x) = 0, (0)
            //           - M' + (0 or 2B), (1)
            //           -2M' + (0 or 2B or 4B), (2)
            //           -3M' + (0 or 2B or 4B or 6B) (3) (mod MOD1)
            // we checked that
            //   ((1) mod MOD1) mod 5 = 2
            //   ((2) mod MOD1) mod 5 = 3
            //   ((3) mod MOD1) mod 5 = 4
            long long diff =
                c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));
            if (diff < 0) diff += MOD1;
            static constexpr unsigned long long offset[5] = {
                0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};
            x -= offset[diff % 5];
            c[i] = x;
        }

        return c;
    }

}  // namespace atcoder

//ACL lazy_segtree
namespace atcoder {

    template <class S,
            S (*op)(S, S),
            S (*e)(),
            class F,
            S (*mapping)(F, S),
            F (*composition)(F, F),
            F (*id)()>
    struct lazy_segtree {
    public:
        lazy_segtree() : lazy_segtree(0) {}
        lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
        lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
            log = internal::ceil_pow2(_n);
            size = 1 << log;
            d = std::vector<S>(2 * size, e());
            lz = std::vector<F>(size, id());
            for (int i = 0; i < _n; i++) d[size + i] = v[i];
            for (int i = size - 1; i >= 1; i--) {
                update(i);
            }
        }

        void set(int p, S x) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p >> i);
        }

        S get(int p) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            return d[p];
        }

        S prod(int l, int r) {
            assert(0 <= l && l <= r && r <= _n);
            if (l == r) return e();

            l += size;
            r += size;

            for (int i = log; i >= 1; i--) {
                if (((l >> i) << i) != l) push(l >> i);
                if (((r >> i) << i) != r) push(r >> i);
            }

            S sml = e(), smr = e();
            while (l < r) {
                if (l & 1) sml = op(sml, d[l++]);
                if (r & 1) smr = op(d[--r], smr);
                l >>= 1;
                r >>= 1;
            }

            return op(sml, smr);
        }

        S all_prod() { return d[1]; }

        void apply(int p, F f) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            d[p] = mapping(f, d[p]);
            for (int i = 1; i <= log; i++) update(p >> i);
        }
        void apply(int l, int r, F f) {
            assert(0 <= l && l <= r && r <= _n);
            if (l == r) return;

            l += size;
            r += size;

            for (int i = log; i >= 1; i--) {
                if (((l >> i) << i) != l) push(l >> i);
                if (((r >> i) << i) != r) push((r - 1) >> i);
            }

            {
                int l2 = l, r2 = r;
                while (l < r) {
                    if (l & 1) all_apply(l++, f);
                    if (r & 1) all_apply(--r, f);
                    l >>= 1;
                    r >>= 1;
                }
                l = l2;
                r = r2;
            }

            for (int i = 1; i <= log; i++) {
                if (((l >> i) << i) != l) update(l >> i);
                if (((r >> i) << i) != r) update((r - 1) >> i);
            }
        }

        template <bool (*g)(S)> int max_right(int l) {
            return max_right(l, [](S x) { return g(x); });
        }
        template <class G> int max_right(int l, G g) {
            assert(0 <= l && l <= _n);
            assert(g(e()));
            if (l == _n) return _n;
            l += size;
            for (int i = log; i >= 1; i--) push(l >> i);
            S sm = e();
            do {
                while (l % 2 == 0) l >>= 1;
                if (!g(op(sm, d[l]))) {
                    while (l < size) {
                        push(l);
                        l = (2 * l);
                        if (g(op(sm, d[l]))) {
                            sm = op(sm, d[l]);
                            l++;
                        }
                    }
                    return l - size;
                }
                sm = op(sm, d[l]);
                l++;
            } while ((l & -l) != l);
            return _n;
        }

        template <bool (*g)(S)> int min_left(int r) {
            return min_left(r, [](S x) { return g(x); });
        }
        template <class G> int min_left(int r, G g) {
            assert(0 <= r && r <= _n);
            assert(g(e()));
            if (r == 0) return 0;
            r += size;
            for (int i = log; i >= 1; i--) push((r - 1) >> i);
            S sm = e();
            do {
                r--;
                while (r > 1 && (r % 2)) r >>= 1;
                if (!g(op(d[r], sm))) {
                    while (r < size) {
                        push(r);
                        r = (2 * r + 1);
                        if (g(op(d[r], sm))) {
                            sm = op(d[r], sm);
                            r--;
                        }
                    }
                    return r + 1 - size;
                }
                sm = op(d[r], sm);
            } while ((r & -r) != r);
            return 0;
        }

    private:
        int _n, size, log;
        std::vector<S> d;
        std::vector<F> lz;

        void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
        void all_apply(int k, F f) {
            d[k] = mapping(f, d[k]);
            if (k < size) lz[k] = composition(f, lz[k]);
        }
        void push(int k) {
            all_apply(2 * k, lz[k]);
            all_apply(2 * k + 1, lz[k]);
            lz[k] = id();
        }
    };

}  // namespace atcoder

using namespace atcoder;
#define mint static_modint<mod>
#define vm(n,i) vector<mint>(n,i)
#define v2m(n,m,i) vector<vector<mint>>(n,vm(m,i))
#define v3m(n,m,k,i) vector<vector<vector<mint>>>(n,v2m(m,k,i))
#define v4m(n,m,k,l,i) vector<vector<vector<vector<mint>>>>(n,v3m(m,k,l,i))

//vector output
template <typename T>
void out(vector<T> &v){
    for(T x:v) cout << x << " ";
    cout << "\n"; return;
}
//Graph
struct graph {
    long long N;
	vector<vector<tuple<long long,long long,int>>> G;
    vector<long long> par_v;
    vector<long long> par_e;
    int edge_count = 0;
    
	graph(long long n) {
        N = n;
		G = vector<vector<tuple<long long,long long,int>>>(N);
        par_v = vector<long long>(N,-1);
        par_e = vector<long long>(N,-1);
	}

    graph(long long n,long long m,bool weighted = false,bool directed = false) {
        N = n;
		G = vector<vector<tuple<long long,long long,int>>>(N);
        par_v = vector<long long>(N,-1);
        par_e = vector<long long>(N,-1);
        for(int i=0;i<m;i++){
            long long a,b,c; cin >> a >> b;
            if(weighted) cin >> c;
            else c = 1;
            unite(a,b,c,directed);
        }
	}

    void unite(long long a,long long b,long long cost = 1,bool directed = false){
        G[a].emplace_back(b,cost,edge_count);
        if(!directed) G[b].emplace_back(a,cost,edge_count);
        edge_count++;
    }
};
//map add
template <typename T>
void add(map<T,ll> &cnt,T a,ll n = 1){
    if(cnt.count(a)) cnt[a] += n;
    else cnt[a] = n;
}  

const ll mod = 998244353;

int main(){
    riano_; ll ans = 0;
    ll N,M; cin >> N >> M;
    vector<Pr> ed;
    string S;
    rep(i,M) S += '0';
    rep(i,M){
        string T = S; T[i] = '1';
        cout << "? " << T << endl;
        ll a; cin >> a;
        ed.emplace_back(a,(ll)i);
    }
    sort(all(ed)); reverse(all(ed));
    rep(i,M) S[i] = '1';
    cout << "? " << S << endl;
    cin >> ans;
    rep(i,M-1){
        auto[c,id] = ed[i];
        S[id] = '0';
        cout << "? " << S << endl;
        ll a; cin >> a;
        if(ans-a!=c){
            ans = a;
        }
        else{
            S[id] = '1';
        }
    }
    cout << "! " << ans << endl;
    //cout << ans << endl;
}