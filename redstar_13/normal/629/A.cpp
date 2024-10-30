#include <bits/stdc++.h>



#define inf 0x3f3f3f3f

#define MOD 1000000007

#define pb push_back

#define sq(x) ((x)*(x))

#define x first

#define y second

#define eps 1e-8

#define bpt(x) (__builtin_popcount(x))

#define bptl(x) (__builtin_popcountll(x))

#define bit(x, y) (((x)>>(y))&1)

#define bclz(x) (__builtin_clz(x))

#define bclzl(x) (__builtin_clzll(x))

#define bctz(x) (__builtin_ctz(x))

#define bctzl(x) (__builtin_ctzll(x))



using namespace std;

typedef long long INT;

typedef vector<int> VI;

typedef pair<int, int> pii;

typedef pair<pii, int> pi3;

typedef double DO;



template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}

char s[111][111];

int row[111], col[111];



int main() {

	int n,i,j;

	cin>>n;

	for(i=0; i<n; i++){

		scanf("%s", s[i]);

	}

	

	for(i=0; i<n; i++){

		for(j=0; j<n; j++){

			if(s[i][j]=='C') row[i]++, col[j]++;

		}

	}

	int ans=0;

	for(i=0; i<n; i++){

		ans+=row[i]*(row[i]-1)/2+col[i]*(col[i]-1)/2;

	}

	cout<<ans<<endl;



	return 0;

}