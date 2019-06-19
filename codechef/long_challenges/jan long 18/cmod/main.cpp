#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while(t--)
    {
        long long int n,p;
        cin >> n >> p;
        long long int m,mid;
        if(n%2==0)
        {
            m = n - ((n+2)/2);
            mid = (n+2)/2;
        }
        else
        {
            m = n - ((n+1)/2);
            mid= (n+1)/2;
        }
        unsigned long long int ways;
        if(n>2)
        {
            ways = (p-n)*(p-n) + (p-n)*(p-m) + (p-m)*(p-m);
            cout << ways << endl;
        }
        else{
            ways = p*p*p;
            cout << ways << endl;
        }
    }
}
