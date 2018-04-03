#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long Long;

int main() {
	Long n, m;
	map<Long, Long> bucket;

	cin >> n;
	for (Long i = 0; i < n; ++i) {
		Long like;
		cin >> like;
		bucket[like]++;
	}

	cin >> m;
	vector< pair<Long, Long> > data(m);
	for (Long i = 0; i < m; ++i)	cin >> data[i].first;
	for (Long i = 0; i < m; ++i)	cin >> data[i].second;

	vector< pair< pair<Long, Long>, Long > > ans(m);
	for (Long i = 0; i < m; ++i)
		ans[i] = make_pair(make_pair(bucket[data[i].first], bucket[data[i].second]), i + 1);
	
	sort(ans.begin(), ans.end());

	/*
	for (const auto &var : ans)
		cout << var.second << " -> " << var.first.first << ' ' << var.first.second << endl;
	*/

	cout << ans.back().second << endl;

	return 0;
}