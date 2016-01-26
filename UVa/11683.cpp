#include <bits/stdc++.h>
using namespace std;

int main() {
	int altura, C, alturas[10007], res, temp;

	while (cin >> altura >> C && altura != 0 && C != 0) {
		for (int i = 0; i < C; ++i)
			cin >> alturas[i];

		res = 0;
		res += altura - alturas[0];
		for (int i = 1; i < C; ++i) { 
			temp = alturas[i - 1] - alturas[i];
			if (temp > 0)
				res += temp;
		}

		cout << res << "\n";
	}
	return 0;
}
/*
5 8
1 2 3 2 0 3 4 5
3 3
1 0 2
4 3
4 4 1
0

*/
