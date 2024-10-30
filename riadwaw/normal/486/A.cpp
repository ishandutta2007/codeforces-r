/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Z {
public:
	void solve(std::istream& in, std::ostream& out) {
		long long n;
		in >> n;
		if(n % 2 == 0) {
			out << n / 2;
		}
		else {
			out << n / 2 - n;
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	Z solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(0);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}