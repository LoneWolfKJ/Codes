#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a,b;
        long int n;
        cin >> n;
        cin >> a >> b;
        long long int s[n];
        long int bob=0,alice=0,common=0;
        for(long int i=0;i<n;i++)
        {
            cin >> s[i];
            if(s[i]%a==0 && s[i]%b==0)
            {
                common++;
            }
            else if(s[i]%a==0)
            {
                bob++;
            }
            else if(s[i]%b==0)
            {
                alice++;
            }
        }
        bob = bob;
        alice = alice - common;
        //cout << alice << "ali" << endl;
        if(bob>alice)
        {
            cout << "BOB" << endl;
        }
        else
        {
            cout << "ALICE" << endl;
        }
        end:
            ;
    }
}
