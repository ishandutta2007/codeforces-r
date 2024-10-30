/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>
#include <map>


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

//#include <spcppl/dataStructures/TreapMultiset.hpp>
//#define PROBLEM "problem_name.h"
//#include PROBLEM
//#include <message.h>
//#include <spcppl/dgcj.h>

using namespace std;

template<typename T>
struct TD;

class DZaprosiNaDedukciyu {
public:
	void solve(std::istream& in, std::ostream& out) {
		//static int testnumber = 0;
		//out << "Case #" << ++testnumber << ": ";
		int q;
		in >> q;

		struct S {
			int root;
			int xor_from_root;
		};
		map<int, S> root;
		map<int, vector<int>> rootNodes;
		int last = 0;
		for (int _: range(q)) {
			int t;
			in >> t;

			if (t == 1) {
				int l, r, x;
				in >> l >> r >> x;
				l ^= last;
				r ^= last;
				x ^= last;
				if (l > r) {
					swap(l, r);
				}
				//cerr <<1 <<' '<< l << ' ' << r << ' ' << x << endl;
				++r;

				auto itl = root.find(l);
				if (itl == root.end()) {
					itl = root.emplace(l, S{l, 0}).first;
					rootNodes[l] = {l};
				}

				auto itr = root.find(r);
				if (itr == root.end()) {
					itr = root.emplace(r, S{r, 0}).first;
					rootNodes[r] = {r};
				}

				if (itl->second.root == itr->second.root) {
					continue;
				}
				auto l_root = itl->second.root;
				auto r_root = itr->second.root;
				auto* l_nodes = &rootNodes[l_root];
				auto* r_nodes = &rootNodes[r_root];
				if (l_nodes->size() < r_nodes->size()) {
					swap(l, r);
					swap(l_nodes, r_nodes);
					swap(l_root, r_root);
				}
				auto to_xor = itl->second.xor_from_root ^ x ^ itr->second.xor_from_root;

				for (auto v: *r_nodes) {
					auto& node = root[v];
					node.root = l_root;
					node.xor_from_root ^= to_xor;
				}
				l_nodes->insert(l_nodes->end(), r_nodes->begin(), r_nodes->end());
				r_nodes->clear();
			} else {
				int ls, rs;
				in >> ls >> rs;
				int l = ls ^ last;
				int r = rs ^ last;
				if (l > r) {
					swap(l, r);
				}
				//cerr << 2  << ' ' << l << ' ' << r << endl;
				++r;

				auto itl = root.find(l);
				auto itr = root.find(r);
				if (itl == root.end() || itr == root.end() || itl->second.root != itr->second.root) {
					out << -1 << "\n";
					last = 1;
				} else {
					int res = itl->second.xor_from_root ^ itr->second.xor_from_root;
					out << res << "\n";
					last = res;
				}
			}
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	DZaprosiNaDedukciyu solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}