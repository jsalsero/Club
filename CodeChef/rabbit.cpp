#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define vi vector<lli>
#define MOD 1000000007 

vector<vi> multiplicacion(const vector<vi> m1, const vector<vi> m2) {
	vector <vi> res;

	lli fila = m1.size();
	lli filb = m2.size();
	lli colb = m2[0].size();

	lli sum=0;
	for(lli i=0; i<fila; i++) {
		vector<lli> aux;
		for(lli j=0; j<colb; j++) {
			for(lli k=0; k<filb; k++) {
				sum += m1[i][k] * m2[k][j];
			}
			aux.push_back(sum%MOD);
			sum=0;
		}
		res.push_back(aux);
	}
	return res;
}

vector<vi> ExponenciarMatriz(vector<vi> m1, lli n) {
	vector <vi> res;
	vector <vi> p = (m1);
	
	// matriz identidad
	lli tam = m1.size();
	for(lli i = 0; i < tam; i++) {
		vector<lli> aux;
		for(lli j = 0; j < tam; j++) {
			if (j == i)
				aux.push_back(1);
			else
				aux.push_back(0);
		}
		res.push_back(aux);
	}

	for(; n; n >>= 1) {
		if (n & 1)
			res = multiplicacion(res, p);
		p = multiplicacion(p, p);
	}

	return res;	
}

int main() {
	lli casos, saltos, num, maxi, N;
	lli cubeta[17];

	cin >> casos;
	for(lli h=0; h<casos; h++) {
		vector<vi> matriz;
		fill(cubeta, cubeta + 15, 0);

		cin >> N;
		cin >> saltos;
		cin >> maxi;
		cubeta[maxi]++;

		for(lli i=1; i<saltos; i++) {
			cin >> num;
			maxi = max(maxi, num);
			cubeta[num]++;
		}
	
		vector<lli> v_rec;
		for(lli i = 1; i<=maxi; i++) {
			if(cubeta[i])
				v_rec.push_back(1);
			else
				v_rec.push_back(0);
		}

		matriz.push_back(v_rec);
		for(lli i = 0; (i + 1) < maxi; i++) {
			vector<lli> aux;
			for(lli j = 0; j < maxi; j++) {
				if (j == i)
					aux.push_back(1);
				else
					aux.push_back(0);
			}
			matriz.push_back(aux);
		}				
		matriz = ExponenciarMatriz(matriz, N);
		cout << matriz[0][0] << endl;	
	}
	return 0;
}
/*
3
10
1 1
13
3 1 2 8
15
5 1 2 3 4 5
*/
