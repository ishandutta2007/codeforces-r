#include <bits/stdc++.h>
#include <algorithm>

#define ll long long int
using namespace std;

const int N=15000;
ll a[N],Le[N],Ri[N],b[N];

void msort(int l, int r){
	int m=(l+r)/2;
	if (l == r-1){
		return;
	}
	msort(l,m);
	msort(m,r);
	int p1 = l;
	int p2 = m;
	int k = l; 
	while (k < r){
		if (p2 >= r || (p1 < m && a[p1] > a[p2] )){
			b[k] = a[p1];
			p1++;
		}
		else{
			b[k] = a[p2];
			p2++;
		}
		k++;
	}
	for (int i=l; i<r; i++){
		a[i] = b[i];
	}
}
void merge(ll arr[], ll l, long long int m, long long int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 	
        	Le[j] += i;
            arr[k] = L[i]; 
            
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(long long int arr[], long long int l,long long  int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r);   
        merge(arr, l, m, r); 
    } 
}

int main(){
	ll t;
	cin >>t;
	for (ll i=0; i<t; i++){
		ll n,to=0,te=0,td=0;
		cin >>n;
		stack <ll> st;
		for (ll j=0; j<n; j++){
			cin >> a[j];
			if (a[j]%2){
				to++;
			}
			else{
				te++;
			}
		}
		mergeSort(a,0,n-1);
		for (ll j=1; j<n; j++){
			if (abs(a[j]-a[j-1]) == 1){
				td++;
			}
		}
		if ((te%2 == to%2 && te%2 == 0) || (te%2==to%2 && td)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}