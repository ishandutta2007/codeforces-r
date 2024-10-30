#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
int t, n;
vector<int> g[N];
pair<int,int> ask(vector<int> v) {
	printf("? %d ", v.size());
	for (auto x: v) printf("%d ", x);
	printf("\n");
	fflush(stdout);
	int x, d; scanf("%d%d", &x, &d);
	return make_pair(x, d);
}
 
int dep[N], par[N], vis[N];
vector<int> vd[N];
void dfs(int u, int p) {
	dep[u] = dep[p] + 1; par[u] = p;
	vd[dep[u]].push_back(u);
	for (auto v: g[u]) {
		if (v == p) continue;
		dfs(v, u);
		dep[v] = dep[u] + 1;
	}
}
void tag(int u) {
	while (u) {
		vis[u] = 1; u = par[u];
	}
}
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			g[i].clear(); vd[i].clear(); vis[i] = 0;
		}
		for (int i = 1; i < n; i ++) {
			int u, v; 
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
 
		vector<int> vec;
		for (int i = 1; i <= n; i ++) vec.push_back(i);
		pair<int,int> P = ask(vec);
		int root = P.first;
		dfs(root, 0);
 		// printf("$ %d %d\n", P.first, P.second);
		int lef = 1 + P.second / 2, rig = min(P.second + 2, *max_element(dep + 1, dep + 1 + n) + 1), u = 0, v = 0;
		while (rig - lef > 1) {
			// printf("A: lef = %d, rig = %d\n", lef, rig);
			int mid = (lef + rig) >> 1;
			// printf("mid = %d\n", mid);
			pair<int,int> tmp = ask(vd[mid]);
			// printf("mid = %d\n", mid);
			// printf("ok\n");
			if (tmp.second == P.second) {
				lef = mid, u = tmp.first; 
			} else {
				rig = mid;
			}
			// printf(" u = %d\n", u);
			// printf("ok\n");
			// printf("B: lef = %d, rig = %d\n", lef, rig);
		}
 		if (u == 0) {
 			u = ask(vd[lef]).first;

 		}
 		// printf("u = %d\n", u);

		int sum = P.second + 2;

		int d = sum - dep[u];
		if (d == 1) v = root;
		else {
			tag(u);
			vector<int> nv;
			for (auto x: vd[d]) if (vis[x] == 0) nv.push_back(x);
			pair<int, int> tmp = ask(nv);
			v = tmp.first;
		}
		printf("! %d %d\n", u, v);
		fflush(stdout);
		char str[10]; scanf("%s", str);
		if (str[0] == 'I') assert(0);
	}
}