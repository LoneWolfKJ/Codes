#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		long long int n;
		int ans;
		cin >> n;
		switch(n%6)
        {
            case 0: ans=0;break;
            case 1: ans=1;break;
            case 2: ans=4;break;
            case 3: ans=6;break;
            case 4: ans=5;break;
            case 5: ans=2;break;
        }
        cout << ans << endl;
	}
}
