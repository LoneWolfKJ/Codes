#include <iostream>

using namespace std;
// power function is taken from geekforgeeks to calculate power in log(n) time
// used oeis to find Jacobsthal sequence (or Jacobsthal numbers): a(n) = a(n-1) + 2*a(n-2), with a(0) = 0, a(1) = 1.

long long int num(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    else{
        return num(n-1) + 2*num(n-2);
    }
}
long long int power(int x, int y)
{
    long long int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << num(n) << " " << power(2,n) << " ";
    }
}
