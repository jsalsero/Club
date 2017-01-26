#include <bits/stdc++.h>
using namespace std;

pair<int, int> process(vector<int> &ans, int n, int m) {
	const int TAM = n + m + 2;

	bool petya = true;
	for (int i = 2; i < TAM; ++i, petya = !petya) {
		if (n > 0) {
			if (petya)
				(!ans[i - 1])? ans[i] = 0, --n: ans[i] = 1, --m;
			else
				(ans[i - 1])? ans[i] = 0, --n: ans[i] = 1, --m;
		} else
			ans[i] = 1, --m;
	}

	int same = 0, diff = 0;
	for (int i = 0; i < TAM - 1; ++i)
		(ans[i] == ans[i + 1])? same++:	diff++;
	
	return make_pair(same, diff);
}

int main() {
	int n, m;

	cin >> n >> m;
	if (n > m)
		swap(n, m);

	vector<int> ans(n + m);
	ans[0] = 0;
	ans[1] = 1;
	auto less = process(ans, n - 1, m - 1);

	ans[0] = 1;
	ans[1] = 0;
	auto more = process(ans, n - 1, m - 1);

	if (less.first > more.first)
		cout << less.first << ' ' << less.second << '\n';
	else
		cout << more.first << ' ' << more.second << '\n';
	return 0;
}
