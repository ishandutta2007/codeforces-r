/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>




#include <string>
#include <stdexcept>

#ifndef SPCPPL_ASSERT
	#ifdef SPCPPL_DEBUG
		#define SPCPPL_ASSERT(condition) \
		if(!(condition)) { \
			throw std::runtime_error(std::string() + #condition + " in line " + std::to_string(__LINE__) + " in " + __PRETTY_FUNCTION__); \
		}
	#else
		#define SPCPPL_ASSERT(condition)
	#endif
#endif


template <typename T>
T divideCeil(T a, T b) {
	SPCPPL_ASSERT(b != 0);
	if (b < 0) {
		a = -a;
		b = -b;
	}
	return a / b + (a % b > 0);
}

template <typename T>
T divideFloor(T a, T b) {
	SPCPPL_ASSERT(b != 0);
	if (b < 0) {
		a = -a;
		b = -b;
	}
	return a / b - (a % b < 0);
}

template <typename T>
T divideTowardsZero(T a, T b) {
	SPCPPL_ASSERT(b != 0);
	return a / b;
}

template <typename T>
T divideAwayFromZero(T a, T b) {
	SPCPPL_ASSERT(b != 0);
	bool changeSign = false;
	if (a < 0) {
		changeSign = !changeSign;
		a = -a;
	}
	if (b < 0) {
		changeSign = !changeSign;
		b = -b;
	}
	T res = (a + b - 1) / b;
	if (changeSign) {
		res *= -1;
	}
	return res;
}



using namespace std;

class TaskA {
public:
	void solve(std::istream& in, std::ostream& out) {
		int64_t x, y, p, q;
		in >> x >> y >> p >> q;

		if (p == q) {
			if (x == y) {
				out << 0 << "\n";
			} else {
				out << -1 << "\n";
			};
			return;
		}
		if (p == 0) {
			if (x == 0) {
				out << 0 << "\n";
			} else {
				out << -1 << "\n";
			}
			return;
		}

		int64_t ans1 = q * divideCeil(x, p);
		p = q - p;
		x = y - x;
		int64_t ans2 = q * divideCeil(x, p);

		out << max(ans1, ans2) - y << "\n";
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskA solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

	return 0;
}