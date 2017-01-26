#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	int n;

	cin >> n;
	vector< pair<int, int> > data(n);
	for (int i = 0; i < n; ++i)
		cin >> data[i].first >> data[i].second;

    int pass = 0;
    int ans  = 0;
    for (int i = 0; i < n; ++i) {
        pass += data[i].second - data[i].first;
        ans = max(ans, pass);
    }

    cout << ans << endl;

	return 0;
}