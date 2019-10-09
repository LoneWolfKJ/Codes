    #include<bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp> 
    #include <ext/pb_ds/tree_policy.hpp> 
    using namespace std;
    using namespace std::chrono; 
    using namespace __gnu_pbds; 
      
    #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
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
     
    map<ll,ll> m;
    ll pull(ll x){
        m[x]=0;
        if(m[x-1]==1){
            m[x-1]=0;
        }
        else{
            m[x-1]=1;
        }
        return m[x-1];
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
            m.clear();
            ll h,n;
            cin >> h >> n;
            ll a[n];
            for(int i=0;i<n;i++){
                cin >> a[i];
                //cout << a[i] << " ";
                m[a[i]]=1;
            }
            //cout << "\n";
            ll me=h;
            ll crystals=0;
            int ini=1;
            int flag=0;
            while(me>0 && ini<(n)){
                //cout << me << "me starting \n";
                ll temp = pull(me);
                if(temp==1){
                    me--;
                    while(a[ini]>=me && ini<(n-1)){
                        ini++;
                    }
                    //cout << ini << " ini\n";
                    me = min(me,a[ini]+1);
                    //cout << me << "me\n";
                }
                if(me<=0){
                    break;
                }
                //cout << temp << " temp\n";
                if(temp==0){
                    
                    me-=2;
                    if(me<=0){
                        break;
                    }
                    if(m[me]!=1){
                        crystals++;
                        m[me]=1;
                    }
                    //while(a[ini]>=me && ini<(n-1)){
                       // ini++;
                    //}
                    //cout << crystals << " " << me << " me \n";
                }
                if(ini ==(n-1) && flag==0){
                    flag=1;
                }
                else{
                    if(ini == (n-1) && flag==1){
                        break;

                    }
                }
                
            }
            //cout << ini << "ini\n";
            //cout << " answer \n";
            cout << crystals << "\n";
        }
        
        #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<milliseconds>(stop - start); 
        cout << "Time Elapsed : " << duration.count() << " ";
        #endif
     
    }