#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono; 
 
typedef long long int ll;
#define mp make_pair
#define pb push_back
 
vector<int> sieve(ll n){
   vector<int> prime(n+1,0);
   vector<int> primes(n+1,0);
   int index=0;
   for(int i=2;i<=n;i++){
       if(prime[i]==0){
           prime[i]=i;
           primes[index]=i;
           index++;
       }
       for(int j=0;j<index && primes[j]<=prime[i] && i*primes[j]<=n; j++){
           prime[primes[j]*i] = primes[j];
           if (i % primes[j] == 0) break;
       }
   }
   return prime;
}
 
template <typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
   if ( !v.empty() ) {
       copy (v.begin(), v.end(), ostream_iterator<T>(out, " "));
       out << "\n";
   }
   return out;
}
 
ll power(ll a, ll n) {
    ll p = 1;
    while (n > 0) {
       if(n%2) {
          p = p * a;
       } n >>= 1; a *= a;
    }
    return p;
}
 
ll powermodulo(ll a, ll n, ll mod) {
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
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now(); 
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    #endif
    int n; cin >> n; while(n--){
        //cout << t << "t\n";
        int t;
        cin >> t;
        ll a[t];
        ll sum=0;
        for(int i=0;i<t;i++){
            cin >> a[i];
            sum+= (a[i] %t);
            sum=sum%t;
        }
        sum = ((sum==0)? 1 : -1);
        //cout << sum << " sum\n";
        if(sum==-1){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time Elapsed : " << duration.count() << " ";
    #endif
 
}