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
#include <algorithm>
#include <array>


template <typename T>
bool updateMin(T& oldValue, const T& newValue) {
	if (newValue < oldValue) {
		oldValue = newValue;
		return true;
	}
	return false;
}

template <typename T>
bool updateMax(T& oldValue, const T& newValue) {
	if (oldValue < newValue) {
		oldValue = newValue;
		return true;
	}
	return false;
}



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




struct Min {
	template <typename T>
	T operator()(const T& l, const T& r) const {
		return std::min(l, r);
	}
};



#include <cstddef>







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


template <typename T, typename Merge, typename Update, typename ApplyUpdate, typename MergeUpdates>
class TopDownSegmentTree: protected SegmentTreeBase<T, Merge> {
	using size_t = std::size_t;
	using Base = SegmentTreeBase<T, Merge>;
public:
	template <typename R>
	explicit TopDownSegmentTree(
			const R& range,
			const T& defaultValue = T(),
			const Merge& merge = Merge(),
			const Update& defaultUpdate = Update(),
			const ApplyUpdate& applyUpdate = ApplyUpdate(),
			const MergeUpdates& mergeUpdates = MergeUpdates()
	):
			Base(range, defaultValue, merge),
			defaultUpdate(defaultUpdate),
			updates(shift << 1, defaultUpdate),
			applyUpdate(applyUpdate),
			mergeUpdates(mergeUpdates) {

	}

	void update(size_t l, size_t r, const Update& update) {
		SPCPPL_ASSERT(l <= r && r <= n);
		return internalUpdate(1, 0, shift, l, r, update);
	}

	T getResult(size_t l, size_t r) {
		SPCPPL_ASSERT(l <= r && r <= n);
		return internalGet(1, 0, shift, l, r);
	}

	template <typename Visitor>
	std::size_t descend(Visitor visit) {
		size_t v = 1;
		std::size_t vl = 0;
		std::size_t vr = shift;
		while (v < shift) {
			push(v, vl, vr);
			std::size_t vm = vl + (vr - vl) / 2;
			if (visit(values[v], values[2 * v], values[2 * v + 1])) {
				v = 2 * v;
				vr = vm;
			} else {
				v = 2 * v + 1;
				vl = vm;
			}
		}
		return v - shift;
	}

	template <typename Predicate>
	std::size_t getFirstPrefix(Predicate predicate) {
		if (predicate(defaultValue)) {
			return 0;
		}
		if (!predicate(values[1])) {
			return n + 1;
		}
		T current_left = defaultValue;
		return descend([&](const T&, const T& l, const T&) {
			auto new_left = merge(current_left, l);
			if (predicate(new_left)) {
				return true;
			} else {
				current_left = std::move(new_left);
				return false;
			}
		}) + 1;
	}

protected:
	using Base::n;
	using Base::defaultValue;
	using Base::shift;
	using Base::values;
	using Base::merge;
private:

	void internalUpdate(size_t v, size_t vl, size_t vr, size_t l, size_t r, const Update& update) {
		if (r <= vl || l >= vr) {
			return;
		}
		if (l <= vl && vr <= r) {
			values[v] = applyUpdate(values[v], update, vl, vr);
			updates[v] = mergeUpdates(updates[v], update);
			return;
		}
		push(v, vl, vr);
		size_t vm = vl + (vr - vl) / 2;
		internalUpdate(2 * v, vl, vm, l, r, update);
		internalUpdate(2 * v + 1, vm, vr, l, r, update);
		this->recalculate(v);
	}

	T internalGet(size_t v, size_t vl, size_t vr, size_t l, size_t r) {
		if (r <= vl || l >= vr) {
			return defaultValue;
		}
		if (l <= vl && vr <= r) {
			return values[v];
		}
		push(v, vl, vr);
		size_t vm = vl + (vr - vl) / 2;
		return merge(
				internalGet(2 * v, vl, vm, l, r),
				internalGet(2 * v + 1, vm, vr, l, r)
		);
	}

