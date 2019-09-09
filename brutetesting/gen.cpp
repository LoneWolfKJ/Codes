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
	//srand(atoi(argv[1]));
	int n = rand(1,1000);
	cout << n << "\n";
	for(int i=0;i<n;i++){
		int x;
		x=rand(1,1000000000);
		cout << x << " ";
	}
	puts("");
	return 0;
}

