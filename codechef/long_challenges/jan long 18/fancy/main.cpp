#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string s1;
    getline(cin,s1);
    for(int i=0;i<t;i++)
    {
        string s;
        getline(cin,s);
        int co=0;
        if(s.length()<3)
        {
            cout << "regularly fancy" << endl;
            co=3;
            goto end;
        }
        if(s.length()==3)
        {

            if(s[0]=='n' && s[1]=='o' && s[2]=='t')
            {
                co=1;
                goto end;
            }
            else{
                goto end;
            }
        }
        for(int j=0;j<s.length()-2;j++)
        {
            if(s[j]=='n' && s[j+1]=='o' && s[j+2]=='t')
            {
                if((j+2)==(s.length()-1) && s[j-1]==' ')
                {
                    co=1;
                    goto end;
                }
                else if(j==0 && s[j+3]==' ')
                {
                    co=1;
                    goto end;
                }
                else if(s[j-1]==' ' && s[j+3]==' ')
                {
                    co=1;
                    goto end;
                }
            }
        }
        end:
            if(co==1)
            {
                cout << "Real Fancy" << endl;
            }
            else if(co==3)
            {
                ;
            }
            else{
                cout << "regularly fancy" << endl;
            }
    }
}
