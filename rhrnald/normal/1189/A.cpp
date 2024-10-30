#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 1000001;
int n,m;
string s;
int main(void){
	scanf("%d", &n);
	cin >> s;
	int a=0, b=0;
	for(int i=0; i<n; i++) {
		if(s[i]=='0') a++;
		else b++;
	}
	if(a!=b) {
		printf("1\n");
		cout << s;
		return 0;
	}
	printf("2\n");
	cout << s.substr(0,1) << ' ' << s.substr(1);
}