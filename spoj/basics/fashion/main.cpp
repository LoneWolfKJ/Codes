#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n],b[n];
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin >> b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        for(int i=0;i<n;i++)
        {
            sum = sum +a[i]*b[i];
        }
        cout << sum << endl;
    }
}
