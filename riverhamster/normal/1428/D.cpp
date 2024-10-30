#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>
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

const int N = 100005;
int a[N];
int R = 0;
stack<pair<int, int> > s;
stack<int> s2;
vector<pair<int, int> > res;

#define FAIL putc('-'), putc('1'), exit(0)

int main() {
  int n;
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  R = n + 1;
  for (int i = n; i >= 1; --i) {
    if (a[i] == 0) continue;
    if (a[i] == 1) {
      --R;
      res.emplace_back(R, i);
      s.emplace(R, i);
    }
    else if (a[i] == 2) {
      if (s.empty()) FAIL;
      res.emplace_back(s.top().first, i);
      s.pop();
      s2.push(i);
    }
    else {
      if (s.empty() && s2.empty()) FAIL;
      int t;
      if (!s2.empty()) t = s2.top(), s2.pop();
      else t = s.top().second, s.pop();
      --R;
      res.emplace_back(R, t);
      res.emplace_back(R, i);
      s2.push(i);
    }
  }
  write(res.size()), endl();
  for (auto p : res) write(p.first, p.second), endl();
  return 0;
}