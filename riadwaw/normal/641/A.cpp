/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class TaskA {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		string s;
		in >> s;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			in >> v[i];
		}
		set<int> used;
		int pos = 0;
		while (true) {
			int mult = 1;
			if (s[pos] == '<') {
				mult = -1;
			}
			pos += mult * v[pos];
			if (pos < 0 || pos >= n) {
				out << "FINITE\n";
				return;
			} else {
				if(used.count(pos)) {
					out << "INFINITE\n";
					return;
				} else {
					used.insert(pos);
				}
			}
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