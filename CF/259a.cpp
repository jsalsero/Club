#include <bits/stdc++.h>
using namespace std;

int main() {
	bool ans = true;
	for (int i = 0; i < 8; ++i) {
		char last, act;
		bool valid = true;

		cin >> last;
		for (int i = 0; i < 7; ++i, last = act)
			cin >> act, valid &= (last != act);

		ans &= valid;
	}
	cout << (ans? "YES": "NO");
	return 0;
}
