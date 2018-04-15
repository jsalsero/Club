#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, A[107][107], B[107];
	int k_res, k_actual, res, mini;
	int aux;

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> A[i][j];
	
	res = INT_MIN;

	for (int l = 0; l < N; ++l) {
		fill(B, B + N, 0);

		for (int r = l; r < N; ++r) {
			// Kadane			
			k_actual = 0;
			k_res = INT_MIN;
			for (int h = 0; h < N; h++) {
				B[h] += A[h][r];
				k_actual = max(0, k_actual + B[h]);				
				k_res = max(k_res, k_actual);
			}
			
			bool flag = false;
			aux = B[0];
			for (int h = 1; h < N && !flag; h++) {
				if (B[h] >= 0)
					flag = true;
				aux = max(aux, B[h]);
			}
			if (flag)
				res = max(res, k_res);
			else
				res = max(res, aux);
		}
	}
	cout << res << "\n";
	return 0;
}