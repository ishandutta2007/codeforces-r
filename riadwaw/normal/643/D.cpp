/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>
#include <tuple>
#include <set>


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
	explicit IntegerIterator(int value): value(value) {

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

	bool operator==(IntegerIterator rhs) {
		return value == rhs.value;
	}

	bool operator!=(IntegerIterator rhs) {
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


using namespace std;

class TaskD {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, q;
		in >> n >> q;
		vector<int64_t> t(n);
		vector<int> parent(n);
		for (int i: range(n)) {
			in >> t[i];
		}
		vector<int> deg(n);
		for (int i: range(n)) {
			in >> parent[i];
			--parent[i];
			++deg[parent[i]];
		}

		vector<int64_t> fromSelfAndChildren(n);

		vector<int64_t> fromParentByParent(n);

		auto to_self = [&](int i) {
			return t[i] - t[i] / (deg[i] + 2) * (deg[i] + 1);
		};

		auto to_nei = [&](int i) {
			return t[i] / (deg[i] + 2);
		};


		for (int i: range(n)) {
			fromSelfAndChildren[i] += to_self(i);
			fromSelfAndChildren[parent[i]] += to_nei(i);

			fromParentByParent[i] = to_nei(i);
		}

		auto byFromSelfAndChildren = [&](int a, int b) {
			return tie(fromSelfAndChildren[a], a) < tie(fromSelfAndChildren[b], b);
		};
		vector<set<int, decltype(byFromSelfAndChildren)>> childrenOrder(n, set<int, decltype(byFromSelfAndChildren)>(byFromSelfAndChildren));

		for (int i: range(n)) {
			childrenOrder[parent[i]].insert(i);
		}

		auto getAll = [&](int a) {
			return fromSelfAndChildren[a] + fromParentByParent[parent[a]];
		};

		auto byAll = [&](int a, int b) {
			return make_pair(getAll(a), a) <
			       make_pair(getAll(b), b);
		};

		set<int, decltype(byAll)> globalMn(byAll);
		set<int, decltype(byAll)> globalMx(byAll);

		for (int i: range(n)) {
			if (!childrenOrder[i].empty()) {
				globalMn.insert(*childrenOrder[i].begin());
				globalMx.insert(*childrenOrder[i].rbegin());
			}
		}
		for (int _: range(q)) {
			int z;
			in >> z;
			if (z == 2) {
				int c;
				in >> c;
				--c;
				out << getAll(c) << "\n";
			} else if (z == 3) {
				out << getAll(*globalMn.begin()) << ' ' << getAll(*globalMx.rbegin()) << "\n";
			} else {
				int a, c;
				in >> a >> c;
				--a, --c;
				auto do_smth = [&](int change_degree, int to) {
					int dad = parent[to];
					if (!childrenOrder[dad].empty()) {
						globalMn.erase(*childrenOrder[dad].begin());
						globalMx.erase(*childrenOrder[dad].rbegin());
					}
					childrenOrder[dad].erase(to);
					if (!childrenOrder[to].empty()) {
						globalMn.erase(*childrenOrder[to].begin());
						globalMx.erase(*childrenOrder[to].rbegin());
					}
					if (change_degree == -1) {
						childrenOrder[to].erase(a);
					}

					int daddad = parent[dad];
					if (!childrenOrder[daddad].empty()) {
						globalMn.erase(*childrenOrder[daddad].begin());
						globalMx.erase(*childrenOrder[daddad].rbegin());
					}

					childrenOrder[daddad].erase(dad);

					fromSelfAndChildren[dad] -= to_nei(to);
					fromSelfAndChildren[to] -= to_self(to);

					fromSelfAndChildren[to] += change_degree * to_nei(a);
					deg[to] += change_degree;
					fromParentByParent[to] = to_nei(to);

					fromSelfAndChildren[dad] += to_nei(to);
					fromSelfAndChildren[to] += to_self(to);

					childrenOrder[daddad].insert(dad);
					if (!childrenOrder[daddad].empty()) {
						globalMn.insert(*childrenOrder[daddad].begin());
						globalMx.insert(*childrenOrder[daddad].rbegin());
					}
					if (change_degree == 1) {
						childrenOrder[to].insert(a);
					}
					if (!childrenOrder[to].empty()) {
						globalMn.insert(*childrenOrder[to].begin());
						globalMx.insert(*childrenOrder[to].rbegin());
					}
					childrenOrder[dad].insert(to);
					if (!childrenOrder[dad].empty()) {
						globalMn.insert(*childrenOrder[dad].begin());
						globalMx.insert(*childrenOrder[dad].rbegin());
					}
				};

				do_smth(-1, parent[a]);
				parent[a] = c;
				do_smth(1, parent[a]);
				int ttt = 3;
			}
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskD solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(0);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}