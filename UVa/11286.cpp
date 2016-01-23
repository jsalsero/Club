#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, num, maxi;
	map< map<int, int> , int> M;
	map<int,int> aux;

	while (cin >> n && n != 0) {
		M.clear();
		for (int i = 0; i < n; ++i) {
			aux.clear();
			for (int j = 0; j < 5; ++j) {
				cin >> num;
				aux[num]++;	
			}			
			M[aux]++;
		}
		maxi = 0;
		for (auto var : M) 
			maxi = max(maxi, var.second);
		if (maxi == 1)
			cout << n << "\n";
		else
			cout << maxi << "\n";
	}
	return 0;
}
