/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>
#include <assert.h>
#include <memory.h>

using namespace std;
class B {
	int n;
public:
	int sum (int r)
	{
		int result = 0;
		for (; r >= 0; r = (r & (r+1)) - 1)
			result += t[r];
		return result;
	}

	void inc (int i, int delta)
	{
		for (; i < n; i = (i | (i+1)))
			t[i] += delta;
	}
	vector<int> t;

	void solve(std::istream& in, std::ostream& out) {

		in >> n;
		vector<int> a(n), b(n);

		t.assign(n, 0);
		for(int i = 0; i < n; ++i) {
			int x;
			in >> x;
			a[i] = x - sum(x);
			inc(x, 1);
		}



		t.assign(n, 0);
		for(int i = 0; i < n; ++i) {
			int x;
			in >> x;
			b[i] = x - sum(x);
			inc(x, 1);
		}

		vector<int> c(n);

		int carry = 0;
		for(int i = n - 1, j = 1; i >= 0; --i) {
			int val = a[i] + b[i] + carry;
			carry = val / j;
			c[i] = val % j;
			++j;
		}


		const int shift = 1 << 18;
		vector<int> tree(2 * shift);

		for(int i = 0; i < n; ++i) {
			tree[shift + i] = 1;
		}

		for(int i = shift - 1; i >=0; --i) {
			tree[i] = tree[2 * i] + tree[2 * i + 1];
		}

		for(int i = 0; i < n; ++i) {
			int v = 1;
			int need = c[i] + 1;
			while(v < shift) {
				--tree[v];
				if(tree[2 * v] >= need) {
					v *= 2;
				}
				else {
					need -= tree[2 * v];
					v = 2 * v + 1;
				}
			}
			out << v - shift << ' ';
			--tree[v];

		}


	}
};


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << std::fixed;
	std::cout.precision(20);
	B solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}