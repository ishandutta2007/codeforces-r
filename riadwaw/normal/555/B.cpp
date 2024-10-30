/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <bits/stdc++.h>


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


#include <algorithm>


template<typename R>
void sort(R &range) {
	std::sort(range.begin(), range.end());
}

template<typename R, typename Comp>
void sort(R &range, Comp comp) {
	std::sort(range.begin(), range.end(), comp);
}

template<typename R>
void reverse(R &range) {
	std::reverse(range.begin(), range.end());
}

template<typename R, typename T>
auto lower_bound(const R &range, const T &value) -> decltype(range.begin()) {
	return std::lower_bound(range.begin(), range.end(), value);
}

template<typename R, typename T, typename Comp>
auto lower_bound(const R &range, const T &value, Comp comp) -> decltype(range.begin()) {
	return std::lower_bound(range.begin(), range.end(), value, comp);
}

template<typename R, typename T>
auto upper_bound(const R &range, const T &value) -> decltype(range.begin()) {
	return std::upper_bound(range.begin(), range.end(), value);
}

template<typename R, typename T, typename Comp>
auto upper_bound(const R &range, const T &value, Comp comp) -> decltype(range.begin()) {
	return std::upper_bound(range.begin(), range.end(), value, comp);
}

template <typename R>
auto unique(R& range) -> decltype(range.begin()) {
	return std::unique(range.begin(), range.end());
}

template <typename R>
auto min_element(const R& range) -> decltype(range.begin()) {
	return std::min_element(range.begin(), range.end());
}

template <typename R>
auto max_element(const R& range) -> decltype(range.begin()) {
	return std::max_element(range.begin(), range.end());
}

template <typename R>
bool next_permutation(R& range) {
	return std::next_permutation(range.begin(), range.end());
}

template <typename T>
void unique(std::vector<T>& range) {
	range.erase(std::unique(range.begin(), range.end()), range.end());
}

template <typename R>
R sorted(R range) {
	sort(range);
	return range;
}

template <typename R, typename Comp>
R sorted(R range, Comp comp) {
	sort(range, comp);
	return range;
}

template <typename R>
R reversed(R range) {
	reverse(range);
	return range;
}

using namespace std;

class TaskB {
public:
	void solve(std::istream& in, std::ostream& out) {

		long long INF = (long long int) 3e18;
		int n, m;
		in >> n >> m;
		vector<long long> l(n), r(n);
		for(int i : range(n)) {
			in >> l[i] >> r[i];
		}

		vector<tuple<long long, long long, int>> segs(n - 1);
		for(int i: range(n - 1)) {
			segs[i] = make_tuple(l[i + 1] - r[i], r[i + 1] - l[i], i);
		}



		for(int i: range(m)) {
			long long  x;
			in >> x;
			segs.emplace_back(x, INF, i);
		}
		sort(segs);

		vector<int> ans(n);
		multiset<pair<long long, int>> open;
		for(auto p: segs) {
			long long pos, end;
			int id;
			tie(pos, end, id) = p;
			if(end == INF) {
				if(open.empty()) {
					continue;
				}
				if(open.begin()->first < pos) {
					break;
				}
				else {
					int rID = open.begin()->second;
					open.erase(open.begin());
					ans[rID] = id;
				}
			}
			else {
				open.insert(make_pair(end, id));
			}
		}

		if(!open.empty()) {
			out << "No\n";
			return;
		}

		out << "Yes\n";
		for(int i: range(n - 1))
			out << ans[i] + 1 << ' ';
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(0);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}