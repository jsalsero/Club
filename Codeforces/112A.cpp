#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;

	cin >> a >> b;
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	transform(b.begin(), b.end(), b.begin(), ::tolower);

	if (a < b)	cout << -1;
	if (a > b)	cout <<  1;
	if (a == b)	cout <<  0;

	return 0;
}