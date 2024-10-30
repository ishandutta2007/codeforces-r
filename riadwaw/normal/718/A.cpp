/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>

using namespace std;

class TaskA {
public:
	void solve(std::istream& in, std::ostream& out) {
		string s;
		int t;

		in >> t >> t >> s;

		int point = (int) s.find('.');
		int leftMost = -1;
		for (int i = point + 1; i < s.size(); ++i) {
			if (s[i] >= '5') {
				leftMost = i;
				break;
			}
		}

		while (leftMost != -1 && t) {
			--t;
			if (leftMost - 1 == point) {
				s = s.substr(0, point);
				int p = (int)s.size() - 1;
				while (true) {
					if (p == -1) {
						s = '1' + s;
						break;
					}
					if (s[p] == '9') {
						s[p] = '0';
						--p;
					} else {
						++s[p];
						break;
					}
				}
				out << s;
				return;
			}
			++s[leftMost - 1];
			s.erase(s.begin() + leftMost, s.end());
			if (s[leftMost - 1] == '5') {
				--leftMost;
			} else {
				leftMost = -1;
			}
		}

		out << s;

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