#include <iostream>
#include<bits/stdc++.h>

using namespace std;

long int calc(long int n)
{
	int rem, i = 0;
	long int res = 0;
	int arr[105];

	while (n) {
		rem = n % 2;
		n /= 2;
		arr[i] = rem;
		i++;
	}

	int k = 0;
	while (i--) {
		res += arr[i] * (1 << k);
		k++;
	}

	return res;
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--) {
		long int n;
		scanf("%ld", &n);

		if (n & 1) {
			printf("%ld\n", n);
		} else {
			printf("%ld\n", calc(n));
		}
	}
 	return 0;
}
