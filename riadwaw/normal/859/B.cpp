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


#include <algorithm>

template <typename T>
void updateMin(T& oldValue, const T& newValue) {
	if (newValue < oldValue) {
		oldValue = newValue;
	}
}

template <typename T>
void updateMax(T& oldValue, const T& newValue) {
	if (oldValue < newValue) {
		oldValue = newValue;
	}
}

//#define PROBLEM "problem_name.h"
//#include PROBLEM
//#include <message.h>
//#include <spcppl/dgcj.h>

using namespace std;

class TaskB {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		int ans = 1000000000;
		for (int i = 1; i <= n; ++i) {
			int j = divideCeil(n, i);
			updateMin(ans, i + j);
		}

		out << ans * 2;
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}