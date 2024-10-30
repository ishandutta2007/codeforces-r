#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
void msort(int l,int r,int* a){
	int b[10000];
	if (r-l==1){
		return;
	}
	int mid = (l+r)/2;
	msort(l, mid, a);
	msort(mid, r, a);
	int p1,p2;
	p1 = l;
	p2 = mid;
	for (int i=l; i<r; i++){
		if (p2>=r || (a[p1]<a[p2] and p1<mid)){
			b[i] = a[p1];
			p1++;
		}
		else{
			b[i] = a[p2];
			p2++;
		}
	}
	for (int i=l; i<r; i++){
		a[i]=b[i];
	}
}
struct node{
	int val;
	node* p;
};

struct stack{
	node* top=NULL;
	int s=0;
	int topp(){
		if (s>0)
		return top->val;
		else
		return NULL;
	}
	void push(int x){
		node* a=new node;
		a->val=x;
		a->p=top;
		top=a;
		s++;
	}
	void pop(){
		if (s>1){
			top=top->p;
		}
		else{
			top=NULL;
		}
		s--;
	}
};
bool in(int* a, int x, int n){
	for (int i=0; i<n; i++){
		if (a[i] == x){
			return 1;
		}
	}
	return 0;
}
int main(){
	int t;
	cin>>t;
	for (int i=0; i<t; i++){
		long long int n,a,b;
		cin>>n>>a>>b;
		int k=int('a'),c=0;
		for (int j=0; j<b; j++){
			cout<<char(int('a')+j);
		}
		n-=b;
		while(n>0){
			for (int j=0; j<b; j++){
				cout<<char(int('a')+j);
				n--;
				if (n==0){
					break;
				}
			}
		}
		cout<<endl;
	}
}