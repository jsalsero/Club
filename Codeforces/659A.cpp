#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b;

	cin >> n >> a >> b;
	cout << (a + b - 1 + 1000*n) % n + 1;
	return 0;
}