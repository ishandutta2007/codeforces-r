/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>


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



#include <random>


namespace impl {
using Random = std::mt19937;
}  // namespace impl

inline impl::Random& randomEngine() {
	static std::random_device device;
	static impl::Random engine(device());
	return engine;
}

inline int randomInteger() {
	std::uniform_int_distribution<int> d;
	return d(randomEngine());
}

inline int randomInteger(int to) {
	SPCPPL_ASSERT(to > 0);
	std::uniform_int_distribution<int> d(0, to - 1);
	return d(randomEngine());
}

inline int randomInteger(int from, int to) {
	return from + randomInteger(to - from);
}

//#define PROBLEM "problem_name.h"
//#include PROBLEM
//#include <message.h>
//#include <spcppl/dgcj.h>

using namespace std;
vector<int> current_test;
vector<int> current_test_initial;
class FKovarniiInteraktor {
public:
	static constexpr int kStressCount = 20;

	static void generateTest(std::ostream& test) {
		int n = randomInteger(10);
		current_test.resize(n);
		for (int i: range(n)) {
			current_test[i] = randomInteger() % 2;
		}
		//int n = 3;
		//current_test = {0, 0, 0};
		current_test_initial = current_test;
		test << n << " " <<  accumulate(current_test.begin(), current_test.end(), 0);
	}
	void solve(std::istream& in, std::ostream& out) {
		//static int testnumber = 0;
		//out << "Case #" << ++testnumber << ": ";

		int n, t;
		in >> n >> t;
		auto go = [&](int x, int y) {
			out << "? "  << x + 1 << " " << y + 1 << endl;
			#ifdef LOCAL
				if (randomInteger(2)) {
					for (int i = 0; i <= y; ++i) {
						current_test[i] ^= 1;
					}
				} else {
					for (int i = x; i < n; ++i) {
						current_test[i] ^= 1;
					}
				}
				return accumulate(current_test.begin(), current_test.end(), 0);
			#else
				int z;
				cin >> z;
				return z;
			#endif
		};
		if (n == 1) {
			out << "! " << t;
			return;
		}
		if (n % 2 == 0) {
			vector<int> cur(n);
			vector<int> changed(n);
			for (int i: range(n)) {
				while (true) {
					bool br = false;
					int newt = go(i, i);
					if ((t % 2) ^ (newt % 2) ^ (i % 2) == 0) {
						for (int j = i; j < n; ++j) {
							changed[j] ^= 1;
						}
					} else {
						for (int j = 0; j <= i; ++j) {
							changed[j] ^= 1;
							cur[j] ^= 1;
						}
						int now = accumulate(cur.begin(), cur.begin() + i, 0);
						int was = i - now;
						int expected_delta = now - was;
						int actual_delta = newt - t;
						assert(abs(actual_delta - expected_delta) == 1);
						if (actual_delta > expected_delta) {
							cur[i] = 1;
						} else {
							cur[i] = 0;
						};
						br = true;
					};
					t = newt;
					if (br) {
						break;
					}
				}
			}
			out << "! ";
			for (int i = 0; i < n; ++i) {
				out << (cur[i] ^ changed[i]);
				cur[i] ^= changed[i];
			}
			out << "\n";
			#ifdef LOCAL
			assert(cur == current_test_initial);
			#endif
		} else {
			vector<int> sum(n - 1);
			vector<int> changed(n);
			for (int i = 0; i + 1 < n; i += 2) {
				while (true) {
					bool br = false;
					int newt = go(i, i + 1);
					if ((t % 2) ^ (newt % 2) ^ (i % 2) == 1) {
						for (int j = i; j < n; ++j) {
							changed[j] ^= 1;
						}
					} else {
						for (int j = 0; j <= i + 1; ++j) {
							changed[j] ^= 1;
						}
						for (int j = 0; j <= i; ++j) {
							sum[j] = 2 - sum[j];
						}
						int now = 0;
						for (int j = 0; j < i; j += 2) {
							now += sum[j];
						}
						int was = i - now;
						int expected_delta = now - was;
						int actual_delta = newt - t;
						assert(abs(actual_delta - expected_delta) == 2 || actual_delta == expected_delta);
						if (actual_delta - expected_delta == 2) {
							sum[i] = 2;
						} else if (actual_delta - expected_delta == 0) {
							sum[i] = 1;
						} else {
							sum[i] = 0;
						}
						br = true;
					};
					t = newt;
					if (br) {
						break;
					}
				}
			}
			vector<int> cur(n);
			cur[n - 1] = t;
			for (int i = 0; i < n - 1; i+= 2) {
				cur[n - 1] -= sum[i];
			}

			for (int i = n - 2; i >= 0; --i) {
				while (true) {
					bool br = false;
					int newt = go(i, i + 1);
					if ((t % 2) ^ (newt % 2) ^ (i % 2) == 0) {
						for (int j = 0; j <= i + 1; ++j) {
							changed[j] ^= 1;
						}
						cur[i + 1] ^= 1;
					} else {
						for (int j = i; j < n; ++j) {
							changed[j] ^= 1;
							cur[j] ^= 1;
						}
						int now = accumulate(cur.begin() + i + 1, cur.end(), 0);
						int was = n - 1 - i - now;
						int expected_delta = now - was;
						int actual_delta = newt - t;
						assert(abs(actual_delta - expected_delta) == 1);
						if (actual_delta > expected_delta) {
							cur[i] = 1;
						} else {
							cur[i] = 0;
						};
						br = true;
					};
					t = newt;
					if (br) {
						break;
					}
				}
			}
			out << "! ";
			for (int i = 0; i < n; ++i) {
				out << (cur[i] ^ changed[i]);
				cur[i] ^= changed[i];
			}
			out << "\n";
			#ifdef LOCAL
			assert(cur == current_test_initial);
			#endif
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	FKovarniiInteraktor solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}