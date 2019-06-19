#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define ull unsigned long long


using namespace std;

ull cal(ull b,ull p,ull div)
{
    ull k=1,l=b;
    while(p)
    {
        if(p & 1)
        {
            k=(k*l)%div;
        }
        l=(l*l)%div;
        p=p/2;
    }
    return k;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ull res,n,div=1000000007,div2;
        int wolf;
        cin >> wolf;
        int b[wolf];
        for(int k=0;k<wolf;k++)
        {
            cin >> b[k];
        }
        n=wolf;

        ull base=2,power=0;
        div2=div-1;
        for(ull i=0; i<n; i++)
        {
            power=(n-1)%div2;
        }
        if(power==0)
            cout<<1<<endl;
        else
        {
            res=cal(base,power,div);
            cout<<res<<endl;
        }


    }

    return 0;
}
