#include <bits/stdc++.h>
using namespace std;

int main() {
	int casos, n, aux, res[12];

	scanf("%d", &casos);
	while(casos--) {
		scanf("%d", &n);
		fill(res, res+10, 0);
		for(int i = 1; i <= n; ++i) {
			aux = i;
			while(aux) {
				res[aux%10]++;
				aux /=10;
			}
		}
		for (int i = 0; i < 9; i++)
			printf("%d ", res[i]);
		printf("%d\n", res[9]);
	}
	return 0;
}


/*
1 2 3 4 5 6 7 8 9 
10 11 12 13 14 15 16 17 18 19 
20 21 22                   29
30

*/
