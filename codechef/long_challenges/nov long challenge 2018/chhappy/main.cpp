#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long int n,k=0;
        unordered_map<long int, long int> hm;
        unordered_map<long int, long int> kj;
        cin >> n;
        long int a[n];
        for(k=0;k<n;k++)
        {
            cin >> a[k];
            hm[a[k]]++;
           // cout << "loop1" << endl;
        }
        for(k=0;k<n;k++)
        {
            if(hm[a[k]])
            {
                kj[a[a[k]-1]]++;
                if(kj[a[a[k]-1]]>=2)
            {
              // cout << "loop 3 inner" << endl;
                cout << "Truly Happy" << endl;
                goto hola;
            }
                hm[a[k]]=0;
            }
        }

        cout << "Poor Chef" << endl;
        hola:
            ;
    }
}
