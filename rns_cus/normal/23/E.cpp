//23_E
#include <bits/stdc++.h>
using namespace std;

// base and base_digits must be consistent
typedef __int64 INT;
const int pb = 10;
const int base_digits = 9;
const int base = 1000000000;	//pb^base_digits
const int DIV = 100000;		//pb^5

struct bigint {
	vector <int> a;
	int sign;

	bigint() : sign(1) {}
	bigint(INT v) { *this = v; }
	bigint(const string &s) { read(s); }

	void operator = (const bigint &v) { sign = v.sign, a = v.a; }

	void operator = (INT v) {
		sign = 1;
		if (v < 0) sign = -1, v = -v;
		for ( ; v > 0; v = v / base) a.push_back(v % base);
	}

	bigint operator + (const bigint &v) const {
		if (sign == v.sign) {
			bigint res = v;
			for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; i ++) {
				if (i == (int) res.a.size()) res.a.push_back(0);
				res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
				carry = res.a[i] >= base;
				if (carry) res.a[i] -= base;
			}
			return res;
		}
		return *this - (-v);
	}

	bigint operator - (const bigint &v) const {
		if (sign == v.sign) {
			if (abs() >= v.abs()) {
				bigint res = *this;
				for (int i = 0, carry = 0; i < (int) v.a.size() || carry; i ++) {
					res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
					carry = res.a[i] < 0;
					if (carry) res.a[i] += base;
				}
				res.trim();
				return res;
			}
			return - (v - *this);
		}
		return *this + (-v);
	}

	void operator *= (int v) {
		if (v < 0) sign = -sign, v = -v;
		for (int i = 0, carry = 0; i < (int) a.size() || carry; i ++) {
			if (i == (int) a.size()) a.push_back(0);
			INT cur = a[i] * (INT) v + carry;
			carry = (int) (cur / base);
			a[i] = (int) (cur % base);
		}
		trim();
	}

	bigint operator * (int v) const {
		bigint res = *this;
		res *= v;
		return res;
	}

	friend pair <bigint, bigint> DIVmod(const bigint &a1, const bigint &b1) {
		int norm = base / (b1.a.back() + 1);
		bigint a = a1.abs() * norm;
		bigint b = b1.abs() * norm;
		bigint q, r;
		q.a.resize(a.a.size());

		for (int i = a.a.size() - 1; i >= 0; i --) {
			r *= base;
			r += a.a[i];
			int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
			int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
			int d = ((INT) base * s1 + s2) / b.a.back();
			r -= b * d;
			while (r < 0) r += b, --d;
			q.a[i] = d;
		}

		q.sign = a1.sign * b1.sign;
		r.sign = a1.sign;
		q.trim();
		r.trim();
		return make_pair(q, r / norm);
	}

	bigint operator / (const bigint &v) const { return DIVmod(*this, v).first; }
	bigint operator%(const bigint &v) const { return DIVmod(*this, v).second; }

	void operator/=(int v) {
		if (v < 0) sign = -sign, v = -v;
		for (int i = (int) a.size() - 1, rem = 0; i >= 0; i --) {
			INT cur = a[i] + rem * (INT) base;
			a[i] = (int) (cur / v);
			rem = (int) (cur % v);
		}
		trim();
	}

	bigint operator / (int v) const {
		bigint res = *this;
		res /= v;
		return res;
	}

	int operator % (int v) const {
		if (v < 0) v = -v;
		int m = 0;
		for (int i = a.size() - 1; i >= 0; --i)
			m = (a[i] + m * (INT) base) % v;
		return m * sign;
	}

	void operator += (const bigint &v) { *this = *this + v; }
	void operator -= (const bigint &v) { *this = *this - v; }
	void operator *= (const bigint &v) { *this = *this * v; }
	void operator /= (const bigint &v) { *this = *this / v; }

	bool operator < (const bigint &v) const {
		if (sign != v.sign) return sign < v.sign;
		if (a.size() != v.a.size()) return a.size() * sign < v.a.size() * v.sign;
		for (int i = a.size() - 1; i >= 0; i--) if (a[i] != v.a[i]) return a[i] * sign < v.a[i] * sign;
		return false;
	}

	bool operator > (const bigint &v) const { return v < *this; }
	bool operator <= (const bigint &v) const { return !(v < *this); }
	bool operator >= (const bigint &v) const { return !(*this < v); }
	bool operator==(const bigint &v) const { return !(*this < v) && !(v < *this); }
	bool operator!=(const bigint &v) const { return *this < v || v < *this; }

	void trim() {
		while (!a.empty() && !a.back()) a.pop_back();
		if (a.empty()) sign = 1;
	}

	bool isZero() const { return a.empty() || (a.size() == 1 && !a[0]); }

	bigint operator - () const {
		bigint res = *this;
		res.sign = -sign;
		return res;
	}

	bigint abs() const {
		bigint res = *this;
		res.sign *= res.sign;
		return res;
	}

	INT longValue() const {
		INT res = 0;
		for (int i = a.size() - 1; i >= 0; i --) res = res * base + a[i];
		return res * sign;
	}

	friend bigint gcd(const bigint &a, const bigint &b) { return b.isZero() ? a : gcd(b, a % b); }
	friend bigint lcm(const bigint &a, const bigint &b) { return a / gcd(a, b) * b; }

	void read(const string &s) {
		sign = 1;
		a.clear();
		int pos = 0;
		while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
			if (s[pos] == '-') sign = -sign;
			pos ++;
		}
		for (int i = s.size() - 1; i >= pos; i -= base_digits) {
			int x = 0;
			for (int j = max(pos, i - base_digits + 1); j <= i; j ++) x = x * pb + s[j] - '0';
			a.push_back(x);
		}
		trim();
	}

	friend istream& operator>>(istream &stream, bigint &v) {
		string s;
		stream >> s;
		v.read(s);
		return stream;
	}

	friend ostream& operator<<(ostream &stream, const bigint &v) {
		if (v.sign == -1) stream << '-';
		stream << (v.a.empty() ? 0 : v.a.back());
		for (int i = (int) v.a.size() - 2; i >= 0; --i) stream << setw(base_digits) << setfill('0') << v.a[i];
		return stream;
	}

	static vector <int> convert_base(const vector <int> &a, int old_digits, int new_digits) {
		vector <INT> p(max(old_digits, new_digits) + 1);
		p[0] = 1;
		for (int i = 1; i < (int) p.size(); i++) p[i] = p[i - 1] * pb;
		vector <int> res;
		INT cur = 0;
		int cur_digits = 0;
		for (int i = 0; i < (int) a.size(); i ++) {
			cur += a[i] * p[cur_digits];
			cur_digits += old_digits;
			while (cur_digits >= new_digits) {
				res.push_back(int(cur % p[new_digits]));
				cur /= p[new_digits];
				cur_digits -= new_digits;
			}
		}
		res.push_back((int) cur);
		while (!res.empty() && !res.back()) res.pop_back();
		return res;
	}

	typedef vector <INT> vll;

	static vll karatsubaMultiply(const vll &a, const vll &b) {
		int n = a.size();
		vll res(n + n);
		if (n <= 32) {
			for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
			res[i + j] += a[i] * b[j];
			return res;
		}

		int k = n >> 1;
		vll a1(a.begin(), a.begin() + k);
		vll a2(a.begin() + k, a.end());
		vll b1(b.begin(), b.begin() + k);
		vll b2(b.begin() + k, b.end());

		vll a1b1 = karatsubaMultiply(a1, b1);
		vll a2b2 = karatsubaMultiply(a2, b2);

		for (int i = 0; i < k; i ++) a2[i] += a1[i];
		for (int i = 0; i < k; i ++) b2[i] += b1[i];

		vll r = karatsubaMultiply(a2, b2);
		for (int i = 0; i < (int) a1b1.size(); i ++) r[i] -= a1b1[i];
		for (int i = 0; i < (int) a2b2.size(); i ++) r[i] -= a2b2[i];

		for (int i = 0; i < (int) r.size(); i ++) res[i + k] += r[i];
		for (int i = 0; i < (int) a1b1.size(); i ++) res[i] += a1b1[i];
		for (int i = 0; i < (int) a2b2.size(); i ++) res[i + n] += a2b2[i];
		return res;
	}

	bigint operator*(const bigint &v) const {
		vector <int> a5 = convert_base(this->a, base_digits, 5);
		vector <int> b5 = convert_base(v.a, base_digits, 5);
		vll a(a5.begin(), a5.end());
		vll b(b5.begin(), b5.end());
		while (a.size() < b.size()) a.push_back(0);
		while (b.size() < a.size()) b.push_back(0);
		while (a.size() & (a.size() - 1)) a.push_back(0), b.push_back(0);
		vll c = karatsubaMultiply(a, b);
		bigint res;
		res.sign = sign * v.sign;
		for (int i = 0, carry = 0; i < (int) c.size(); i++) {
			INT cur = c[i] + carry;
			res.a.push_back((int) (cur % DIV));
			carry = (int) (cur / DIV);
		}
		res.a = convert_base(res.a, 5, base_digits);
		res.trim();
		return res;
	}

	inline bool isOdd() { return a[0] & 1; }
};

