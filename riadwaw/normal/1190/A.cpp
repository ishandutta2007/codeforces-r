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
 
//#define PROBLEM "problem_name.h"
//#include PROBLEM
//#include <message.h>
//#include <spcppl/dgcj.h>
 
using namespace std;
 
class ATokitsukazeIVibrasivanieVeshei {
public:
	static constexpr int kStressCount = 0;
	static void generateTest(std::ostream& test) {
	}
	void solve(std::istream& in, std::ostream& out) {
		//static int testnumber = 0;
		//out << "Case #" << ++testnumber << ": ";
 
 
		#define int int64_t
		int n, m;
		int64_t page;
		in >> n >> m >> page;
		vector<int64_t> poses(m);
		int64_t start = 0;
		int iter = 0;
		for (int i: range(m)) {
			int64_t x;
			in >> x;
			--x;
			poses[i] = x;
		}
 
		int ans = 0;
		while (iter < m) {
			if (poses[iter] >= start + page) {
				start += (- start + poses[iter]) / page * page;
				continue;
			}
 
			++ans;
 
			int cntNow = 0;
			assert(poses[iter] < start + page);
			while (iter < m && poses[iter] < start + page) {
				++iter;
				++cntNow;
			}
 
			start += cntNow;
		}
 
		out << ans << "\n";
 
		#undef int
	}
};
 
 
int main() {
	std::ios_base::sync_with_stdio(false);
	ATokitsukazeIVibrasivanieVeshei solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}