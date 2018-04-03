#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	set<int> s;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		s.insert(num);
	}

	vector<int> ans;
	for (int i = 1; i <= 1e9 && m >= i; ++i)
		if (s.find(i) == s.end())
			ans.push_back(i), m-= i;

	cout << ans.size() << endl;
	for (const auto& var : ans)
		cout << var << ' ';
	return 0;
}