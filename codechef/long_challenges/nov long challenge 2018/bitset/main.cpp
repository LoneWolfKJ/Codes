#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// max length function is from geekforgeeks
int maxlength(bool arr[], int n)
{
    int count = 0;
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count = 0;
        else
        {
            count++;
            result = max(result, count);
        }
    }

    return result;
}

int main()
{
    unordered_map<int,int> hm;
    int n,q,k;
    string query;
    cin >> n >> q >> k;
    bool s[n];
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
    }
    cin >> query;
    for(int i=0;i<q;i++)
    {
        if(query[i]=='?')
        {
            hm[i] = maxlength(s,n);
            if(hm[i]>=k)
            {
                cout << k << endl;
                goto hola;
            }
            else{
                cout << hm[i] << endl;
                goto hola;
            }
        }
        else{
            bool lst = s[n-1];
            for(int bola=n-1;bola>0;bola--)
            {
                s[bola] = s[bola-1];
            }
            s[0] = lst;
        }
        hola:
            ;
    }
}

