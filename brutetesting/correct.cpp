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

#define mod 1000000007
#define pie 3.14
typedef long long int ll;
vector<ll>adj[1000005];
bool check[1000005]={0};
vector<ll>s;
ll tree[1000005];
ll sub[1000005];//for storing number of nodes in subtree
void update(ll node,ll st,ll e,ll id,ll val)
{
    if(st==e)
        tree[node]=val;
    else
    {
        ll m=(st+e)/2;
        if(st<=id && id<=m)
            update(2*node,st,m,id,val);
        else
        {
            update(2*node+1,m+1,e,id,val);
        }
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
//Will get number of odd numbers in subtree in logn time
ll query(ll node,ll st,ll e,ll l,ll r)
{
    if(r<st || l>e)
        return 0;
    if(l<=st && e<=r)
        return tree[node];
    ll m=(st+e)/2;
    return query(2*node,st,m,l,r)+query(2*node+1,m+1,e,l,r);
}
ll dfs(ll n)
{
    ll i;
    //cout<<n<<endl;
    sub[n]++;
    s.push_back(n);
    check[n]=true;
        for(i=0;i<adj[n].size();i++)
        {
            if(check[adj[n][i]]==false)
            {
                dfs(adj[n][i]);
                s.push_back(adj[n][i]);
                sub[n]=sub[n]+sub[adj[n][i]];
            }
        }
        return 0;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

ll n,q,i;
ll arr[1000005];
cin>>n>>q;
for(i=1;i<=n;i++)
cin>>arr[i];
for(i=0;i<(n-1);i++)
{
    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
dfs(1);
s.push_back(1);
// for(i=0;i<s.size();i++)
// cout<<s[i]<<"\n";
vector<pair<ll,ll>>p;
for(i=1;i<=n;i++)
{
    p.push_back({0,0});
}
//Calculating intime and outime of numbers
for(i=0;i<s.size();i++)
{
    if(p[s[i]].first==0)
        p[s[i]].first=i+1;
    else
        p[s[i]].second=i+1;
}
// for(i=1;i<=n;i++)
// {
// cout<<i<<" "<<p[i].first<<" "<<p[i].second<<"\n";````````````````
// }
//cout<<sub[2]<<"\n";
for(i=1;i<=n;i++)
{
    ll a,b;
    a=p[i].first;
    b=p[i].second;
    if(arr[i]%2==1)
    {
        update(1,1,s.size(),a,1);
        update(1,1,s.size(),b,1);
    }
}
while(q--)
{
    ll ch,a,b,k,k1,ans;
    cin>>ch;
    if(ch==1)
    {
        cin>>a>>b;
        if(b%2==1)
        {
            update(1,1,s.size(),p[a].first,1);
            update(1,1,s.size(),p[a].second,1);
        }
        else
        {
            update(1,1,s.size(),p[a].first,0);
            update(1,1,s.size(),p[a].second,0);
        }
    }
    else if(ch==2)
    {
        cin>>a;
        k=query(1,1,s.size(),p[a].first,p[a].second)/2;
        k1=sub[a]-k;
        ans=k*k1;
        cout<<ans<<"\n";
    }
}

}
