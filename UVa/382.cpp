#include <bits/stdc++.h>
using namespace std;
#define ll long long

bitset<10000010> bs;
vector<int> primos;

void criba(ll n) {
	bs.set();
	bs[0] = bs[1] = 0;
	n++;
	for (ll i = 2; i <= n; i++) 
		if(bs[i]){
			for (ll j = i*i; j <= n; j += i) 
				bs[j] = 0;
			primos.push_back((int)i);
		}	
}

int suma_factores(int n) {
	int suma = 0;
	int tam = n/2;
	for (int i = 1; i <= tam; i++) {
		if(n%i == 0)
			suma += i;
	}
	return suma;
}

int main() {
	int n, aux;

	

	printf("PERFECTION OUTPUT\n");
	while(1) {
		scanf("%d", &n);
		if(n == 0)
			break;

		printf("%5d  ", n);
		aux = suma_factores(n);
		
		if(aux == n)
			printf("PERFECT\n");
		else if(aux > n)
			printf("ABUNDANT\n");
		else if(aux < n)
			printf("DEFICIENT\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
