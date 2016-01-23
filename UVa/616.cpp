#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, maxi, aux;
	bool flag;

	cin.tie(0);
	ios_base::sync_with_stdio(0);

	while(1) {
		cin >> n;
		if(n < 0)
			return 0;
		maxi = -1;		
		for(int i = sqrt(n) + 1; i >= 2; i--) {
			if((n - 1)%i != 0)
				continue;
			aux = n - 1;
			flag = false;
			for (int j = 0; j < i; ++j) { // Iteraciones para cada persona
				if(aux%i == 0) {
					aux -= aux/i;
					if(j + 1 != i)
						aux--;
					flag = true;
				}
				else{
					flag = false;
					break;
				}
			}
			if(!flag)
				continue;

			if(aux%i == 0) {
				maxi = i;
				break;
			}
		}
		if(maxi != -1)
			cout << n << " coconuts, " << maxi << " people and 1 monkey\n";
			//printf("%d coconuts, %d persons and 1 monkey\n", n, maxi);
		else
			cout << n << " coconuts, " << "no solution\n";
			//printf("%d coconuts, no solution\n", n);
	}
	return 0;
}
