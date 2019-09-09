#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define mp make_pair
#define pb push_back

ll power(ll a, ll n) {
	ll p = 1;
	while (n > 0) {
		if(n%2) {
			p = p * a;
		} n >>= 1; a *= a;
	} 
	return p;
}
ll power(ll a, ll n, ll mod) {
	ll p = 1;
	while (n > 0) {
		if(n%2) {
			p = p * a; p %= mod;
		} n >>= 1;
	       	a *= a; a %= mod;
	} 
	return p % mod;
}

int rand(int a, int b) {
	return a + rand() % (b-a + 1);
}

int main(int argc, char* argv[]){
	srand(atoi(argv[1]));
	int n = rand(1,100);
	int q = rand(1,100);
	cout << n << " " << q << "\n";
	for(int i=0;i<n;i++){
		int x;
		x=rand(1,1000000000);
		cout << x << " ";
	}
	cout << "\n";
	for(int i=0;i<(n-1);i++){
		int k,j;
		k=rand(1, n);
		j=rand(1, n);
		cout << k << " " << j << "\n";
	}
	for(int i=0;i<q;i++){
		int k1,k2,k3;
		k1=rand(1,n);
		k2=rand(1,100000);
		k3=rand(1,1000000000);
		if(k2%2){
			cout << "2 " << k1 <<"\n";
		}
		else{
			cout << "1 " << k1 << " " << k3 << "\n";
		}
	}
	puts("");
	return 0;
}

