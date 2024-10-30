#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
namespace io {
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
  inline char getc () {return (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++);}
  inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf;}
  inline void putc (char x) {*oS ++ = x; if (oS == oT) flush ();}
  template<class T>
  inline void read(T &x) {
    char ch; int f = 1;
    x = 0;
    while(isspace(ch = getc()));
    if(ch == '-') ch = getc(), f = -1;
    do x = x * 10 + ch - '0'; while(isdigit(ch = getc()));
    x *= f;
  }
  template<class T, class ...Args>
  inline void read(T &x, Args&... args) {read(x); read(args...);}
  template<class T>
  inline void write(T x) {
    static char stk[128];
    int top = 0;
    if(x == 0) {putc('0'); return;}
    if(x < 0) putc('-'), x = -x;
    while(x) stk[top++] = x % 10, x /= 10;
    while(top) putc(stk[--top] + '0');
  }
  template<class T, class ...Args>
  inline void write(T x, Args... args) {write(x); putc(' '); write(args...);}
  inline void space() {putc(' ');}
  inline void endl() {putc('\n');}
  struct _flush {~_flush() {flush();}} __flush;
};
using io::read; using io::write; using io::flush; using io::space; using io::endl; using io::getc; using io::putc;

const int M = 998244353;
inline int add(int x, int y) { return x + y >= M ? x + y - M : x + y; }
template <class... Args> inline int add(int x, int y, Args... args) { return add(add(x, y), args...); }
inline int sub(int x, int y) { return x - y < 0 ? x - y + M : x - y; }
inline int mul(int x, int y) { return 1LL * x * y % M; }
template <class... Args> inline int mul(int x, int y, Args... args) { return mul(mul(x, y), args...); }
inline void inc(int &x, int y=1) { x += y; if(x >= M) x -= M; }
inline void dec(int &x, int y=1) { x -= y; if(x < 0) x += M; }
inline int power(int x, int y) {
  int res = 1;
  for(; y; y>>=1, x = mul(x, x)) if(y & 1) res = mul(res, x);
  return res;
}
inline int inv(int x) { return power(x, M - 2); }

const int N = 5005;
int a[N], f[N], s[N];
int fac[N], ifac[N];
void prefac(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
  ifac[n] = inv(fac[n]);
  for (int i = n - 1; i >= 0; --i) ifac[i] = mul(ifac[i + 1], i + 1);
}

int main() {
  int n;
  read(n);
  prefac(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  sort(a + 1, a + 1 + n);
  if (a[n] < a[n - 1] * 2) {
    write(0), endl();
    return 0;
  }
  f[0] = 1; s[0] = fac[n - 1];
  int last = 0;
  for (int i = 1; i <= n; ++i) {
    while (last != n && a[last + 1] * 2 <= a[i]) ++last;
    f[i] = mul(s[last], ifac[n - last - 1]);
    if (i != n) s[i] = add(s[i - 1], mul(f[i], fac[n - last - 2]));
  }
  write(f[n]), endl();
  return 0;
}