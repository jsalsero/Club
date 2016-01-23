#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ll n,k;
	while(scanf("%lld %lld", &n, &k) == 2) {		
		printf("%lld\n", n + (n - 1)/(k - 1));
	}
	return 0;
}
