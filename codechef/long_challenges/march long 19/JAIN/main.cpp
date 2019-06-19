#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[33]={0};
        for(int i=0;i<n;i++)
        {
            int flaga=0,flage=0,flagi=0,flago=0,flagu=0;
            string s;
            cin >> s;
            for(int j=0;j<s.length();j++)
            {
                if(s[j]=='a')
                    flaga = 1;
                else if(s[j]=='e')
                    flage=1;
                else if(s[j]=='i')
                    flagi=1;
                else if(s[j]=='o')
                    flago=1;
                else if(s[j]=='u')
                    flagu=1;

                if(flaga==1 && flage==1 &&  flagi==1 && flago==1 && flagu==1)
                    break;
            }
            int number;
            number = flaga + 2*flage + 4*flagi + 8*flago + 16*flagu;
            //cout << number << " number " << "\n";
            a[number]++;
        }
        long long int ans=0;
        for(int i=0;i<=32;i++)
        {
            for(int j=0;j<=32;j++)
            {
                if(((i|j) == 31) && ((a[i]*a[j])!=0 && i!=j)){
                    ans+= (a[i]*a[j]);
                    //cout << a[i] << " " << a[j] << "ai aj\n";
                    //cout << i << " " << j << "i j\n";
                }
            }
        }
        cout << ans/2 << "\n";

    }
}
