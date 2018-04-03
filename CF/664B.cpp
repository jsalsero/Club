#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, cont, menos = 0, mas = 1;
	vector<char> signos(107);

	cont = 0;

	while (1) {
		char trash, oper;
		cin >> trash >> oper;
		
		if (oper == '=') break;
		if (oper == '+') mas++;
		if (oper == '-') menos++;

		signos[cont++] = oper;
	}
	cin >> n;

	if (mas - n*menos <= n && n <= mas*n - menos) {
		cout << "Possible\n";
		int acc = 0;
		for (int i = 0; i < cont; ++i) {
			int suma = 1;
			if (i > 0 && signos[i - 1] == '-')
				suma = -1;

			if (suma == 1)	mas--;
			if (suma != 1)	menos--;

			for (int j = 1; j <= n; ++j)
				if (acc + j*suma + mas - n*menos <= n && n <= acc + j*suma + n*mas - menos) {
					cout << j << ' ' << signos[i] << ' ';
					acc += j*suma;
					break;
				}
		}
		cout << abs(n - acc) <<  " = " << n;
	} else
		cout << "Impossible";

	return 0;
}
