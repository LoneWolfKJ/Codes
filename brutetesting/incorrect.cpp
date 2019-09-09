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
 
vector<int> v[4*100001]; 
vector<int> s; 
int seg[5*100001] = { 0 }; 
int seg1[5*100001] = { 0 }; 
int ar[4*100001]; 
  
int vertices; 
int edges; 
  
int segment(int low, int high, int pos) 
{ 
    if (high == low) { 
        seg[pos] = ar[s[low]]%2 == 0 ? 1 : 0;
        seg1[pos] = ar[s[low]]%2 == 0 ? 0 : 1;
    } 
    else { 
        int mid = (low + high) / 2; 
        segment(low, mid, 2 * pos); 
        segment(mid + 1, high, 2 * pos + 1); 
        seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
        seg1[pos] = seg1[2 * pos] + seg1[2 * pos + 1]; 
    }
    
    return seg[pos];
} 
  
pair<int,int> query(int node, int start, 
          int end, int l, int r) 
{ 
    if (r < start || end < l) { 
        return make_pair(0,0); 
    } 
  
    if (l <= start && end <= r) { 
        return make_pair(seg[node],seg1[node]); 
    } 
  
    int mid = (start + end) / 2; 
    pair<int,int> p1 = query(2 * node, start, 
                   mid, l, r); 
    pair<int,int> p2 = query(2 * node + 1, mid + 1, 
                   end, l, r); 
  
    return make_pair(p1.first+p2.first, p1.second+p2.second); 
} 
  
int update(int pos, int low, int high, 
           int idx, int val) 
{ 
    if (low == high) { 
        seg[pos] = val%2 == 0 ? 1 : 0;
        seg1[pos] = val%2 == 0 ? 0 : 1;
    } 
    else { 
        int mid = (low + high) / 2; 
  
        if (low <= idx && idx <= mid) { 
            update(2 * pos, low, mid, 
                   idx, val); 
        } 
        else { 
            update(2 * pos + 1, mid + 1, 
                   high, idx, val); 
        } 
        seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
        seg1[pos] = seg1[2 * pos] + seg1[2 * pos + 1]; 
    }
    return seg[pos];
} 
  
int dfs(int root) 
{ 
    s.push_back(root); 
    if (v[root].size() == 0) 
        return root; 
  
    for (int i = 0; i < v[root].size(); i++) { 
        int temp = dfs(v[root][i]); 
        s.push_back(temp); 
    } 
    return root; 
} 

int main() 
{ 
    int q;
    cin >> vertices >> q;
    //cout << vertices << " ";
    edges = vertices - 1;
    //cout << edges << " ";
    ar[0]=0;
    for(int i=1;i<=vertices;i++){
        int x;
        cin >> x;
        ar[i]=x;
        //cout << i << " " << x << " " << ar[i] << "\n";
    }
    //cout << " array \n";
    //for(int i=0;i<=vertices;i++){
    //    cout << ar[i] << " ";
    //}
    //cout << "\n";
    // Edges between the nodes
    for(int i=0;i<edges;i++){
        int u1,v1;
        cin >> u1 >> v1;
        v[u1].push_back(v1);
        //cout << u1 << " " << v1 << "\n";
    }
    
    int temp = dfs(1); 
    s.push_back(temp); 
  
    vector<pair<int, int> > p; 
  
    for (int i = 0; i <= vertices; i++) 
        p.push_back(make_pair(0, 0)); 
  
    for (int i = 0; i < s.size(); i++) { 
        if (p[s[i]].first == 0) 
            p[s[i]].first = i + 1; 
        else
            p[s[i]].second = i + 1; 
    } 
  
    segment(0, s.size() - 1, 1); 
    int e,f;
    int qtype,node;
    int val;
    for(int i=0;i<q;i++){
        cin >> qtype >> node;
        if(qtype == 1){
            cin >> val;
            e= p[node].first;
            f = p[node].second;
            
            update(1, 1, s.size(), e, val); 
            update(1, 1, s.size(), f, val); 
        }
        else{
            e = p[node].first; 
            f = p[node].second; 
  
            pair<int,int> ans = query(1, 1, s.size(), e, f);
            
            cout << (ans.first/2)*(ans.second/2) << "\n";
        }
    }
    return 0;
}

