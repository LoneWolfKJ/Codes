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
    int t; cin >> t; while(t--){
        int n,r;
        cin >> n >> r;
        int a[n];
        map<int,int> hits;
        for(int i=0;i<n;i++){
            cin>>a[i];
            cout << a[i];
            int ciel = ceil(((double)(a[i]))/r);
            hits[ciel]++;
            cout << ciel << "\n";
        }
        sort(a,a+n);
        vector<int> v;
        map<int,int> m;
        for(int i=n-1;i>=0;i--){
            if(m[a[i]]==0){
            v.pb(a[i]);
            }
            m[a[i]]++;
        }
        int ind[100005];
        int hit=0;
        int killed=0;
        for(int i=0;i<v.size();i++){
            ind[v[i]]= -1*r;
            killed+=m[v[i]];
            //cout << killed << "killed 1 ";
            hit++;
            killed+=hits[hit];
            //cout << killed << " killed 2 "; 
            if(killed>=n)
                break;
        }
        cout << hit << "\n";

    }
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start); 
    cout << "Time Elapsed : " << duration.count() << " ";
    #endif
 
}