#define N 711
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define pb push_back

int p[N], pcnt;
bool fg[N];
short int num[N][N];
double lg[N];

void init(){
    fg[1] = 1;
    for(int i = 2; i < N; i ++){
        if(!fg[i]) p[pcnt ++] = i;
        for(int j = 0; j < pcnt && p[j] * i < N; j ++){
            fg[p[j] * i] = 1;
            if(i % p[j] == 0) break;
        }
    }

    for(int i = 2; i < N; i ++){
        int ii = i;
        for(int j = 0; j < pcnt; j ++) if(ii % p[j] == 0) {
            while(ii % p[j] == 0) ii /= p[j], num[i][j] ++;
        }
    }

    for(int i = 0; i < pcnt; i ++) lg[i] = log(1.0 * p[i]);
}

void multiply(short int *f, short int *g, short int *h){
    for(int i = 0; i < pcnt; i ++) h[i] = f[i] + g[i];
}

void copy(short int *f, short int *g){
    for(int i = 0; i < pcnt; i ++) f[i] = g[i];
}

bool cmp(short int *f, short int *g){
    double r1 = 0, r2 = 0;
    for(int i = 0; i < pcnt; i ++){
        r1 += lg[i] * f[i];
        r2 += lg[i] * g[i];
    }
    return r1 < r2;
}

