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
};

struct coche {
	string nombre;
	int low, hig;
};

#define mapeo(n) distance(V.begin(), lower_bound(V.begin(), V.end(), n))

/*
void debug() {
	cout << "veamos las pos Q\n";
	for (auto q : queries) {
		cout << (mapeo(q)) << endl;
		//varo.Actualizar(mapeo(q), varo.Query(mapeo(q)));
	}

	for (auto t : varo.tree) {
		cout << t << ' ';
	}
	cout << endl;
	for (auto v : V) {
		cout << v << ' ';
	}
	cout << endl;
}
*/

int main() {
	string cad;
	int N, Q, aux, count;
	int low, hig;
	vector<int> queries;	
	vector<coche> C;
	vector<int> V;
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {		
		cin >> cad >> low >> hig;
		C.push_back({cad, low, hig + 1});
		V.push_back(low);
		V.push_back(hig + 1);
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> aux;
		queries.push_back(aux);
		V.push_back(aux);
	}

	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());

	FenTree varo = FenTree(V.size());	
	for (auto var : C) {
		varo.Actualizar(mapeo(var.low) + 1, 1);
		varo.Actualizar(mapeo(var.hig) + 1, -1);
	}
	
	FenTree idx = FenTree(V.size());
	count = 1;
	for (auto var: C) {
		idx.Actualizar(mapeo(var.low) + 1, count);
		idx.Actualizar(mapeo(var.hig) + 1, -count);
		count++;
	}

	for (auto q : queries) {
		aux = varo.Query(mapeo(q) + 1);
		if (aux == 0)
			cout << "NONE\n";
		else if (aux > 1)
			cout << "MULTIPLE\n";
		else {
			cout << C[idx.Query(mapeo(q) + 1) - 1].nombre << "\n";
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
