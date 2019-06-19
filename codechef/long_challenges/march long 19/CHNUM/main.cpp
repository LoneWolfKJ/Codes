#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        long int a[n]={0};
        int pos=0,neg=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if(a[i]>0)
                pos++;
            if(a[i]<0)
                neg++;
        }
        if(neg==0)
            cout << pos << " " << pos << "\n";
        else if(pos==0)
            cout << neg << " " << neg << "\n";
        else{
            if(pos>=neg)
                cout << pos << " " << neg << "\n";
            else
                cout << neg << " " << pos << "\n";
        }
    }
}
