#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        int a;
        int x;
        bool sol = false;
        for(int i = 1; i <= n; i ++ ){
            cin >> a;
            x = sqrt(a);
            if(x * x != a) sol = true;
        }
        if(sol)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}