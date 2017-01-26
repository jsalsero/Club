#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

int main() {
	int n;
	string direc;

	cin >> n >> direc;
	vector<Long> data(n + 7);
	for (int i = 0; i < n; ++i)
		cin >> data[i];

	vector<bool> visited(n + 7, false);
	Long idx = 0;
	bool infinite = true;
	while (!visited[idx] && infinite) {
		visited[idx] = true;
		if (direc[idx] == '>')
			if (idx + data[idx] >= n)
				infinite = false;
			else
				idx += data[idx];
		else
			if (idx - data[idx] < 0)
				infinite = false;
			else
				idx -= data[idx];
	}
	cout << (infinite? "INFINITE": "FINITE");	

	return 0;
}