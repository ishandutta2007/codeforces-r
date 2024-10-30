/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>

using namespace std;

class TaskC {
public:
	void solve(std::istream& in, std::ostream& out) {
		int x2, x3;
		in >> x2 >> x3;
		int l = 0, r = 6000000;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (m / 2 >= x2 && m / 3 >= x3 && (m / 2 + m / 3 - m / 6) >= x2 + x3) {
				r = m;
			} else {
				l = m;
			}
		}
		out << r << endl;
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