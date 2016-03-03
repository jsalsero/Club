#include <bits/stdc++.h>
using namespace std;
#define MAX 100007

struct FenTree {
    vector<int> tree;
    FenTree(int n) : tree(n + 1) {}
    
    void Actualizar(int i, int v) {
        while (i < tree.size()) {
            tree[i] += v;
            i += i & -i;
        }
    }
    
    int Query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & -i;
        }
        return sum;
    }
    
    int Rango(int i, int j) {
        return Query(j) -
               Query(i - 1);
    }
};

struct coche {
	string nombre;
	//char nombre[27] = "\0";
	int low, hig;
};

map<int,int> M;
int indice(int valor) { return distance(M.begin(), M.find(valor)); }

void debug() {
	cout << "Mapa\n";
	for (auto var : M) {
		cout << var.first << ' ' << indice(var.first) << endl;
	}
}

int main() {
	int N, Q, aux, count;
	int queries[MAX];
	char cad[27];
	coche C[MAX];	

	cin.tie(0);
	ios_base::sync_with_stdio(0);

	//cin >> N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {		
		//cin >> C[i].nombre >> C[i].low >> C[i].hig;
		scanf("%s %d %d", cad, &C[i].low, &C[i].hig);
		string aux(cad);
		C[i].nombre = aux;
		M[ C[i].low ]++;
		M[ C[i].hig + 1 ]--;
	}

	//cin >> Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		//cin >> queries[i];
		scanf("%d", &queries[i]);
		M[queries[i]] += 0;
	}

	//debug();

	FenTree varo = FenTree(M.size());		
	
	for (auto var : M) {
		varo.Actualizar(indice(var.first) + 1, var.second);		
	}

	FenTree idx = FenTree(M.size());	
	for (int i = 0; i < N; i++) {
		idx.Actualizar( indice(C[i].low) + 1, i + 1);
		idx.Actualizar( indice(C[i].hig + 1) + 1, -(i + 1));
	}

	for (int i = 0; i < Q; i++) {
		aux = varo.Query( indice(queries[i]) + 1);
		if (aux == 0)
			printf("NONE\n");
			//cout << "NONE\n";
		else if (aux > 1)
			printf("MULTIPLE\n");
			//cout << "MULTIPLE\n";
		else {
			printf("%s\n", C[idx.Query(indice(queries[i]) + 1) - 1].nombre.c_str());
			//cout << C[idx.Query(indice(queries[i]) + 1) - 1].nombre << "\n";
		}
	}
	return 0;
}
/*
4
SPARK 10000 45000
CIVIC 12000 44000
CAMARO 30000 75900
MUSTANG 7000 37000
4
60000
10000
7500
5000

*/
