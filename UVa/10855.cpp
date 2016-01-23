#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, n;
	int cero, uno, dos ,tres;
	bool flag0, flag1, flag2, flag3;

	cin.tie(0);
	ios_base::sync_with_stdio(0);

	while (cin >> N >> n && N != 0 && n != 0) {
		char A[N][N];
		char B[n][n];
		cero = uno = dos = tres = 0;

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> A[i][j];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> B[i][j];

		for (int i = 0; i <= N - n; ++i) {
			for (int j = 0; j <= N - n; ++j) {
				// 0 giros
				flag0 = true;
				flag1 = true;
				flag2 = true;
				flag3 = true;
				for (int k = 0; k < n; ++k) {
					for (int h = 0; h < n; ++h) {
						if( A[i + k][j + h] != B[k][h] )          flag0 = false;
						if( A[i + k][j + h] != B[n - h - 1][k] )      flag1 = false;
						if( A[i + k][j + h] != B[n - k - 1][n - h - 1] )  flag2 = false;
						if( A[i + k][j + h] != B[h][n- k - 1] )      flag3 = false;
					}
				}
				if(flag0) cero++;
				if(flag1) uno++;
				if(flag2) dos++;
				if(flag3) tres++;
			}
		}
		cout << cero << ' ' << uno << ' ' << dos << ' ' << tres << "\n";
	}
	return 0;
}
