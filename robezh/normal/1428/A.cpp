#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    int a, b, c, d;
    cin >> T;
    while(T--) {
        cin >> a >> b >> c >> d;
        if(a != c && b != d) {
            cout << abs(a - c) + abs(b - d) + 2 << '\n';
        } else {
            cout << abs(a - c) + abs(b - d) << '\n';
        }
    }

}