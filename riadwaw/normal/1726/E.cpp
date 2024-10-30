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




#include <assert.h>
#include <type_traits>




template <bool b, typename T = void>
//todo[c++14] use std::enable_if_t
using enable_if_t = typename std::enable_if<b, T>::type;











// todo[c++17]: replace with std::disjunction_v
template <bool... Bools>
struct Disjunction : std::false_type {
};

template <bool First, bool... Others>
// todo[c++14] use bool_constant
struct Disjunction<First, Others...> : std::integral_constant<bool, First || Disjunction<Others...>::value> {

};

#if __cplusplus >= 201703L
template <bool... Bools>
constexpr bool DisjunctionV = Disjunction<Bools...>::value;

static_assert(!DisjunctionV<>, "");
static_assert(!DisjunctionV<false, false>, "");
static_assert(DisjunctionV<true>, "");
static_assert(DisjunctionV<false, true>, "");
static_assert(DisjunctionV<true, false>, "");
static_assert(DisjunctionV<false, false, true, true>, "");
#endif

template <typename T, typename... Types>
// todo[c++17] use is_same_v
// todo[c++17] use variable template
using IsOneOf = Disjunction<std::is_same<T, Types>::value...>;


//todo[c++14] use remove_cv_t
//todo[c++17] use is_integral_v
//todo[c++17] use  variable template
template <typename T>
using IsSaneInteger = std::integral_constant<
		bool,
		std::is_integral<T>::value && !IsOneOf<typename std::remove_cv<T>::type, char, signed char, unsigned char, bool, char16_t, char32_t, wchar_t>::value
>;






template <typename T, typename = std::true_type>
struct IdentityHelper;

template <typename T>
struct IdentityHelper<T, typename std::is_arithmetic<T>::type> {
	static T identity() {
		return 1;
	}
};

template <typename T>
T identity() {
	return IdentityHelper<T>::identity();
}



/**
* ax + by = result
*/
template <typename T>
T extendedGcd(T a, T b, T& x, T& y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	T d = extendedGcd(b % a, a, y, x);
	x -= (b / a) * y;
	return d;
}

template <typename T>
class Zn {
public:
	Zn(): value(0) {
	}

	/**
	* Instead of ctor, to allow not to normalize in ctor
	*/
	template <typename U>
	static Zn valueOf(U value) {
		int x = static_cast<int>(value % mod());
		if (x < 0) {
			x += mod();
		}
		return Zn(x);
	}

	static Zn rawValueOf(int value) {
		SPCPPL_ASSERT(value >= 0 && value < mod());
		return Zn(value);
	}

	template <typename U>
	Zn& operator=(U rhs) {
		return *this = Zn::valueOf(rhs);
	}


	Zn& operator+=(const Zn& rhs) {
		value += rhs.value;
		if (value >= mod()) {
			value -= mod();
		}
		return *this;
	}

	template <typename U>
	Zn& operator+=(U rhs) {
		return *this += Zn::valueOf(rhs);
	}

	Zn& operator-=(const Zn& rhs) {
		value -= rhs.value;
		if (value < 0) {
			value += mod();
		}
		return *this;
	}

	template <typename U>
	Zn& operator-=(U rhs) {
		return *this -= Zn::valueOf(rhs);
	}

	Zn& operator*=(const Zn& rhs) {
		long long result = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
		value = static_cast<int>(result % mod());
		return *this;
	}

	template <typename U>
	Zn& operator*=(U rhs) {
		return *this *= Zn::valueOf(rhs);
	}

	Zn operator-() const {
		if (value == 0) {
			return *this;
		}
		else {
			return Zn(mod() - value);
		}
	}

	Zn& operator/=(const Zn& rhs) {
		return *this *= rhs.inversed();
	}

	template <typename U>
	Zn& operator/=(U rhs) {
		return *this /= Zn::valueOf(rhs);
	}

	Zn inversed() const {
		SPCPPL_ASSERT(value != 0);

		int x, y;
		int gcd = extendedGcd(value, mod(), x, y);
		(void) gcd;
		SPCPPL_ASSERT(gcd == 1);

		if (x < 0) {
			x += mod();
		}
		return Zn(x);
	}

	template <typename U>
	friend std::ostream& operator<<(std::ostream&, const Zn<U>& zn);

	template <typename U>
	friend std::istream& operator>>(std::istream&, Zn<U>& zn);

	template <typename U>
	friend bool operator==(const Zn<U>& lhs, const Zn<U>& rhs);

	int intValue() const {
		return value;
	}

private:
	/**
	* No normalization performed
	*/
	explicit Zn(int value): value(value) {
	}

