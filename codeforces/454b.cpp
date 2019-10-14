#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define mp make_pair
#define pb push_back
 
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
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    #endif
    //int t; cin >> t; while(t--){}
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int flag=-1;
    int issorted=1;
    for(int i=0;i<v.size()-1;i++){
        if(v[i+1] < v[i]){
            issorted=0;
            flag=i+1;
        }
    }
    if(issorted==1){
        cout << "0";
    }
    else{
        vector<int> v2;
        for(int i=flag;i<v.size();i++){
            v2.pb(v[i]);
        }
        for(int i=0;i<flag;i++){
            v2.pb(v[i]);
        }
        //cout << v2;
        //cout << is_sorted(v2.begin(),v2.end());
        //cout << n-flag;
        if(is_sorted(v2.begin(),v2.end())){
            cout << n-flag;
        }
        else{
            cout << "-1";
        }
    }
    #ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}