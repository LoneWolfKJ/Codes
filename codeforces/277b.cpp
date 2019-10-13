#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono; 
 
typedef long long int ll;
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

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
    //int t; cin >> t; while(t--){}
    ll n,m;
    cin >> n >> m;
    int a[n][m];
    int b[n][m];
    vector<int> r,c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> b[i][j];
            a[i][j]=1;
            if(b[i][j]==0){
                r.pb(i);
                c.pb(j);
            }
        }
    }
    //cout << r << c;
    for(int i=0;i<r.size();i++){
        for(int j=0;j<m;j++){
            a[r[i]][j]=0;
        }
    }
    for(int i=0;i<c.size();i++){
        for(int j=0;j<n;j++){
            a[j][c[i]]=0;
        }
    }
    vector<int> rows,cols;
    for(int i=0;i<n;i++){
        int t=0;
        for(int j=0;j<m;j++){
            t|=a[i][j];
        }
        rows.pb(t);
    }
    for(int i=0;i<m;i++){
        int t=0;
        for(int j=0;j<n;j++){
            t|= a[j][i];
        }
        cols.pb(t);
    }
    //cout << "\nrows cols \n";
    //cout<<rows << cols;
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j] != (rows[i]|cols[j])){
                flag=1;
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    if(flag==1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start); 
    cout << "Time Elapsed : " << duration.count() << " ";
    #endif
 
}