	int value;

	constexpr static int mod() {
		return T::value;
	}

	template <int N = T::value>
	static constexpr bool correct_or_runtime(int) {
		return N > 0 && N <= (1 << 30);
	}
	static constexpr bool correct_or_runtime(...) {
		return true;
	}
	static_assert(
			std::is_same<typename std::decay<decltype(T::value)>::type, int>::value,
			"T::value must be int"
	);
	static_assert(correct_or_runtime(0), "Mod has to be positive integer up to 1 << 30");
};

template <typename T>
bool operator==(const Zn<T>& lhs, const Zn<T>& rhs) {
	return lhs.value == rhs.value;
}

template <typename T, typename U>
bool operator==(const Zn<T>& lhs, U rhs) {
	return lhs == Zn<T>::valueOf(rhs);
}

template <typename T, typename U>
bool operator==(U lhs, const Zn<T>& rhs) {
	return rhs == lhs;
}

template <typename T>
bool operator!=(const Zn<T>& lhs, const Zn<T>& rhs) {
	return !(lhs == rhs);
}

template <typename T, typename U>
bool operator!=(const Zn<T>& lhs, U rhs) {
	return !(lhs == rhs);
}

template <typename T, typename U>
bool operator!=(U lhs, const Zn<T>& rhs) {
	return !(lhs == rhs);
}

template <typename T>
Zn<T> operator+(const Zn<T>& lhs, const Zn<T>& rhs) {
	Zn<T> copy = lhs;
	return copy += rhs;
}

template <typename T, typename U>
Zn<T> operator+(const Zn<T>& lhs, U rhs) {
	Zn<T> copy = lhs;
	return copy += rhs;
}

template <typename T, typename U>
Zn<T> operator+(U lhs, const Zn<T>& rhs) {
	return rhs + lhs;
}

template <typename T>
Zn<T> operator-(const Zn<T>& lhs, const Zn<T>& rhs) {
	Zn<T> copy = lhs;
	return copy -= rhs;
}

template <typename T, typename U>
Zn<T> operator-(const Zn<T>& lhs, U rhs) {
	Zn<T> copy = lhs;
	return copy -= rhs;
}

template <typename T, typename U>
Zn<T> operator-(U lhs, const Zn<T>& rhs) {
	return Zn<T>::valueOf(lhs) - rhs;
}

template <typename T>
Zn<T> operator*(const Zn<T>& lhs, const Zn<T>& rhs) {
	Zn<T> copy = lhs;
	return copy *= rhs;
}

template <typename T, typename U>
Zn<T> operator*(const Zn<T>& lhs, U rhs) {
	Zn<T> copy = lhs;
	return copy *= rhs;
}

template <typename T, typename U>
Zn<T> operator*(U lhs, const Zn<T>& rhs) {
	return rhs * lhs;
}

template <typename T>
Zn<T> operator/(const Zn<T>& lhs, const Zn<T>& rhs) {
	Zn<T> copy = lhs;
	return copy /= rhs;
}

template <typename T, typename U>
Zn<T> operator/(const Zn<T>& lhs, U rhs) {
	Zn<T> copy = lhs;
	return copy /= rhs;
}

template <typename T, typename U>
Zn<T> operator/(U lhs, const Zn<T>& rhs) {
	return Zn<T>::valueOf(lhs) / rhs;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Zn<T>& zn) {
	return stream << zn.value;
}

template <typename T>
std::istream& operator>>(std::istream& stream, Zn<T>& zn) {
	int64_t value;
	stream >> value;
	zn.value = static_cast<int>(value % T::value);
	return stream;
}

template <typename T>
struct IdentityHelper<Zn<T>> {
	static Zn<T> identity() {
		return Zn<T>::valueOf(1);
	}
};

template <int m>
using ZnConst = Zn<std::integral_constant<int, m>>;

using Zn7 = ZnConst<1000000007>;




#include <cstddef>




template <typename T>
T factorial(std::size_t maxN) {
	T result = identity<T>();
	for (std::size_t i = 2; i <= maxN; ++i) {
		result *= static_cast<int64_t>(i);
	}
	return result;
}

template <typename T>
std::vector<T> factorials(std::size_t maxN) {
	std::vector<T> res(maxN + 1);
	res[0] = identity<T>();
	for (std::size_t i = 1; i <= maxN; ++i) {
		res[i] = res[i - 1] * static_cast<long long>(i);
	}
	return res;
}

