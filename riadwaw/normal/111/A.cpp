#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <math.h>
#include <sstream>
#include <complex>
#include <string.h>
#include <algorithm>
using namespace std;

void solve();
#define mp make_pair
#define pb push_back
typedef int fknmain;
typedef long long int li;
/**
 CAUTION Is int really int?
 * 
 Real solution after main function
 */
//#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;

fknmain main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
#define LL "%lld"
#else
#define LL "%I64d"
#endif
#ifndef int
#define INT "%d"
#else
#define INT LL
#endif
    solve();
    return 0;
}

void solve(){
    li n,x,y;
    cin>>n>>x>>y;
    if(n>y){
        cout<<-1;
        return;
    }
    if((y-n+1)*(y-n+1)+n-1>=x){
        for(int i=1;i<n;++i){
            cout<<1<< ' ';
        }
        cout<<y-n+1;
    }
    else
        cout<<-1;
}