	void push(size_t v, size_t vl, size_t vr) {
		size_t vm = vl + (vr - vl) / 2;
		values[2 * v] = applyUpdate(values[2 * v], updates[v], vl, vm);
		updates[2 * v] = mergeUpdates(updates[2 * v], updates[v]);
		values[2 * v + 1] = applyUpdate(values[2 * v + 1], updates[v], vm, vr);
		updates[2 * v + 1] = mergeUpdates(updates[2 * v + 1], updates[v]);

		updates[v] = defaultUpdate;
	}

	Update defaultUpdate;
	std::vector<Update> updates;
	ApplyUpdate applyUpdate;
	MergeUpdates mergeUpdates;
};






template <typename T, typename Merge>
class BottomUpSegmentTree: protected SegmentTreeBase<T, Merge> {
	using Base = SegmentTreeBase<T, Merge>;

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

	template <typename Visitor>
	std::size_t descend(Visitor visit) const {
		size_t v = 1;
		while (v < shift) {
			if (visit(values[v], values[2 * v], values[2 * v + 1])) {
				v = 2 * v;
			} else {
				v = 2 * v + 1;
			}
		}
		return v - shift;
	}

protected:
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

//#define PROBLEM "problem_name.h"
//#include PROBLEM
//#include <message.h>
//#include <spcppl/dgcj.h>

using namespace std;

struct ApplyUpdate {
	template <typename T>
	int operator() (int v, int u, T vl, T vr) const {
		return min(v, u);
	}
};

class CAnonimnostNasheVse {
public:
	static constexpr int kStressCount = 0;
	static void generateTest(std::ostream& test) {
	}
	void solve(std::istream& in, std::ostream& out) {
		//static int testnumber = 0;
		//out << "Case #" << ++testnumber << ": ";
		//cerr << "test " << testnumber << endl;

		constexpr int inf = 1000000000;
		struct Val {
			int first_max = inf;
			int second_max = -1;
		};



		int n, q;
		in >> n >> q;

		TopDownSegmentTree<int, Min, int, ApplyUpdate, Min> tree(n, inf, Min(), inf);

		vector<array<int, 4>> queries(q);
		for (int i: range(q)) {
			in >> queries[i][0];
			if (queries[i][0] == 1) {
				in >> queries[i][1];
				--queries[i][1];
			} else {
				in >> queries[i][1];
				--queries[i][1];
				in >> queries[i][2];
				in >> queries[i][3];
				if (queries[i][3] == 0) {
					tree.update(queries[i][1], queries[i][2], i);
				}
			}
		}

		struct TwoMax {
			array<int, 2> x = {-1, -1};
			int index_of_max = -1;
		};

		struct Merge {
			TwoMax operator() (TwoMax a, TwoMax b) const {
				array<int, 4> res = {a.x[0], a.x[1], b.x[0], b.x[1]};
				sort(res.begin(), res.end(), greater<>());
				return {res[0], res[1], a.x[0] > b.x[0] ? a.index_of_max : b.index_of_max};
			}
		};

		vector<TwoMax> when_understood_zero(n);
		for (int i: range(n)) {
			when_understood_zero[i].x[0] = tree.getResult(i, i + 1);
			when_understood_zero[i].index_of_max = i;
		}


		BottomUpSegmentTree<TwoMax, Merge> max_tree(when_understood_zero);


		vector<int> when_understood_one(n, inf);

		for (int i: range(q)) {
			if (queries[i][0] == 0 && queries[i][3] == 1) {
				auto z = max_tree.getResult(queries[i][1], queries[i][2]);
				int when_really_understood = max(i, z.x[1]);
				updateMin(when_understood_one[z.index_of_max], when_really_understood);
			}
		}

		for (int i: range(q)) {
			if (queries[i][0] == 1) {
				if (when_understood_zero[queries[i][1]].x[0] < i) {
					out << "NO\n";
				} else if (when_understood_one[queries[i][1]] < i) {
					out << "YES\n";
				} else {
					out << "N/A\n";
				}
			}
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	CAnonimnostNasheVse solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}