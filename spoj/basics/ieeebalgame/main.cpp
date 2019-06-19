#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        double k;
        k= (double)n/(n+1);
        cout << fixed << setprecision(8) << k << endl;
    }
}
