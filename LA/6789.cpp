#include <bits/stdc++.h>
using namespace std;
#define MAX 100007

int A[MAX], n;
int barrido(int dif) {
	// Barrido
	int conta = 0;
	int p1 = 0;
	int p2 = 1;
	for (; p1 <= p2 && p2 < n; p2++) {
		if (A[p2] - A[p1] <= dif) {
			conta++;
		} else {
			while (A[p2-1] - A[p1] > dif && p1 < p2) {
				conta += (p2 - 1) - p1;
				p1++;
			}
		}
	}
	return conta;
}

int main() {
	int k, i, j;
	
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> A[i];
	sort(A, A + n);
	int izq = A[1] - A[0];
	int der = A[n - 1] - A[0];
	int dif, conta, p1, p2;
	
	while (izq < der) {
		cout << izq << "  " << der << "   ";
		dif = (izq + der)/2;
		// Barrido		
		conta = 0;
		p1 = 0;
		p2 = 1;
		while (p2 < n && p1 < n && p1 < p2) {
			if (A[p2] - A[p1] > dif) {
				p2--;
				p1++;
				if (A[p2] - A[p1] <= dif) conta += p2 - p1;
			} else {
				conta++;
				p2++;
			}
		}
		cout << conta << endl;
		(conta > k) ? der = dif : izq = dif+1;
	}
	conta = 0;
	p1 = 0;
	p2 = 1;
	while (p2 < n && p1 < n && p1 < p2) {
		while (p1 < p2 && A[p2] - A[p1] > dif) {
			p1++;
		}
		if (p1 == p2) break;
		conta += p2 - p1;
		p2++;
	}
	return 0;
}
/*
5 4
1 2 4 6 15
4 6
2 8 13 120
0 0


*/