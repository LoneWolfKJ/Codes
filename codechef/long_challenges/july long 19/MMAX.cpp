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

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int remainder=0;
		string k;
		cin >> k;
		for(int i=0;i<k.length();i++){
			remainder = ((remainder*10)+(k[i]-'0'))%n;
		}
		int kj= n-remainder;
		if(kj==remainder){
		cout << (kj*2) -1 << "\n";
		}
		else{
		cout << min(kj,remainder) *2  << "\n";
		}
	}
	return 0;
}