vector <short int> v[N];
short int n;
short int chi[N];
short int f[N][N][128], g[N][128], h[N];
short int ans[N][N];
bool vis[N];

void dfs(int x){
    vis[x] = 1;
    short int tot = 1;
    for(int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i];
        if(vis[y]) continue;
        dfs(y);
        for(int i = 1; i <= tot; i ++) {
            for(int j = 0; j < pcnt; j ++) g[i][j] = f[x][i][j];
            multiply(f[x][i], ans[y], h);
            for(int j = 0; j < pcnt; j ++) f[x][i][j] = h[j];
        }
        for(int j = 1; j <= tot; j ++) for(int k = 1; k <= chi[y]; k ++) {
            multiply(g[j], f[y][k], h);
            if(cmp(f[x][j + k], h)) copy(f[x][j + k], h);
        }
        tot += chi[y];
    }
    chi[x] = tot;
    for(int i = 1; i <= tot; i ++) {
        multiply(f[x][i], num[i], h);
        if(cmp(ans[x], h)) copy(ans[x], h);
    }
}

int main(){
    //freopen("e2.in", "r", stdin);
    init();

    scanf("%d", &n);
    for(int i = 0; i < n - 1; i ++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b), v[b].push_back(a);
    }

    dfs(1);

    bigint rlt = 1;
    for(int i = 0; i < pcnt; i ++) for(int j = 0; j < ans[1][i]; j ++) rlt *= p[i];
    cout << rlt;
    ///return 9;
}