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







#include <algorithm>



template <typename R>
void sort(R& range) {
	std::sort(range.begin(), range.end());
}

template <typename R, typename Comp>
void sort(R& range, Comp comp) {
	std::sort(range.begin(), range.end(), comp);
}

template <typename R>
void reverse(R& range) {
	std::reverse(range.begin(), range.end());
}

template <typename R, typename T>
auto lower_bound(const R& range, const T& value) -> decltype(range.begin()) {
	return std::lower_bound(range.begin(), range.end(), value);
}

template <typename R, typename T, typename Comp>
auto lower_bound(const R& range, const T& value, Comp comp) -> decltype(range.begin()) {
	return std::lower_bound(range.begin(), range.end(), value, comp);
}

template <typename R, typename T>
auto upper_bound(const R& range, const T& value) -> decltype(range.begin()) {
	return std::upper_bound(range.begin(), range.end(), value);
}

template <typename R, typename T, typename Comp>
auto upper_bound(const R& range, const T& value, Comp comp) -> decltype(range.begin()) {
	return std::upper_bound(range.begin(), range.end(), value, comp);
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


template <typename T>
class CoordinateMinimizer {
public:
	CoordinateMinimizer() {
		#ifdef SPCPPL_DEBUG
			addingFinished = false;
		#endif
	}

	template <typename R>
	explicit CoordinateMinimizer(const R& range): values(range.begin(), range.end()) {
		finalize();
	}

	void finalize() {
		sort(values);
		values.erase(std::unique(values.begin(), values.end()), values.end());

		#ifdef SPCPPL_DEBUG
			addingFinished = true;
		#endif
	}

	void add(const T& t) {
		SPCPPL_ASSERT(!addingFinished);
		values.push_back(t);
	}

	void add(T&& t) {
		SPCPPL_ASSERT(!addingFinished);
		values.push_back(std::move(t));
	}

	std::size_t find(const T& t) {
		SPCPPL_ASSERT(addingFinished);
		auto iterator = lower_bound(values, t);
		// SPCPPL_ASSERT(iterator != values.end() && *iterator == t);
		return iterator - values.begin();
	}

	std::size_t size() {
		SPCPPL_ASSERT(addingFinished);
		return values.size();
	};

private:
	std::vector<T> values;
	#ifdef SPCPPL_DEBUG
		bool addingFinished;
	#endif
};



#include <functional>









#include <utility>

template <typename T>
constexpr auto hasBegin(int) -> decltype(std::begin(std::declval<T>()), true) {
	return true;
}

template <typename T>
constexpr bool hasBegin(...) {
	return false;
}

template <typename T>
using IsContainer = std::integral_constant<bool, hasBegin<T>(0)>;



#include <type_traits>

template <bool b, typename T = void>
//todo[c++14] use std::enable_if_t
using enable_if_t = typename std::enable_if<b, T>::type;



template <typename T, typename Merge>
class SegmentTreeBase {
protected:
	explicit SegmentTreeBase(std::size_t n, const T& defaultValue = T(), const Merge& merge = Merge()):
			n(n),
			defaultValue(defaultValue),
			shift(calculateShift(n)),
			values(shift << 1, defaultValue),
			merge(merge) {

	}

	template <typename R, typename = enable_if_t<IsContainer<R>::value>>
	explicit SegmentTreeBase(const R& range, const T& defaultValue = T(), const Merge& merge = Merge()) :
			SegmentTreeBase(
					static_cast<std::size_t>(std::distance(std::begin(range), std::end(range))),
					defaultValue,
					merge
			) {
		std::copy(std::begin(range), std::end(range), values.begin() + shift);
		for (std::size_t index: downrange(shift, static_cast<std::size_t>(1))) {
			recalculate(index);
		}
	}

	static std::size_t calculateShift(std::size_t n) {
		std::size_t result = 1;
		while (result < n) {
			result <<= 1;
		}
		return result;
	}

	void recalculate(std::size_t index) {
		values[index] = merge(values[2 * index], values[2 * index + 1]);
	}

	std::size_t n;
	T defaultValue;
	std::size_t shift;
	std::vector<T> values;
	Merge merge;
};


template <typename T, typename Merge>
class BottomUpSegmentTree: protected SegmentTreeBase<T, Merge> {
public:

	template <typename R>
	explicit BottomUpSegmentTree(const R& range, const T& defaultValue = T(), const Merge& merge = Merge()):
			SegmentTreeBase<T, Merge>(range, defaultValue, merge) {

	}

	const T& getElement(std::size_t index) {
		SPCPPL_ASSERT(index < n);
		return values[index + shift];
	}

	T getResult(std::size_t l, std::size_t r) const {
		SPCPPL_ASSERT(l <= r && r <= n);
		return internalGetResult(l + shift, r + shift);
	}

	template <typename Updater>
	void update(std::size_t index, const Updater& updater) {
		SPCPPL_ASSERT(index < n);
		index += shift;
		updater(values[index]);
		for (std::size_t parent = index / 2; parent > 0; parent /= 2) {
			this->recalculate(parent);
		}
	}

	void set(std::size_t index, const T& value) {
		return update(index, [&value](T& element) {
			element = value;
		});
	}

protected:
	using Base = SegmentTreeBase<T, Merge>;
	using Base::n;
	using Base::defaultValue;
	using Base::shift;
	using Base::values;
	using Base::merge;

private:
	T internalGetResult(std::size_t l, std::size_t r) const {
		if (l == r) {
			return defaultValue;
		}
		if (l & 1) {
			return merge(values[l], internalGetResult(l + 1, r));
		}
		if (r & 1) {
			return merge(internalGetResult(l, r - 1), values[r - 1]);
		}
		return internalGetResult(l / 2, r / 2);
	}
};


template <typename T>
class BottomUpSumSegmentTree: public BottomUpSegmentTree<T, std::plus<T>> {
public:
	template <typename R>
	explicit BottomUpSumSegmentTree(
			const R& range,
			const T& zero = T()
	): BottomUpSegmentTree<T, std::plus<T>>(range, zero) {
	}

};

//#define PROBLEM "problem_name.h"
//#include PROBLEM
//#include <message.h>
//#include <spcppl/dgcj.h>

using namespace std;

class DTokitsukazeIStranniiPryamougolnik {
public:
	static constexpr int kStressCount = 0;
	static void generateTest(std::ostream& test) {
	}
	void solve(std::istream& in, std::ostream& out) {
		//static int testnumber = 0;
		//out << "Case #" << ++testnumber << ": ";

		int n;
		in >> n;
		vector<pair<int, int>> p(n);
		for (int i: range(n)) {
			in >> p[i].first >> p[i].second;
		}

		auto by_y = [&](auto x, auto y) {
			return tie(x.second, x.first) < tie(y.second, y.first);
		};

		sort(p.begin(), p.end(), by_y);

		CoordinateMinimizer<int> cm;
		for (auto pt: p) {
			cm.add(pt.first);
		}

		cm.finalize();

		vector<int> counts(cm.size());
		for (auto pt: p) {
			++counts[cm.find(pt.first)];
		}

		for (auto& pt: p) {
			pt.first = cm.find(pt.first);
		}

		BottomUpSumSegmentTree<int> tree(cm.size());
		for (int i: range(cm.size())) {
			tree.set(i, 1);
		}

		int64_t ans = 0;
		for (int i = 0; i < p.size(); ++i) {
			int leftX;
			if (i == 0 || p[i].second != p[i - 1].second) {
				leftX = 0;
			} else {
				leftX = p[i - 1].first + 1;
			}

			int leftSum = tree.getResult(leftX, p[i].first);
			int rightSum = tree.getResult(p[i].first + 1, cm.size());

			ans += (leftSum + 1LL) * (rightSum + 1LL);

			if (--counts[p[i].first] == 0) {
				tree.set(p[i].first, 0);
			}
		}

		out << ans << "\n";
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	DTokitsukazeIStranniiPryamougolnik solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}