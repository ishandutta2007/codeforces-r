/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>





#include <type_traits>

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


using namespace std;

class TaskC {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		using R = Rational<int64_t>;
		R mn{};
		R mx{1000000};

		int x1, x2, y1, y2;

		in >> x1 >> y1 >> x2 >> y2;

		for (int i: range(n)) {
			int x, y, vx, vy;
			in >> x >> y >> vx >> vy;

			auto go = [&](int z, int vz, int z1, int z2) {
				if (vz == 0) {
					if (z <= z1 || z >= z2) {
						mx = -1;
					}
					return;
				}
				if (vz < 0) {
					swap(z1, z2);
				}

				R cur(z1 - z, vz);

				mn = max(mn, cur);

				R cur2(z2 - z, vz);

				mx = min(mx, cur2);

			};

			go(x, vx, x1, x2);
			go(y, vy, y1, y2);
		}

		//cerr << "---" << endl;
		//cerr << mn << ' ' << mx << endl;

		if (mn >= mx) {
			out << -1;
		} else {
			out << mn.getNumerator() / 1.0 / mn.getDenominator();
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskC solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}