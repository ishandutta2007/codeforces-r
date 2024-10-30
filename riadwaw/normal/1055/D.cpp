/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>
#include <unordered_set>
//#include <spcppl/random/random.hpp>
//#include <spcppl/strings/hash/TwoIntsHasher.hpp>
//#include <spcppl/strings/hash/StringHash.hpp>


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
class IntegerIterator: public std::iterator<std::input_iterator_tag, T, std::ptrdiff_t, T*, T> {
public:
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




#include <cstddef>



std::vector<std::size_t> prefix_function(const std::string& s) {
	auto n = s.size();
	std::vector<std::size_t> pi(n);
	for (auto i: range<std::size_t>(1, n)) {
		std::size_t j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		pi[i] = j;
	}
	return pi;
}

bool isSubstring(const std::string& needle, const std::string& haystack) {
	auto pi = prefix_function(needle + '\0' + haystack);
	for (auto value: pi) {
		if (value == needle.size()) {
			return true;
		}
	}
	return false;
}

//#define PROBLEM "problem_name.h"
//#include PROBLEM
//#include <message.h>
//#include <spcppl/dgcj.h>

using namespace std;


//long long rdtsc() {
//	long long x;
//	asm("rdtsc" : "=A"(x));
//	return x;
//}

class DRefaktoring {
public:
	void solve(std::istream& in, std::ostream& out) {
		//static int testnumber = 0;
		//out << "Case #" << ++testnumber << ": ";

		int n;
		in >> n;
		vector<string> from(n), to(n);

		for (int i: range(n)) {
			in >> from[i];
		}
		for (int i: range(n)) {
			in >> to[i];
		}

		vector<int> start(n, -1);
		vector<int> finish(n, -1);
		for (int i: range(n)) {
			for (auto j: range(from[i].size())) {
				if (from[i][j] != to[i][j]) {
					if (start[i] == -1) {
						start[i] = j;
					}
					finish[i] = j + 1;
				}
			}
		}
		bool increased = true;
		while (increased) {
			char to_increase = 0;
			for (int i: range(n)) {
				if (start[i] == -1) {
					continue;
				}
				if (start[i] == 0) {
					increased = false;
					break;
				} else if (from[i][start[i] - 1] != to_increase && to_increase != 0) {
					increased = false;
				} else {
					to_increase = from[i][start[i] - 1];
				}
			}
			if (increased) {
				for (int i: range(n)) {
					if (start[i] != -1) {
						--start[i];
					}
				}
			}
		}
		increased = true;
		while (increased) {
			char to_increase = 0;
			for (int i: range(n)) {
				if (finish[i] == -1) {
					continue;
				}
				if (finish[i] == from[i].size()) {
					increased = false;
					break;
				} else if (from[i][finish[i]] != to_increase && to_increase != 0) {
					increased = false;
				} else {
					to_increase = from[i][finish[i]];
				}
			}
			if (increased) {
				for (int i: range(n)) {
					if (finish[i] != -1) {
						++finish[i];
					}
				}
			}
		}

		string s;
		string s2;
		for (int i: range(n)) {
			if (start[i] != -1) {
				string t = from[i].substr(start[i], finish[i] - start[i]);
				string t2 = to[i].substr(start[i], finish[i] - start[i]);
				if (s.empty()) {
					s = move(t);
					s2 = move(t2);
				} else if (s != t || s2 != t2) {
					out << "NO\n";
					return;
				}
			}
		}

		for (int i: range(n)) {
			string res = from[i];
			auto index = from[i].find(s);
			if (index != string::npos) {
				copy(s2.begin(), s2.end(), res.begin() + index);
			}
			if (res != to[i]) {
				out << "NO\n";
				return;
			}
		}
		out << "YES\n";
		out << s << '\n' << s2 << "\n";
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	DRefaktoring solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}