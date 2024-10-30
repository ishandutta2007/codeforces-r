/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <bits/stdc++.h>


template <typename T>
T gcd(T a, T b) {
	while (b) {
		T tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

using namespace std;

class TaskA {
public:
	void solve(std::istream& in, std::ostream& out) {
		int a, b, n;
		in >> a >> b >> n;
		while(true) {
			if(n == 0) {
				out << 1;
				break;
			}
			n -= gcd(a, n);
			if(n == 0) {
				out << 0;
				break;
			}
			n -= gcd(b, n);
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskA solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(0);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}