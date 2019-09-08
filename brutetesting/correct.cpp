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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n;
    cin >> n;
    long long int a[1000001]={0};
    long long int x;
    for(long long int i=0;i<n;i++){
        cin >> x;
        a[x]++;
        //cout << a[x];
    }
    long long int minsum=0;
    long long int shooter,shooted;
    long long int currmax=-1;
    long long int power=0,shootedpower=0;
    for(long long int i=1000000;i>=0;i--){
        if(a[i]!=0){
           //cout << i << " \n";
                if(currmax <i){
                    currmax=i;
                    minsum+=(i*a[i]);
                    power+= a[i];
                }
                else{
                    //cout << a[i];
                    //cout << power << " p\n";
                    long long int temp=power;
                    power= max((long long int)0,(power-a[i]));
                    if(power==0){
                        minsum += ((a[i]-temp)*i);
                        currmax= i;
                    }
                    power += a[i];
                 }
            //cout << minsum << " m\n";
            }
    }
        //cout <<  " \n#"<<power << " " << minsum<< " "<< currmax << " \n";
    cout << minsum;
    return 0;
}
