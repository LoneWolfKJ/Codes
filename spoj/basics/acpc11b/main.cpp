#include<bits/stdc++.h>

using namespace std;

int main() {
	int C;
	scanf("%d",&C);
	while(C--)
	{
		int n1;
		scanf("%d",&n1);
		int a[n1];
		for(int i = 0 ; i < n1 ; i++)
			scanf("%d",&a[i]);
		int n2;
		scanf("%d",&n2);
		int b[n2];
		for(int i = 0 ; i < n2 ; i++)
			scanf("%d",&b[i]);
		sort(a,a+n1);
		sort(b,b+n2);
		int min1 = 1000000;
		for(int i = 0 ; i < n1 ; i++)
			for(int j = 0 ; j < n2 ; j++)
			{
				if(min1 > abs(a[i]-b[j])) min1 = abs(a[i]-b[j]);
			}
		printf("%d\n",min1);
	}
	return 0;
}
