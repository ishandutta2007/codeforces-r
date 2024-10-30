/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>

using namespace std;

class TaskA {
public:
	void solve(std::istream& in, std::ostream& out) {
		vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
		int cnt = 0;
		vector<int> al;
		for (int y: primes) {
			out << y << endl;
			string s;
			in >> s;
			if (s == "yes") {
				++cnt;
				al.push_back(y);
			}
		}

		if (al.size() == 1) {
			int y = al[0] * al[0];
			if (y <= 100) {
				out << y << endl;
				string s;
				in >> s;
				if (s == "yes") {
					++cnt;
					al.push_back(y);
				}
			}
		}

		if (cnt >= 2) {
			out << "composite";
		} else {
			out << "prime";
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