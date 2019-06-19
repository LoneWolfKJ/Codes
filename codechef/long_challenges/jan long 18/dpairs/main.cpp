#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,m;
    cin >> n >> m;
    long long int a[n],b[m];
    unordered_map<long long int, long long int> hm,bm,sm;
    for(long long int i=0;i<n;i++)
    {
        cin >> a[i];
        hm[a[i]]=i;
    }
    for(long long int i=0;i<m;i++)
    {
        cin >> b[i];
        bm[b[i]]=i;
    }
    sort(a,a+n);
    sort(b,b+m);
    long long int i,j,counter=0,lc=0;
    while(counter<n+m-1){
        if(lc%2==0)
    {
        for(i=(lc/2);i<n;i++)
        {
            for(j=i;j<m;j++){
            if(sm[(a[i]+b[j])] ==0)
            {
            cout << hm[a[i]] << " " << bm[b[j]] << endl;
            counter++;
            sm[(a[i]+b[j])]=1;
            if(counter==(n+m-1))
            {
                goto end;
            }
            }
            }
            break;
    }
    }
    else{
        for(i=(n-(lc+1)/2);i>=0;i--)
        {
            for(j=m-1;j>=0;j--)
            {
                if(sm[(a[i]+b[j])] ==0)
            {
            cout << hm[a[i]] << " " << bm[b[j]] << endl;
            counter++;
            sm[(a[i]+b[j])]=1;
            if(counter==(n+m-1))
            {
                goto end;
            }
            }
            }
            break;
        }
    }
    lc++;
    }
    end:
        ;
}
