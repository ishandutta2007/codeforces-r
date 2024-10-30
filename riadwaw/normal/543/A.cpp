/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>

template <typename T, int n>
struct NDVector {
	typedef std::vector<typename NDVector<T, n - 1>::type> type;
};

template <typename T>
struct NDVector<T, 0> {
	typedef T type;
};

template <typename T>
std::vector<T> make_vector(std::size_t size) {
	return std::vector<T>(size);
}


template <typename T, typename... Args>
typename NDVector<T, sizeof...(Args) + 1>::type make_vector(std::size_t first, Args... sizes) {
	typedef typename NDVector<T, sizeof...(Args) + 1>::type Result;
	return Result(first, make_vector<T>(sizes...));
}


#include <iterator>

#include <string>
#include <stdexcept>
#ifdef SPCPPL_DEBUG
	#define SPCPPL_ASSERT(condition) \
	if(!(condition)) { \
		throw std::runtime_error(std::string() + #condition + " in line " + std::to_string(__LINE__) + " in " + __PRETTY_FUNCTION__); \
	}
#else
	#define SPCPPL_ASSERT(condition)
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
class IntegerIterator : public std::iterator<std::input_iterator_tag, T, std::ptrdiff_t, T*, T> {
public:
	explicit IntegerIterator(int value): value(value) {

	}

	IntegerIterator& operator++ () {
		++value;
		return *this;
	}

	IntegerIterator operator++ (int) {
		IntegerIterator copy = *this;
		++value;
		return copy;
	}

	IntegerIterator& operator-- () {
		--value;
		return *this;
	}

	IntegerIterator operator-- (int) {
		IntegerIterator copy = *this;
		--value;
		return copy;
	}

	T operator * () const {
		return value;
	}

	bool operator == (IntegerIterator rhs) {
		return value == rhs.value;
	}

	bool operator != (IntegerIterator rhs) {
		return !(*this == rhs);
	}
private:
	T value;
};

template <typename T>
class IntegerRange {
public:
	IntegerRange(T begin, T end): begin_(begin), end_(end) {

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
	typedef std::reverse_iterator<IntegerIterator<T>> IteratorType;
public:
	ReversedIntegerRange(T begin, T end): begin_(begin), end_(end) {

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
	SPCPPL_ASSERT(to >= 0);
	return IntegerRange<T>(0, to);
}

template <typename T>
IntegerRange<T> range(T from, T to) {
	SPCPPL_ASSERT(from <= to);
	return IntegerRange<T>(from, to);
}

template <typename T>
ReversedIntegerRange<T> downrange(T from) {
	SPCPPL_ASSERT(from >= 0);
	return ReversedIntegerRange<T>(from, 0);
}

template <typename T>
ReversedIntegerRange<T> downrange(T from, T to) {
	SPCPPL_ASSERT(from >= to);
	return ReversedIntegerRange<T>(from, to);
}

using namespace std;

class TaskA {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n,m,b,mod;
		in >> n >> m >> b >> mod;
		auto dp = make_vector<int>(2, m + 1, b + 1);

		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			in >> a[i];
		}
		dp[0][0][0] = 1 % mod;
		for(int i :range(n)) {
			for (int j : range(m + 1)) {
				for (int k: range(b + 1)) {
					dp[(i + 1) & 1][j][k] += dp[i & 1][j][k];
					f(dp[(i + 1) & 1][j][k], mod);

					if(j + 1 <= m && k + a[i] <= b) {
						dp[i & 1][j + 1][k + a[i]] += dp[i & 1][j][k];
						f(dp[i & 1][j + 1][k + a[i]], mod);
					}
				}
			}

			dp[i & 1] = make_vector<int>(m + 1, b + 1);
		}

		long long ans = 0;
		for(int i = 0; i <= b; ++i) {
			ans += dp[n & 1][m][i];
		}

		out << ans % mod;
	}


	void f(int& x, int mod) {
		if(x >= mod)
			x -= mod;
	}
};


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << std::fixed;
	std::cout.precision(20);
	TaskA solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}