#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, A[10007];

	while (cin >> N && N != 0) {
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}

		int actual = A[0];
		int res = A[0];
		for (int i = 1; i < N; ++i) {
			actual = max(A[i], actual + A[i]);
			res = max(res, actual);
		}
		if (res <= 0)
			cout << "Losing streak.\n";
		else
			cout << "The maximum winning streak is " << res << ".\n";
	}
	return 0;
}