#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif

	string s1,s2;
	cin>>s1>>s2;
	SORT(s1);
	REP(i,s1.size()) if(s1[i]!='0'){
		char c =s1[i];
		s1.erase(s1.begin()+i);
		s1=c+s1;
		break;
	}
	if(s1==s2) puts("OK");
	else puts("WRONG_ANSWER");


    return 0;
}