#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &data) {
	set<int> s;
	for (const auto &var: data)
		s.insert(var);

	if (s.size() == 1)
		return vector<int>(1, data[0]);

	int miss  = 1, middle = 1 << 30;
	int ratio = data[1] - data[0];
	for (int i = 0; i < data.size() - 1 && miss >= 0; ++i) {
		if (data[i + 1] - data[i] != ratio)
			miss--, middle = data[i] + ratio;
	}

	vector<int> ans;
	if (s.size() == data.size() && miss >= 0) {
		if (miss)
			ans.push_back(data[0] - ratio);
		if (miss == 0)
			ans.push_back(middle);
		if (miss)
			ans.push_back(data.back() + ratio);
	}

	miss = 1, ratio = 1, middle = 1 << 30;
	for (int i = 0; i < data.size() - 1 && miss >= 0; ++i) {
		if (data[i + 1] - data[i] != ratio)
			miss--, middle = data[i] + ratio;
	}

	if (s.size() == data.size() && miss >= 0) {
		if (miss == 0 && middle + 1 == )
			ans.push_back(middle);
	}

	sort(ans.begin(), ans.end());

	return ans;
}

int main() {
	int n;

	cin >> n;
	vector<int> data(n);
	for (int i = 0; i < n; ++i)
		cin >> data[i];
	sort(data.begin(), data.end());

	if (n == 1)
		cout << -1 << endl;
		else {
		auto ans = solve(data);
		cout << ans.size() << endl;
		for (const auto &var : ans)
			cout << var << ' ';
	}


	return 0;
}
