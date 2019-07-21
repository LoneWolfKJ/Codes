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

int main() 
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll a[n];
		ll sum =0;
		for(int i=0;i<n;i++){
			cin >> a[i];
			sum += a[i];
		}
		long double mean1 = (long double)sum/n;
		long double mean2;
		int flag=0;
		//cout << mean1 << "mean1 \n";
		int coin_number;
		for(int i=0;i<n;i++){
       			mean2 = ((long double)((sum-a[i])))/(n-1);
			//cout << mean2 << " mean2with " << i << "\n";
			if(mean2==mean1){
				flag=1;
				coin_number = i+1;
				break;
			}
                }
		if(flag){
			cout << coin_number << "\n";
		}
		else{
			cout << "Impossible\n";
		}

	}
	return 0;
}

