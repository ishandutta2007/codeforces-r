/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>



#include <assert.h>
#include <type_traits>


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
	static Zn valueOf(int value) {
		int x = value % mod();
		if (x < 0) {
			x += mod();
		}
		return Zn(x);
	}

	static Zn valueOf(long long value) {
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

	Zn& operator=(int rhs) {
		return *this = Zn::valueOf(rhs);
	}

	Zn& operator=(long long rhs) {
		return *this = Zn::valueOf(rhs);
	}

	Zn& operator+=(const Zn& rhs) {
		value += rhs.value;
		if (value >= mod()) {
			value -= mod();
		}
		return *this;
	}

	Zn& operator+=(int rhs) {
		return *this += Zn::valueOf(rhs);
	}

	Zn& operator+=(long long rhs) {
		return *this += Zn::valueOf(rhs);
	}

	Zn& operator-=(const Zn& rhs) {
		value -= rhs.value;
		if (value < 0) {
			value += mod();
		}
		return *this;
	}

	Zn& operator-=(int rhs) {
		return *this -= Zn::valueOf(rhs);
	}

	Zn& operator-=(long long rhs) {
		return *this -= Zn::valueOf(rhs);
	}

	Zn& operator*=(const Zn& rhs) {
		long long result = static_cast<long long>(value) * static_cast<long long>(rhs.value);
		value = static_cast<int>(result % mod());
		return *this;
	}

	Zn& operator*=(int rhs) {
		return *this *= Zn::valueOf(rhs);
	}

	Zn& operator*=(long long rhs) {
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

	Zn& operator/=(int rhs) {
		return *this /= Zn::valueOf(rhs);
	}

	Zn& operator/=(long long rhs) {
		return *this /= Zn::valueOf(rhs);
	}

	bool operator==(const Zn& rhs) const {
		return value == rhs.value;
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
	static constexpr bool positive_or_runtime(int) {
		return N > 0;
	}
	static constexpr bool positive_or_runtime(...) {
		return true;
	}
	static_assert(
			std::is_same<typename std::decay<decltype(T::value)>::type, int>::value,
			"T::value must be int"
	);
	static_assert(positive_or_runtime(0), "Mod has to be positive integer");
};

template <typename T>
bool operator==(const Zn<T>& lhs, int rhs) {
	return lhs == Zn<T>::valueOf(rhs);
}

template <typename T>
bool operator==(int lhs, const Zn<T>& rhs) {
	return rhs == lhs;
}
template <typename T>
bool operator==(const Zn<T>& lhs, long long rhs) {
	return lhs == Zn<T>::valueOf(rhs);
}

template <typename T>
bool operator==(long long lhs, Zn<T>& rhs) {
	return rhs == lhs;
}

template <typename T>
bool operator!=(const Zn<T>& lhs, const Zn<T>& rhs) {
	return !(lhs == rhs);
}

template <typename T>
bool operator!=(const Zn<T>& lhs, int rhs) {
	return !(lhs == rhs);
}

template <typename T>
bool operator!=(int lhs, const Zn<T>& rhs) {
	return !(lhs == rhs);
}

template <typename T>
bool operator!=(const Zn<T>& lhs, long long rhs) {
	return !(lhs == rhs);
}

template <typename T>
bool operator!=(long long rhs, const Zn<T>& lhs) {
	return !(lhs == rhs);
}

template <typename T>
Zn<T> operator+(const Zn<T>& lhs, const Zn<T>& rhs) {
	Zn<T> copy = lhs;
	return copy += rhs;
}

template <typename T>
Zn<T> operator+(const Zn<T>& lhs, int rhs) {
	Zn<T> copy = lhs;
	return copy += rhs;
}

template <typename T>
Zn<T> operator+(int lhs, const Zn<T>& rhs) {
	return rhs + lhs;
}

template <typename T>
Zn<T> operator+(const Zn<T>& lhs, long long rhs) {
	Zn<T> copy = lhs;
	return copy += rhs;
}

template <typename T>
Zn<T> operator+(long long lhs, const Zn<T>& rhs) {
	return rhs + lhs;
}

template <typename T>
Zn<T> operator-(const Zn<T>& lhs, const Zn<T>& rhs) {
	Zn<T> copy = lhs;
	return copy -= rhs;
}

template <typename T>
Zn<T> operator-(const Zn<T>& lhs, int rhs) {
	Zn<T> copy = lhs;
	return copy -= rhs;
}

template <typename T>
Zn<T> operator-(int lhs, const Zn<T>& rhs) {
	return Zn<T>::valueOf(lhs) - rhs;
}

template <typename T>
Zn<T> operator-(const Zn<T>& lhs, long long rhs) {
	Zn<T> copy = lhs;
	return copy -= rhs;
}

template <typename T>
Zn<T> operator-(long lhs, const Zn<T>& rhs) {
	return Zn<T>::valueOf(lhs) - rhs;
}

template <typename T>
Zn<T> operator*(const Zn<T>& lhs, const Zn<T>& rhs) {
	Zn<T> copy = lhs;
	return copy *= rhs;
}

template <typename T>
Zn<T> operator*(const Zn<T>& lhs, int rhs) {
	Zn<T> copy = lhs;
	return copy *= rhs;
}

template <typename T>
Zn<T> operator*(int lhs, const Zn<T>& rhs) {
	return rhs * lhs;
}

template <typename T>
Zn<T> operator*(const Zn<T>& lhs, long long rhs) {
	Zn<T> copy = lhs;
	return copy *= rhs;
}

template <typename T>
Zn<T> operator*(long long lhs, const Zn<T>& rhs) {
	return rhs * lhs;
}

template <typename T>
Zn<T> operator/(const Zn<T>& lhs, const Zn<T>& rhs) {
	Zn<T> copy = lhs;
	return copy /= rhs;
}

template <typename T>
Zn<T> operator/(const Zn<T>& lhs, int rhs) {
	Zn<T> copy = lhs;
	return copy /= rhs;
}

template <typename T>
Zn<T> operator/(int lhs, const Zn<T>& rhs) {
	return Zn<T>::valueOf(lhs) / rhs;
}

template <typename T>
Zn<T> operator/(const Zn<T>& lhs, long long rhs) {
	Zn<T> copy = lhs;
	return copy /= rhs;
}

template <typename T>
Zn<T> operator/(long long lhs, const Zn<T>& rhs) {
	return Zn<T>::valueOf(lhs) / rhs;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Zn<T>& zn) {
	return stream << zn.value;
}

template <typename T>
std::istream& operator>>(std::istream& stream, Zn<T>& zn) {
	long long value;
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



#include <vector>


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



#include <iterator>


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








template <typename T>
T gcd(T a, T b) {
	while (b) {
		T tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

template <typename T>
class Rational {
public:
	Rational(): numerator(0), denominator(1) {
	}

	Rational(T numerator): numerator(numerator), denominator(1) {
	}

	Rational(T numerator, T denominator): numerator(numerator), denominator(denominator) {
		SPCPPL_ASSERT(denominator != 0);
		normalize();
	}

	Rational& operator+=(const Rational& rhs) {
		return *this = *this + rhs;
	}

	Rational& operator-=(const Rational& rhs) {
		return *this = *this - rhs;
	}

	Rational& operator*=(const Rational& rhs) {
		numerator *= rhs.numerator;
		denominator *= rhs.denominator;
		normalize();
		return *this;
	}

	Rational operator-() const {
		return Rational(-numerator, denominator);
	}

	Rational& operator/=(const Rational& rhs) {
		SPCPPL_ASSERT(rhs.numerator != 0);
		numerator *= rhs.denominator;
		denominator *= rhs.numerator;
		normalize();
		return *this;
	}

	bool operator==(const Rational& rhs) const {
		return numerator == rhs.numerator && denominator == rhs.denominator;
	}

	const T& getNumerator() const {
		return numerator;
	}

	const T& getDenominator() const {
		return denominator;
	}

private:
	void normalize() {
		T g = gcd(numerator, denominator);
		numerator /= g;
		denominator /= g;

		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
	}

	T numerator, denominator;

	template <typename U>
	friend Rational<U> operator+(const Rational<U>& lhs, const Rational<U>& rhs);
};


template <typename T>
Rational<T> operator+(const Rational<T>& lhs, const Rational<T>& rhs) {
	T g = gcd(lhs.denominator, rhs.denominator);
	return Rational<T>(
			lhs.numerator * (rhs.denominator / g) + rhs.numerator * (lhs.denominator / g),
			lhs.denominator / g * rhs.denominator
	);
}

template <typename T>
Rational<T> operator-(const Rational<T>& lhs, const Rational<T>& rhs) {
	return lhs + (-rhs);
}

template <typename T>
Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs) {
	Rational<T> copy = lhs;
	return copy *= rhs;
}

template <typename T>
Rational<T> operator/(const Rational<T>& lhs, const Rational<T>& rhs) {
	Rational<T> copy = lhs;
	return copy /= rhs;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Rational<T>& rational) {
	return stream << rational.getNumerator() << '/' << rational.getDenominator();
}

template <typename T>
struct IdentityHelper<Rational<T>> {
	static Rational<T> identity() {
		return Rational<T>(1);
	}
};

template <typename T>
bool operator==(const Rational<T>& lhs, const Rational<T>& rhs) {
	return lhs.getNumerator() * rhs.getDenominator() == lhs.getDenominator() * rhs.getNumerator();
}

template <typename T>
bool operator!=(const Rational<T>& lhs, const Rational<T>& rhs) {
	return !(lhs == rhs);
}

template <typename T>
bool operator<(const Rational<T>& lhs, const Rational<T>& rhs) {
	return lhs.getNumerator() * rhs.getDenominator() < lhs.getDenominator() * rhs.getNumerator();
}

template <typename T>
bool operator>(const Rational<T>& lhs, const Rational<T>& rhs) {
	return rhs < lhs;
}

template <typename T>
bool operator<=(const Rational<T>& lhs, const Rational<T>& rhs) {
	return !(lhs > rhs);
}

template <typename T>
bool operator>=(const Rational<T>& lhs, const Rational<T>& rhs) {
	return !(lhs < rhs);
}


//#define PROBLEM "problem_name.h"
//#include PROBLEM
//#include <message.h>
//#include <spcppl/dgcj.h>

using namespace std;

class TaskD {
public:
	void solve(std::istream& in, std::ostream& out) {
		int k, pa, pb;
		in >> k >> pa >> pb;
		using Z = ZnConst<1000000007>;
		//using Z = Rational<int>;

		auto ZZ = [](int x) -> Z {
			return Z::rawValueOf(x);
		};

		Z probB = ZZ(pb) / ZZ(pb + pa);
		Z probA = ZZ(pa) / ZZ(pb + pa);

		auto dp = make_vector<Z>(k + 1, k + 1, Z());

		for (int c: inclusiveRange(1, k)) {
			for (int haveA: inclusiveDownrange(k, c)) {
				dp[c][haveA] = ZZ(1) / probB - ZZ(1) + ZZ(haveA);
			}
			for (int haveA: inclusiveDownrange(c - 1, 1)) {
				dp[c][haveA] = probA * dp[c][haveA + 1] + probB * (ZZ(haveA) + dp[c - haveA][haveA]);
			}
			dp[c][0] = dp[c][1];
		}

		out << dp[k][0];
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskD solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}