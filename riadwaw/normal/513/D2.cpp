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

const int shift = 1 << 20;
vector<int> tree;
class TaskD1 {

	vector<vector<pair<int, int>>> q;
	vector<int> res;





	int getMax(int l, int r) {
		if(l >= r)
			return 0;
		if(l % 2)
			return max(tree[l],getMax(l + 1, r));
		if(r % 2)
			return max(getMax(l, r - 1), tree[r - 1]);
		return getMax(l / 2, r / 2);
	}

	void setVal(int l, int v) {

		tree[l + shift] = max(tree[l + shift], v);
//cerr << l << ' ' << tree[l + shift] << endl;
		for(int i = (l + shift) / 2; i; i /= 2) {
			tree[i] = max(tree[2 * i], tree[2 * i + 1]);
		}
	}
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, c;
		in >> n >> c;
		q.resize(n);


		tree.assign(shift << 1, 0);


		for(int i = 0; i < n; ++i) {
			tree[i + shift] = i;

		}

		for(int i = shift - 1; i>=0; --i)
			tree[i] = max(tree[2 * i], tree[2 * i + 1]);



		for(int i = 0; i < c; ++i) {
			int a, b;
			string s;
			in >> a >> b >> s;
			if(a >= b) {
				cout << "IMPOSSIBLE\n";
				return;
			}
			--a, --b;

			q[a].push_back(make_pair(b, s[0] == 'R'));

			setVal(a, b);
		}



		for(int i = n - 1; i >= 0; --i) {

			setVal(i, getMax(i + shift, getMax(i + shift, i + shift + 1) + 1 + shift));

		}

		if(!solve(0, n)) {
			out << "IMPOSSIBLE\n";
			return;
		}

		for(int i = 0; i < n; ++i) {
			out << res[i] + 1 << ' ';
		}
		cerr << "test end" << endl;
	}

	bool solve(int v, int to, int lev = 0) {
		//cerr << v << ' ' << to << endl;
		if(v >= to)
			return true;
		int maxLeftQuery = v;


		//cerr << v << ' ' << q[v].size() << endl;

		for(pair<int, int> x: q[v]) {
			//cerr << x.first << ' ' << x.second << endl;
			if(!x.second) {
				maxLeftQuery = max(maxLeftQuery, x.first);
			}
		}

		//cerr << v << ' ' << to << maxLeftQuery << endl;

		int gm = getMax(v + 1 + shift, maxLeftQuery + 1 + shift);
		//cerr << "get" << gm << endl;

		int left = max(maxLeftQuery + 1, gm + 1);

		//cerr << left << endl;

		if(left > to)
			return false;

		for(pair<int, int> x: q[v]) {
			if(x.second) {
				if(x.first < left)
					return false;
			}
		}

		//cerr << "ok left" << left << endl;
		if(!solve(v + 1, left, lev + 1))
			return false;
	//	cerr << "pb" << v << endl;
		res.push_back(v);
		if(!solve(left, to, lev + 1))
			return false;
	//	cerr << "out" << v << ' ' << to << endl;
		return true;


	}
};


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << std::fixed;
	std::cout.precision(20);
	TaskD1 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}