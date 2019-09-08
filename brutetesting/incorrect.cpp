#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    int n;
    cin >> n;
    ll a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    ll ans = 0;
    vector<ll>v(1000005, 0);
    for(int i=0; i<n; i++)
        v[a[i]]++;
    stack<pair<ll, ll> >st;
    for(ll i = 1; i<=1000005; i++){
        if(v[i] != 0){
        if(!st.empty()){
            auto it = st.top();
            if(it.second > v[i]){
                st.pop();
                st.push({it.first, it.second-v[i]});
                st.push({i, v[i]});
            }
            else if(it.second == v[i]){
                st.pop();
                st.push({i, v[i]});
            }
            else{
                st.pop();
                ll temp = v[i] - it.second;
                while(true){
                    if(temp == 0)
                        break;
                    if(!st.empty()){
                        auto it1 = st.top();
                        st.pop();
                        if(temp > it1.second)
                            temp-=it1.second;
                        else if(temp == it1.second)
                            temp = 0;
                        else{
                            st.push({it1.first, it1.second - temp});
                            temp = 0;
                        }
                    }
                    else
                        break;
                }
                st.push({i, v[i]});
            }
        }
        else{
            st.push({i, v[i]});
        }   
        }
    }
    while(!st.empty()){
        auto it = st.top();
        ans+=it.first*it.second;
        st.pop();
    }
    
    cout << ans;
    return 0;
}
