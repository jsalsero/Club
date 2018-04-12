#include <bits/stdc++.h>
using namespace std;
#define lli long long int

// Exponenciacion binaria a^n mod m
lli Exponenciar(lli a, lli n, lli m) {
    lli res = 1, p = a;
    for (; n; n >>= 1) {
        if (n & 1) 
            res = (res * p) % m;
        p = (p * p) % m;
    }
    return res;
}

int main(){
	lli t, base, expo, modu;
	cin >> t;
	while(t--){
		cin >> base >> expo >> modu;
		cout << Exponenciar(base, expo, modu) << "\n";
	}
	cin >> t;
	return 0;
}