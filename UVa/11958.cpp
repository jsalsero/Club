#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
	int casos, buses, H, M, inicio, aux, tiempo, res;

	scanf("%d", &casos);
	for (int i = 1; i <= casos; ++i) {
		res = INF;
		scanf("%d %d:%d", &buses, &H, &M);
		inicio = H*60 + M;
		for (int j = 0; j < buses; j++) {
			scanf("%d:%d %d", &H, &M, &tiempo);			
			aux = H*60 + M;
			aux -= inicio;
			if (aux < inicio)   // el dia siguiente
				aux += 24*60;				
			aux += tiempo;
			res = min(res, aux);
		}
		cout << "Case " << i << ": " << res << "\n";
	}
	return 0;
}
/*
2
1 18:00
19:30 30
2 18:00
19:00 100
20:00 30

1
3 18:00
17:00 1
20:00 2
06:00 2

*/