#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int t,i,input,zeroes,c;
    cin>>t;
    for(i=0;i<t;i++)
    {
        zeroes=0;
        cin>>input;
        c=5;
        while((input/c)>0)
        {
            zeroes=zeroes+(input/c);
            c=c*5;
        }
        cout<<zeroes<<endl;
    }

}
