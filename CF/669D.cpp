#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;

	cin >> n >> q;

	vector<int> normal(3*n + 7), weird(3*n + 7);
	for (int i = 0; i < 3*n; ++i)
		normal[i] = (i % n) + 1;
	
	for (int i = 0; i < 3*n; i += 2)
		weird[i] = normal[i + 1],
		weird[i + 1] = normal[i];

	/*
	for (const auto& var : normal)
		cout << var << ' ';
	cout << endl;
	for (const auto& var : weird)
		cout << var << ' ';
	*/

	bool shift = false;
	int pointer = 0;

	for (int i = 0; i < q; ++i) {
		int op;
		cin >> op;
		if (op == 1) {
			int move;
			cin >> move;
			pointer = (pointer + n - move) % n;			
		} else
			shift = !shift;
	}

	for (int i = pointer; i < pointer + n; ++i)
		cout << (shift? weird[i]: normal[i]) << ' ';

	return 0;
}