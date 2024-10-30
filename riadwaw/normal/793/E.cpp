/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>
#include <bitset>


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
	typedef std::reverse_iterator<IntegerIterator<T>> IteratorType;
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




#include <type_traits>

template <typename T, size_t N>
struct MakeVector {
	template <
			typename... Args,
			typename R = std::vector<decltype(MakeVector<T, N - 1>::make_vector(std::declval<Args>()...))>
	>
	static R make_vector(std::size_t first, Args... sizes) {
		auto inner = MakeVector<T, N - 1>::make_vector(sizes...);
		return R(first, inner);
	}
};

template <typename T>
struct MakeVector<T, 1> {
	/*
	 * This template is to fool CLion.
	 * Without it CLion thinks that make_vector always returns std::vector<T> and marks code like
	 *
	 * auto dp = make_vector<int>(n, m, 0);
	 * dp[0][0] = 1 as error because it suppose that dp[0] is int
	 *
	 * TODO: Consider removing it once https://youtrack.jetbrains.com/issue/CPP-3340 is fixed
	 */
	template <typename R = std::vector<T>>
	static R make_vector(std::size_t size, const T& value) {
		return R(size, value);
	}
};

template <typename T, typename... Args>
auto make_vector(Args... args) -> decltype(MakeVector<T, sizeof...(Args) - 1>::make_vector(args...)) {
	return MakeVector<T, sizeof...(Args) - 1>::make_vector(args...);
}

#include <map>

using namespace std;

class TaskE {
public:
	vector<int> intr;
	vector<vector<int>> g;

	pair<int, int> dfs(int v) {
		if (g[v].empty()) {
			for (int i = 0; i < 4; ++i) {
				if (intr[i] == v) {
					return {1, i + 1};
				}
			}
			return {1, 0};
		}
		pair<int, int> res{0,0};
		for (auto x: g[v]) {
			auto c = dfs(x);
			res.first += c.first;
			res.second += c.second;
		}
		return res;
	}
	void solve(std::istream& in, std::ostream& out) {
		int n = 5000;
		in >> n;

		g.resize(n);

		int a = 1, b = 2, c = 3, d = 4;
		in >> a >> b >> c >> d;
		--a, --b, --c, --d;

		intr = {a, b, c, d};


		for (int i: range(1, n)) {
			int p = 1;
			in >> p;
			--p;
			g[p].push_back(i);
		}

		vector<int> sizes(4);
		vector<int> addSizes;

		for (int v: g[0]) {
			auto t = dfs(v);
			if (t.second == 0) {
				addSizes.push_back(t.first);
			} else {
				sizes[t.second - 1] = (t.first);
			}
		}

		int sumOthers = 0;
		for (int x: addSizes) {
			sumOthers += x;
		}

		int sumAll = sumOthers;
		for (int x:sizes) {
			sumAll += x;
		}

		if (sumAll % 2) {
			out << "NO\n";
			return;
		}
		//for (int x: sizes) {
		//	cerr << x << endl;
		//}
		//cerr << "---" << endl;
		//
		//for (int x: addSizes) {
		//	cerr << x << endl;
		//}
		//cerr << "---" << endl;
		//cerr << sumOthers << endl;

		//auto dp = make_vector<char>(n + 1, n + 1, 0);

		vector<int> dupSizes(n + 1);
		for (int s: addSizes) {
			++dupSizes[s];
		}
		for (int i: inclusiveRange(n)) {
			if (dupSizes[i] > 2) {
				dupSizes[i * 2] += (dupSizes[i] - 1) / 2;
				dupSizes[i] -= (dupSizes[i] - 1) / 2 * 2;
			}
		}
		vector<bitset<5001>> dp(n + 1);
		dp[0][0] = true;
		for (int s: inclusiveRange(n)) {
			for (int _: range(dupSizes[s])) {
				for (int x: inclusiveDownrange(n, 0)) {
					//for (auto y: inclusiveDownrange(n, 0)) {
					//	if (!dp[x][y]) {
					//		continue;
					//	}
					//	if (x + s <= n) {
					//		dp[x + s][y] = true;
					//	}
					//	if (y + s <= n) {
					//		dp[x][y + s] = true;
					//	}
					//}
					if (x + s <= n) {
						dp[x + s] |= dp[x];
					}
					dp[x] |= (dp[x] << s);
				}
			}
		}

		bool canAB = false;
		bool canCD = false;

		for (int i: inclusiveRange(n)) {
			if (dp[i][0]) {
				if (sizes[2] + i < n / 2 && sizes[3] + (sumOthers - i) < n / 2) {
					canAB = true;
				}
				if (sizes[0] + i < n / 2 && sizes[1] + (sumOthers - i) < n / 2) {
					canCD = true;
				}
			}
		}

		bool canExternal = false;
		for (int i: inclusiveRange(n)) {
			for (int j: inclusiveRange(n)) {
				if (dp[i][j]) {
					if (i < n / 2 && j < n / 2 && sizes[0] + sizes[1] + sumOthers - j < n / 2 &&
					    sizes[2] + sizes[3] + sumOthers - i < n / 2) {
						canExternal = true;
						if (canExternal) {
							break;
						}
						//cerr << i << ' ' << j << ' ' << endl;
					}
				}
			}
			if (canExternal) {
				break;
			}
		}

		if ((canAB && canCD) || canExternal) {
			out << "YES\n";
		} else {
			out << "NO\n";
		}

	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskE solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}