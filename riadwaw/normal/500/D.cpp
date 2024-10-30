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

class D {
	std::vector<std::vector<std::pair<int, int>>> g;
	std::vector<int> len;
	std::vector<long long> count;
	int dfs(int v, int p) {
		int sum = 1;
		for(pair<int, int> to: g[v]) {
			if(to.first == p) {
				continue;
			}
			int childSize =  dfs(to.first, v);
			sum += childSize;
			count[to.second] += 1LL * childSize * (n - childSize) * (n - childSize - 1) +
								1LL * childSize * (childSize - 1) * (n - childSize);
		}
		return sum;
	}
	int n;
public:
	void solve(std::istream& in, std::ostream& out) {
		in >> n;

		g.assign(n, std::vector<std::pair<int, int>>());
		len.assign(n, 0);
		count.assign(n, 0);
		for (int i = 0; i < n - 1; ++i) {
			int a, b, l;
			in >> a >> b >> l;
			--a, --b;
			len[i] = l;
			g[a].push_back(make_pair(b, i));
			g[b].push_back(make_pair(a, i));
		}
		dfs(0, -1);
		long long cnt = 1LL * n * (n - 1) * (n - 2);
		double res = 0;
		for(int i = 0; i < n; ++i) {
			res += count[i] * len[i];
		}
		int q;
		in >> q;
		for (int i = 0; i < q; ++i) {
			int r, w;
			in >> r >> w;
			--r;
			res -= count[r] * len[r];
			len[r] = w;
			res += count[r] * len[r];
			out << res / cnt * 6 << "\n";
		}
	}
};


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << std::fixed;
	std::cout.precision(20);
	D solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}