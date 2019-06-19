#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        long long int sum1=0,sum2=0;
        sum1 = n*(n-1)/2;
        sum1 = sum1%1000007;
        cout << " a " << sum1 << "\n";
        sum2= (n%1000007 *(n+1)%1000007)%1000007;
        cout << " b " << sum2 << "\n" << (n%1000007 *(n+1)%1000007);
        cout << "\n" << n%1000007 << "  " << (n+1)%1000007;
        sum2= sum2%1000007;
        cout << (sum1+sum2)%1000007 << endl;
    }
}
