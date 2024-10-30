/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>


#include <iterator>


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


/**
* Support decrementing and multi-passing, but not declared bidirectional(or even forward) because
* it's reference type is not a reference.
*
* It doesn't return reference because
* 1. Anyway it'll not satisfy requirement [forward.iterators]/6
*   If a and b are both dereferenceable, then a == b if and only if *a and
*   b are bound to the same object.
* 2. It'll not work with reverse_iterator that returns operator * of temporary which is temporary for this iterator
*
* Note, reverse_iterator is not guaranteed to work  now too since it works only with bidirectional iterators,
* but it's seems to work at least on my implementation.
*
* It's not really useful anywhere except iterating anyway.
*/
template <typename T>
class IntegerIterator {
public:
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using pointer = T*;
	using reference = T;
	using iterator_category = std::input_iterator_tag;

	explicit IntegerIterator(T value): value(value) {

	}

	IntegerIterator& operator++() {
		++value;
		return *this;
	}

	IntegerIterator operator++(int) {
		IntegerIterator copy = *this;
		++value;
		return copy;
	}

	IntegerIterator& operator--() {
		--value;
		return *this;
	}

	IntegerIterator operator--(int) {
		IntegerIterator copy = *this;
		--value;
		return copy;
	}

	T operator*() const {
		return value;
	}

	bool operator==(IntegerIterator rhs) const {
		return value == rhs.value;
	}

	bool operator!=(IntegerIterator rhs) const {
		return !(*this == rhs);
	}

private:
	T value;
};

template <typename T>
class IntegerRange {
public:
	IntegerRange(T begin, T end): begin_(begin), end_(end) {
		SPCPPL_ASSERT(begin <= end);
	}

	IntegerIterator<T> begin() const {
		return IntegerIterator<T>(begin_);
	}

	IntegerIterator<T> end() const {
		return IntegerIterator<T>(end_);
	}

private:
	T begin_;
	T end_;
};

template <typename T>
class ReversedIntegerRange {
	using IteratorType = std::reverse_iterator<IntegerIterator<T>>;
public:
	ReversedIntegerRange(T begin, T end): begin_(begin), end_(end) {
		SPCPPL_ASSERT(begin >= end);
	}

	IteratorType begin() const {
		return IteratorType(IntegerIterator<T>(begin_));
	}

	IteratorType end() const {
		return IteratorType(IntegerIterator<T>(end_));
	}

private:
	T begin_;
	T end_;
};

template <typename T>
IntegerRange<T> range(T to) {
	return IntegerRange<T>(0, to);
}

template <typename T>
IntegerRange<T> range(T from, T to) {
	return IntegerRange<T>(from, to);
}

template <typename T>
IntegerRange<T> inclusiveRange(T to) {
	return IntegerRange<T>(0, to + 1);
}

template <typename T>
IntegerRange<T> inclusiveRange(T from, T to) {
	return IntegerRange<T>(from, to + 1);
}

template <typename T>
ReversedIntegerRange<T> downrange(T from) {
	return ReversedIntegerRange<T>(from, 0);
}

template <typename T>
ReversedIntegerRange<T> downrange(T from, T to) {
	return ReversedIntegerRange<T>(from, to);
}

template <typename T>
ReversedIntegerRange<T> inclusiveDownrange(T from) {
	return ReversedIntegerRange<T>(from + 1, 0);
}

template <typename T>
ReversedIntegerRange<T> inclusiveDownrange(T from, T to) {
	return ReversedIntegerRange<T>(from + 1, to);
}



struct Bool {
	Bool() = default;

	/* implicit */ Bool(bool value): value(value) {

	}

	operator bool() const {
		return value;
	}

private:
	bool value;
};



template <typename T>
bool updateMin(T& oldValue, const T& newValue) {
	if (newValue < oldValue) {
		oldValue = newValue;
		return true;
	}
	return false;
}

template <typename T>
bool updateMax(T& oldValue, const T& newValue) {
	if (oldValue < newValue) {
		oldValue = newValue;
		return true;
	}
	return false;
}

//#define PROBLEM "problem_name.h"
//#include PROBLEM
//#include <message.h>
//#include <spcppl/dgcj.h>

using namespace std;

class DYetAnotherMinimizationProblem {
public:
	static constexpr int kStressCount = 0;

	static void generateTest(std::ostream& test) {
	}

	void solve(std::istream& in, std::ostream& out) {
		//static int testnumber = 0;
		//out << "Case #" << ++testnumber << ": ";
		//cerr << "test " << testnumber << endl;

		int n;
		in >> n;
		vector<int> a(n);
		vector<int> b(n);
		for (int i: range(n)) {
			in >> a[i];
		}
		for (int i: range(n)) {
			in >> b[i];
		}

		if (n == 1) {
			out << 0 << "\n";
			return;
		}


		vector<vector<Bool>> can_get(n + 1, vector<Bool>(n * 100 + 1, false));
		can_get[0][0] = true;
		for (int i: range(n)) {
			for (int j: inclusiveRange(i * 100)) {
				if (can_get[i][j]) {
					can_get[i + 1][j + a[i]] = true;
					can_get[i + 1][j + b[i]] = true;
				}
			}
		}

		int64_t sum = 0;
		for (int i: range(n)) {
			sum += a[i];
			sum += b[i];
		}

		int64_t ans = 10000000000;

		for (int i: range(can_get.back().size())) {
			if (can_get.back()[i]) {
				//cerr << i << ' ' << i * i + (sum - i) * (sum - i) << endl;
				updateMin(ans, i * i + (sum - i) * (sum - i));
			}
		}

		for (int i: range(n)) {
			ans += 1LL * a[i] * a[i] * (n - 2);
			ans += 1LL * b[i] * b[i] * (n - 2);
		}
		out << ans << "\n";
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	DYetAnotherMinimizationProblem solver;
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