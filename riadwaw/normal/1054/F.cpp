/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cassert>
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



#include <utility>

template <typename Range, typename Function>
void pairwiseMerge(Range& range, Function function) {
	auto output = range.begin();
	auto end = range.end();
	if (output == end) {
		return;
	}
	auto current = output;
	++current;
	for (;current != end; ++current) {
		if (!function(*output, *current)) {
			++output;
			*output = std::move(*current);
		}
	}

	++output;
	range.erase(output, end);
}








struct Bool {
	Bool() = default;

	/* implicit */ Bool(bool value): value(value) {

	}

	operator bool() const {
		return value;
	}

private:
	bool value;
};



namespace impl {

constexpr std::size_t noPair = std::numeric_limits<std::size_t>::max();

class KuhnDfser {
public:
	KuhnDfser(
			const std::vector<std::vector<std::size_t>>& graph,
			std::vector<std::size_t>& mt
	): graph(graph), mt(mt), used(graph.size()) {
	}

	bool tryKuhn(std::size_t v) {
		if (used[v]) {
			return false;
		}
		used[v] = true;
		for (std::size_t i: range(graph[v].size())) {
			auto to = graph[v][i];
			if (mt[to] == noPair || tryKuhn(mt[to])) {
				mt[to] = v;
				return true;
			}
		}
		return false;
	}

	void clearUsed() {
		std::fill(used.begin(), used.end(), false);
	}

private:
	const std::vector<std::vector<std::size_t>>& graph;
	std::vector<std::size_t>& mt;
	std::vector<Bool> used;
};

class IndependentSetFinder {
public:
	IndependentSetFinder(
			const std::vector<std::vector<std::size_t>>& graph,
			std::vector<std::size_t>& mt
	):
			graph(graph),
			mt(mt),
			inAnswerLeft(graph.size(), true),
			inAnswerRight(mt.size(), true),
			inMatchLeft(graph.size()) {
	}

	std::pair<std::vector<Bool>, std::vector<Bool>> find() {
		for (auto v: mt) {
			if (v != noPair) {
				inMatchLeft[v] = true;
				inAnswerLeft[v] = false;
			}
		}
		for (auto i: range(graph.size())) {
			if (!inMatchLeft[i]) {
				dfs(i);
			}
		}
		return {inAnswerLeft, inAnswerRight};
	}

private:

	void dfs(std::size_t v) {
		for (auto to: graph[v]) {
			if (inAnswerRight[to]) {
				inAnswerRight[to] = false;
				SPCPPL_ASSERT(mt[to] != noPair);
				SPCPPL_ASSERT(!inAnswerLeft[mt[to]]);
				inAnswerLeft[mt[to]] = true;
				dfs(mt[to]);
			}
		}
	}

	const std::vector<std::vector<std::size_t>>& graph;
	std::vector<std::size_t>& mt;
	std::vector<Bool> inAnswerLeft;
	std::vector<Bool> inAnswerRight;
	std::vector<Bool> inMatchLeft;
};

}  // namespace impl

std::pair<std::vector<std::size_t>, std::vector<std::size_t>> findIndependentSetInBipartiteGraph(
		const std::vector<std::vector<std::size_t>>& graph,
		std::size_t rightSize
) {
	std::size_t leftSize = graph.size();

	std::vector<std::size_t> mt(rightSize, impl::noPair);

	impl::KuhnDfser dfser(graph, mt);
	for (auto v: range(leftSize)) {
		dfser.clearUsed();
		dfser.tryKuhn(v);
	}

	impl::IndependentSetFinder finder(graph, mt);
	auto maps = finder.find();

	auto indices = [](const std::vector<Bool>& map) {
		std::vector<std::size_t> result;
		result.reserve(map.size());
		for (auto index: range(map.size())) {
			if (map[index]) {
				result.push_back(index);
			}
		}
		return result;
	};
	return {
			indices(maps.first),
			indices(maps.second)
	};
}