template <typename T>
std::vector<std::vector<T>> binomials(std::size_t maxN) {
	std::vector<std::vector<T>> res(maxN + 1, std::vector<T>(maxN + 1));
	for (std::size_t n = 0; n <= maxN; ++n) {
		res[n][0] = identity<T>();
		res[n][n] = identity<T>();
		for (std::size_t k = 1; k < n; ++k) {
			res[n][k] = res[n - 1][k - 1] + res[n - 1][k];
		}
	}

	return res;
}

template <typename T, typename U, typename = enable_if_t<std::is_integral<U>::value>>
T binomial(U n, U k) {
	if (k > n || k < 0) {
		return T();
	}
	T res = identity<T>();
	for (U i: inclusiveRange<U>(1, k)) {
		res *= n - i + 1;
		res /= i;
	}
	return res;
};

template <typename T, typename U, typename = enable_if_t<std::is_integral<U>::value>>
std::vector<T> pascalTriangleRow(U n, U k) {
	SPCPPL_ASSERT(k >= 0);
	std::vector<T> result(k + 1);
	result[0] = identity<T>();
	for (U i: inclusiveRange<U>(1, k)) {
		result[i] = result[i - 1] * (n - i + 1) / i;
	}
	return result;
};

template <typename T, typename U, typename = enable_if_t<std::is_integral<U>::value>>
std::vector<T> pascalTriangleRow(U n) {
	return pascalTriangleRow<T>(n, n);
};

template <typename T, typename U, typename = enable_if_t<std::is_integral<U>::value>>
T starsAndBars(U stars, U groups) {
	if (groups == 0) {
		if (stars == 0) {
			return identity<T>();
		} else {
			return T();
		}
	}
	return binomial<T>(stars + groups - 1, groups - 1);
};

//#define PROBLEM "problem_name.h"
//#include PROBLEM
//#include <message.h>
//#include <spcppl/dgcj.h>

using namespace std;

class EPochtiIdealno {
public:
	static constexpr int kStressCount = 0;

	static void generateTest(std::ostream &test) {
	}

	using Z = ZnConst<998244353>;

	Z solve(int n) {

		vector<Z> d(n + 1);
		d[0] = 1;

		for (int i: inclusiveRange(1, n)) {
			d[i] = d[i - 1];
			if (i >= 2) {
				d[i] += d[i - 2] * (i - 1);
			}
		}

		vector<Z> pairings(n + 1);
		pairings[0] = 1;
		pairings[1] = 0;
		for (int i: inclusiveRange(2, n)) {
			pairings[i] = pairings[i - 2] * (i - 1);
		}

		vector<Z> power2(n + 1);
		power2[0] = 1;
		for (int i: inclusiveRange(1, n)) {
			power2[i] = power2[i - 1] * 2;
		}
		vector<Z> fact(n + 1);
		vector<Z> invfact(n + 1);
		fact[0] = 1;
		invfact[0] = 1;
		for (int i: inclusiveRange(1, n)) {
			fact[i] = fact[i - 1] * i;
			invfact[i] = 1 / fact[i];
		}

		Z ans;
		for (int pairs = 0; pairs * 4 <= n; ++pairs) {
//			cerr << pairs << ' ' << d[n - pairs * 4] * pairings[2 * pairs] * power2[pairs] << endl;
			int cnt = 2 * pairs + (n - pairs * 4);
			ans += d[n - pairs * 4] * pairings[2 * pairs] * power2[pairs] * fact[cnt] * invfact[2 * pairs] *
					invfact[n - pairs * 4];
		}
		return ans;
	}

	Z stupid_solve(int n) {
		vector<int> a(n);
		int ans = 0;
		for (int i: range(n)) {
			a[i] = i;
		}
		do {
			vector<int> inv(n);

			for (int i: range(n)) {
				inv[a[i]] = i;
			}


			bool all_close = true;
			for (int i: range(n)) {
				if (abs(a[i] - inv[i]) > 1) {
					all_close = false;
					break;
				}
			}
			if (all_close) {
				++ans;
				for (int i: range(n)) {
					cerr << a[i] << " ";
				}
				cerr << endl;
			}
		} while (next_permutation(a.begin(), a.end()));
		return Z::rawValueOf(ans);
	}

	void solve(std::istream &in, std::ostream &out) {
		//static int testnumber = 0;
		//out << "Case #" << ++testnumber << ": ";
		//cerr << "test " << testnumber << endl;

		int n;
		in >> n;

//		solve(5);
//		stupid_solve(5);
//		for (int i: inclusiveRange(1, 7)) {
//			Z ans = solve(i);
//			Z stupid_ans = stupid_solve(i);
//			out << i << " " <<  ans << ' ' << stupid_ans << "\n";
//		}

		out << solve(n) << "\n";
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	EPochtiIdealno solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

	return 0;
}