/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <cmath>

using namespace std;

class TaskB {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, r, v;
		in >> n >> r >> v;
		for (int i = 0; i < n; ++i) {
			int s, f;
			in >> s >> f;
			double L = 0, R = 1e9;
			for (int it = 0; it < 100; ++it) {
				double m = (L + R) / 2;
				double d = abs(2 * sin(m / 2)) * r + m * r;
				if (d >= f - s) {
					R = m;
				}
				else
					L = m;
			}
			out << L * r / v << "\n";
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(0);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}