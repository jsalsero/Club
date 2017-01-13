#include <bits/stdc++.h>
using namesapce std;

int n, cont;
vector<int> ans(107);
vector<int> signos(107);

bool dp(int idx, )

int main() {
	signos[0] = 1;
	cont = 1;

	while (1) {
		char trash, oper;
		cin >> trash >> oper;
		if (oper == '=')
			break;
		signos[cont++] = (oper == '+'? 1: -1);
	}
	cin >> n;

	if (dp(0, )) {
		cout << "Possible\n";
		for (int i = 0; i < cont; ++i)
			cout << ans[i] << " " << (signos[i + 1] == 1? "+ ": "- ");
		cout << "= " << n;
	} else
		cout << "Impossible";

	return 0;
}