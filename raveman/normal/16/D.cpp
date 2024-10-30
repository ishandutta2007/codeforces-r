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

int getM(int h,int m,char c){
	if(c=='a'){
		return 60*(h%12)+m;
	}
	return 12*60+(60*(h%12)+m);
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	int n;
	cin>>n;
	int days = 0;
	int prev = 43214781;
	int num = 0;
	REP(i,n){
		char tmp[111];
		int h,m;
		char q;
		scanf(" [%d:%d %c",&h,&m,&q);
		gets(tmp);
		int M = getM(h,m,q);
		if(M>prev) prev = M, num = 1;
		else if(M==prev && num<10) num++;
		else if(M==prev) days++,num=1;
		else days++,prev=M,num=1;

	}
	cout<<days<<endl;
	return 0;
}