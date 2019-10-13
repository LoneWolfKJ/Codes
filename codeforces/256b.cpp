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
    //int t; cin >> t; while(t--){}
    string a,b;
    cin >> a >> b;
    int n1=a.length();
    int n2=b.length();
    int flag=0;
    for(int i=0,j=0;i<n1;i++){
        if(j<n2){
            if(b[j]==a[i]){
                j++;
            }
        }
        if(j==n2){
            flag=1;
            break;
        }
    }
    if(flag==1){
        cout << "automaton\n";
    }
    else{
        int hm[35]={0};
        for(int i=0;i<n1;i++){
            hm[a[i]-'a']++;
        }
        for(int i=0;i<n2;i++){
            hm[b[i]-'a']--;
        }
        int neg=0;
        for(int i=0;i<26;i++){
            if(hm[i]<0){
                neg=1;
            }
            if(hm[i]!=0){
                flag=1;
            }
        }
        if(flag==0){
            cout << "array\n";
        }
        else{
            if(neg==1){
                cout << "need tree\n";
            }
            else{
                cout << "both\n";
            }
        }
        
    }

    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start); 
    cout << "Time Elapsed : " << duration.count() << " ";
    #endif
 
}