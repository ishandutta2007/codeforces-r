#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 100007

int n ;

int a[ MAXN ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int lst = a[ 1 ] ;
	int i ;
	int cur = 1 ;
	int mx = 0 ;
	for ( i = 2 ; i <= n ; i ++ ) {
		if ( a[ i ] >= lst ) { cur ++ ; }
		else {
			if ( mx < cur ) { mx = cur ; }
			cur = 1 ; 
		}
		lst = a[ i ] ; 
	}
	if ( mx < cur ) { mx = cur ; }
	printf ( "%d\n" , mx ) ;
}