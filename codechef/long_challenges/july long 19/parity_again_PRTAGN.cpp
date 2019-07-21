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
		int q;
		cin >> q;
		int q1=q;
		int a[q];
		int orvalue=0,i=0;
		ll even=0,odd=0;
		while(q1--){
			cin >> a[i];
			int setbits = __builtin_popcount (a[i]);
                        if(setbits%2){
				int temp=even;
				even+=odd;
				odd+= temp+1;
			}
			else{
				int temp=odd;
				//cout << even << " " << odd;
				odd+=odd;
				even+=even+1;
			}
			i++;
                        cout << even << " " << odd << "\n";
		}
	}
	return 0;
}

