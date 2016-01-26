#include <bits/stdc++.h>
using namespace std;

int main() {
	int casos, m, f;
	char c;
	string cad;

	scanf("%d", &casos);
	getchar();
	for (int i = 0; i < casos; ++i) {
		m = f = 0;
		while(c = getchar()) {
			if(c == 'M')
				m++;
			else if(c == 'F')
				f++;
			else if (c == '\n') {
				(m == f && f > 1) ? printf("LOOP\n") : printf("NO LOOP\n");
				break;
			}
		}
	}
	return 0;
}
/*

4
MF MF
FM FF MF MM
MM FF
MF MF MF MF FF

*/
