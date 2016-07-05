#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000002;
int v[MAX], memo[MAX], r[MAX], pila[MAX];

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, res, tope = 1;
	int i, j, k, g, h;
	bool cicle;
	
	cin >> n;
	for (i = 1; i <= n; i++) 
		cin >> v[i];
	for (i = 1; i <= n; i++) {
		if (memo[i]) continue;

		for (j = i; !memo[j];) {
			memo[j] = i;
			pila[tope++] = j;
			j = v[j];
		}
		if (memo[j] == i) {
			k = 1;
			for (g = tope - 1; g >= 1; g--, k++)
				if (pila[g] == j) break;
			
			cicle = true;
			while (tope >= 1) {
				tope--;
				if (cicle) r[pila[tope]] = k;
				else r[ pila[tope] ] = r[ v[ pila[tope] ] ] + 1;
				if (pila[tope] == j) cicle = false;
			}
		}
		else {
			while(tope >= 1){
				tope--;
				r[pila[tope]] = r[v[pila[tope]]] + 1;
			}
		}
		
	}
	cout << *max_element(r, r + n) << "\n";	
}