//#define PROBLEM "problem_name.h"
//#include PROBLEM
//#include <message.h>
//#include <spcppl/dgcj.h>

using namespace std;


struct Segment {
	int fixed;
	int from;
	int to;
};

class TaskF {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n = 1000;
		in >> n;
		vector<pair<int, int>> points(n);
		for (int i: range(n)) {
			in >> points[i].first >> points[i].second;
			//points[i] = {randomInteger(2000), randomInteger(2000)};
		}

		assert((set<pair<int, int>>(points.begin(), points.end()).size() == n));


		vector<Segment> answerHorizontal(n);
		vector<Segment> answerVertical(n);

		for (int i = 0; i < n; ++i) {
			answerHorizontal[i] = Segment{points[i].first, points[i].second, points[i].second};
			answerVertical[i] = Segment{points[i].second, points[i].first, points[i].first};
		}

		vector<Segment> potentialHorizontal;
		vector<Segment> potentialVertical;

		sort(points.begin(), points.end());
		for (int i = 0; i + 1 < n; ++i) {
			auto& a = points[i];
			auto& b = points[i + 1];
			if (a.first == b.first && a.second + 1 < b.second) {
				potentialHorizontal.push_back(Segment{a.first, a.second + 1, b.second - 1});
			}
		}

		sort(
				points.begin(), points.end(), [](auto& p, auto& q) {
					return tie(p.second, p.first) < tie(q.second, q.first);
				}
		);

		for (int i = 0; i + 1 < n; ++i) {
			auto& a = points[i];
			auto& b = points[i + 1];
			if (a.second == b.second && a.first + 1 < b.first) {
				potentialVertical.push_back(Segment{a.second, a.first + 1, b.first - 1});
			}
		}

		vector<vector<size_t>> g(potentialHorizontal.size());


		for (auto i: range(potentialHorizontal.size())) {
			auto& hor = potentialHorizontal[i];
			for (auto j: range(potentialVertical.size())) {
				auto& vert = potentialVertical[j];
				if (hor.fixed >= vert.from && hor.fixed <= vert.to) {
					if (vert.fixed >= hor.from && vert.fixed <= hor.to) {
						g[i].push_back(j);
					}
				}
			}
		}

		auto independent_sets = findIndependentSetInBipartiteGraph(g, potentialVertical.size());
		for (auto x: independent_sets.first) {
			answerHorizontal.push_back(potentialHorizontal[x]);
		}
		for (auto x: independent_sets.second) {
			answerVertical.push_back(potentialVertical[x]);
		}

		auto output = [&](vector<Segment>& answer, bool swap) {
			sort(answer.begin(), answer.end(), [](const Segment& l, const Segment& r) {
				return tie(l.fixed, l.from, l.to) < tie(r.fixed, r.from, r.to);
			});

			pairwiseMerge(answer, [](Segment& l, const Segment& r) {
				if (l.fixed == r.fixed && l.to + 1 == r.from) {
					l.to = r.to;
					return true;
				} else {
					return false;
				}
			});

			out << answer.size() << "\n";
			for (const auto& l: answer) {
				if (swap) {
					out << l.from << ' ' << l.fixed << ' ' << l.to << ' ' << l.fixed << "\n";
				} else {
					out << l.fixed << ' ' << l.from << ' ' << l.fixed << ' ' << l.to << "\n";
				}
			}
		};

		output(answerVertical, true);
		output(answerHorizontal, false);

		int cnt = 0;
		vector<pair<int, int>> found_points;
		for (auto i: range(answerHorizontal.size())) {
			auto& hor = answerHorizontal[i];
			for (auto j: range(answerVertical.size())) {
				auto& vert = answerVertical[j];
				if (hor.fixed >= vert.from && hor.fixed <= vert.to) {
					if (vert.fixed >= hor.from && vert.fixed <= hor.to) {
						++cnt;
						found_points.push_back({hor.fixed, vert.fixed});
					}
				}
			}
		}
		assert(sorted(points) == sorted(found_points));
	}
};
template class std::vector<Segment>;


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskF solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}