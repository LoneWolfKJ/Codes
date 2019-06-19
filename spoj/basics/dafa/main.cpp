#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
       string s;
       cin >> s;
       unordered_map<int,int>hm;
       int k=0;
       for(int i=0;i<s.length();i++)
       {
           if(s[i]=='p')
           {
               hm[k]= i-k;
               if(k-1>0)
               {
                   hm[k]= hm[k] + hm[k-1];
               }
               k++;
           }
       }
       cout << "moves" << hm[k-1];
       if(k%2==0 && hm[k-1]%2==1)
       {
           cout<<"YES"<<endl;
        }
        else
        {
            cout <<"NO" << endl;
        }

    }
}
