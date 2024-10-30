/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>


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



#include <functional>





#include <vector>



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
struct IsContainer: std::integral_constant<bool, hasBegin<T>(0)> {
};



template <typename T, typename Merge>
class SegmentTreeBase {
protected:
	SegmentTreeBase(std::size_t n, const T& defaultValue = T(), const Merge& merge = Merge()):
			n(n),
			defaultValue(defaultValue),
			shift(calculateShift(n)),
			values(shift << 1, defaultValue),
			merge(merge) {

	}

	template <typename R, typename Enable = typename std::enable_if<IsContainer<R>::value>::type>
	SegmentTreeBase(const R& range, const T& defaultValue = T(), const Merge& merge = Merge()) :
			SegmentTreeBase(std::distance(std::begin(range), std::end(range)), defaultValue, merge) {
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
	BottomUpSegmentTree(const R& range, const T& defaultValue = T(), const Merge& merge = Merge()):
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
	typedef SegmentTreeBase<T, Merge> Base;
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
	BottomUpSumSegmentTree(
			const R& range,
			const T& zero = T()
	): BottomUpSegmentTree<T, std::plus<T>>(range, zero) {
	}

};


using namespace std;

class TaskC {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, k, a, b, q;
		in >> n >> k >> a >> b >> q;
		BottomUpSumSegmentTree<int> treeA(n), treeB(n);
		for (int _: range(q)) {
			int t;
			in >> t;
			if (t == 1) {
				int d, cnt;
				in >> d >> cnt;
				--d;
				treeA.update(d, [&](int& x) {
					x = min(x + cnt, a);
				});
				treeB.update(d, [&](int& x) {
					x = min(x + cnt, b);
				});
			} else {
				int d;
				in >> d;
				--d;
				out << treeB.getResult(0, d) + treeA.getResult(d + k, n) << "\n";
			}
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskC solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(0);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}