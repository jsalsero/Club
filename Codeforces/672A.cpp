#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	string ans = "";
	for (int i = 1; i < 1007; ++i)
		ans += to_string(i);

	int n;
	cin >> n;
	cout << ans[n - 1] << endl;
	return 0;
}