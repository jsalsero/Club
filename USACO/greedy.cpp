#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
	while( cin >> n >> k, n != 0 && k != 0) {
		for(int i = 0; i<n ; i++) {
			cin >> size >> price;
			V.push_back( make_pair(size, price) );
		}
	}
	return 0;
}