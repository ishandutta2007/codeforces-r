#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>

typedef long long ll;
typedef long double ld;
using namespace std;

struct pt {
	ld x, y;
	pt() : x(0), y(0) {}
	pt(ld x, ld y) : x(x), y(y) {}

	void scan() {
		scanf("%Lf%Lf", &x, &y);
	}
	void print() {
		printf("%.8Lf %.8Lf\n", x, y);
	}
	pt operator+(pt p) {
		return {x + p.x, y + p.y};
	}
	pt operator-(pt p) {
		return {x - p.x, y - p.y};
	}
	ld operator%(pt p) {
		return x * p.x + y * p.y;
	}
	ld operator*(pt p) {
		return x * p.y - y * p.x;
	}
	ld len() {
		return sqrt(x * x + y * y);
	}
	pt operator*(ld k) {
		return {x * k, y * k};
	}
	pt norm(ld k) {
		return *this * (k / len());
	}
	pt rot() {
		return {-y, x};
	}
	ld s(pt a, pt b) {
		return abs((a - *this) * (b - *this)) / 2;
	}
	ld dist(pt p) {
		return (p - *this).len();
	}
};

ld ss(ld r, ld ang) {
	return r * r * (ang / 2 - sin(ang) / 2);
}

ld ss2(ld r, ld d) {
	return ss(r, asin(d / 2 / r) * 2);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0); cin.tie(0); cut.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> v1, v2;
	string s1, s2;
	vector<int> ans(n);
	int f = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (f ^ (s[i] == 'a')) {
			f ^= 1;
			ans[i] = 1;
		}
	}
	for (int i : ans)
		cout << i << ' ';
}