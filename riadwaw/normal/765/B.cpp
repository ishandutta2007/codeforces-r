/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>

using namespace std;

class TaskB {
public:
	void solve(std::istream& in, std::ostream& out) {
		char mx = 'a' - 1;
		string s;
		in >> s;
		for (char c: s) {
			if (c == mx + 1) {
				++mx;
			} else if (c > mx) {
				out << "NO\n";
				return;
			}
		}
		out << "YES\n";
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}