#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, tam;
	bool light[107], flag;
	vector<int> V;

	while (1) {
		V.clear();
		cin >> n;
		if(n == 0) {
			cin >> n >> n;
			return 0;
		}
		V.push_back(n);
		while(cin >> n && n != 0) {
			V.push_back(n);
		}		

		fill(light, light + 107, true);
		tam = V.size();

		for(int i = 1; i < 18001; ++i) {

			for(int j = 0; j < tam; ++j) {
				if(i%(V[j] - 5) == 0 && i>=(V[j] - 5) )
					light[j] = !light[j];
			}

			flag = true;
			for(int j = 0; j < tam && flag; ++j) {
				if(!light[j] || i<V[j])
					flag = false;
			}

			if(flag) {				
				cout << i/18000 << ':' << i/3600 << ':' << i << "\n";
				break;
			}
		}
		if(!flag)
			cout << "Signals fail to synchronise in 5 hours\n";
	}
	return 0;
}
