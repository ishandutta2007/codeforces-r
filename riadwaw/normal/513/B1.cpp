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

class TaskB2 {
public:
	void solve(std::istream& in, std::ostream& out) {
		long long n, m;
		in >> n >> m;
		vector<int> res(n);
		int mn = 0;
		int mx = n - 1;
		for(int i = 0; i < n - 1; ++i) {
			long long r = 1LL << (n - i - 2);
			//out << r << ' ' << m << endl;
			if(r >= m) {
				res[mn++] = i + 1;
			}
			else {
				res[mx--] = i + 1;
				m -= r;
			}
		}
		res[mn] = n;
		for(int i = 0; i < n; ++i) {
			out << res[i] << ' ';
		}
	}
};


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << std::fixed;
	std::cout.precision(20);
	TaskB2 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}