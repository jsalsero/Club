#include <bits/stdc++.h>
using namespace std;

#define MAX 30005
int padre[ MAX ];
int rango[ MAX ];

void make (int n) {
  for (int i = 0; i < n; i++) {
    padre[ i ] = i;
    rango[ i ] = 0;
  }
}

int find (int x) {
  if (x == padre[ x ]) {
    return x;
  }
  return padre[x] = find( padre[x] );
}

void unionRank(int x, int y) {
  int xRoot = find(x);
  int yRoot = find(y);
  if (rango[xRoot] > rango[yRoot])
    padre[yRoot] = xRoot;
  else {
    padre[xRoot] = yRoot;
    if (rango[xRoot] == rango[yRoot])
      rango[yRoot]++;
  }
}

int root[ MAX ];
int numComponentes;
int getNumberCC(int n) {
  numComponentes = 0;
  for (int i = 0; i < n; ++i) {
    if (padre[i] == i)
      root[numComponentes++] = i;
  }
  return numComponentes;
}

int numVertices[ MAX ];
void getNumberNodes(int n) {
  fill(numVertices, numVertices + MAX, 0);
  for (int i = 0; i < n; ++i) {
    numVertices[ find(i) ]++;
  }
}

int main() {
  int n, m, k, raiz, num, aux;

  while (cin >> n >> m) {
    if (m == 0 && n == 0)
      return 0;
    make(n);
    for (int j = 0; j < m; ++j) {
      cin >> k;
      cin >> raiz;
      for (int i = 1; i < k; ++i) {
        cin >> num;
        unionRank(raiz, num);
      }
    }
    if (k != 0) {
      raiz = find(0);
      aux = getNumberCC(n);
      getNumberNodes(n);
      cout << numVertices[raiz] << "\n";
    } else
      cout << "1\n";
  }
	return 0;
}